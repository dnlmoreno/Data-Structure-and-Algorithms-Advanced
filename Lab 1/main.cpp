#include <iostream>
#include <math.h> // pow
#include <fstream>
#include <vector>
#include <iterator>
#include <chrono>

using namespace std;

/***********************************************************/
/*******    EXPERIMENTACIÓN SENCILLA DE BÚSQUEDAS    *******/
/***********************************************************/

bool busquedaLineal(const vector<int> &vector, int elem);
bool busquedaBinaria(const vector<int> &vector, int elem);
bool busquedaDoblada(const vector<int> &vector, int elem);

void expBusqueda(int replicas, const vector<int> &vector, int elem, int n, ofstream &file);
void expBusqueda_v1(int replicas, const vector<int> &vector, int elem, int n, ofstream &file);

// Para medir el tiempo
auto start = chrono::high_resolution_clock::now();
auto finish = chrono::high_resolution_clock::now();

int main(int argc, char* argv[]){
    // Variables de la etapa tamanio
    int replicas = 100000, elem, elem_v1, n, n_v1;
    int puntos[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int puntos_v1[] = {1000000, 10000000, 20000000, 30000000, 40000000, 50000000, 60000000, 70000000, 80000000, 90000000};
    int cant_puntos = sizeof puntos/sizeof puntos[0];

    // Tamanio y vector utilizado en la etapa de posicion
    int tam_two_stage = puntos[cant_puntos-1];
    int tam_two_stage_v1 = puntos_v1[cant_puntos-1];
    vector<int> elem_vector(tam_two_stage); 
    vector<int> elem_vector_v1(tam_two_stage_v1); 

    /*******************************************/
    /*******    VARIACION DE TAMANIOS    *******/
    /*******************************************/

    // Se guarda en archivo csv
	ofstream file, file_v1;
	file.open("Resultados/Tamaños_medianos_datos/Experimentacion_busquedas_tamanios.csv", ios::out);
    file << "Tamaños" << ";" << "Tiempo_búsqueda_lineal" << ";" << "Tiempo_búsqueda_binaria" << ";" << "Tiempo_búsqueda_doblada" << endl;

	file_v1.open("Resultados/Tamaños_grandes_datos/Experimentacion_busquedas_tamanios.csv", ios::out);
    file_v1 << "Tamaños" << ";" << "Tiempo_búsqueda_binaria" << ";" << "Tiempo_búsqueda_doblada" << endl;

    cout << "EVALUACION EXPERIMENTAL DE DIFERENTES TAMANIOS" << endl; 

    // Tamanios diferentes de los datos de entrada
    for(int i=0; i<cant_puntos; i++){
        n = puntos[i];
        n_v1 = puntos_v1[i];
        vector<int> vector_v0(n);
        vector<int> vector_v1(n_v1);

        // Se rellena el vector ordenado
        for(int j=0; j<vector_v0.size(); j++){
            vector_v0[j] = j;
        }
        for(int j=0; j<vector_v1.size(); j++){
            vector_v1[j] = j;
        }

        // Se toma el ultimo elemento del vector como elemento buscado
        elem = n - 1;
        elem_v1 = n_v1 - 1;

        cout << "-- Cantidad de puntos evaluados: " << i+1 << " de " << cant_puntos << " -- " << endl; 

        // Busqueda del elemento, junto con su tiempo
        expBusqueda(replicas, vector_v0, elem, n, file);
        expBusqueda_v1(replicas, vector_v1, elem_v1, n_v1, file_v1);

        // Se guarda el vector con tamanio "tam_two_stage" para utilizarlo en la etapa siguiente
        if(puntos[i] == tam_two_stage) copy(vector_v0.begin(), vector_v0.end(), elem_vector.begin());
        if(puntos_v1[i] == tam_two_stage_v1) copy(vector_v1.begin(), vector_v1.end(), elem_vector_v1.begin());
    }

    file.close();
    file_v1.close();

    /***************************************************************/
    /*******    VARIACION DE POSICION DEL ELEMENTO BUSCADO   *******/
    /***************************************************************/

    // Valor que variara la posicion del elemento buscado
    int valor = tam_two_stage/cant_puntos - 1;
    int valor_v1 = tam_two_stage_v1/cant_puntos - 1;

    // Se guarda la posicion y el elemento
    vector<int> pos(cant_puntos);
    vector<int> elem_pos(cant_puntos);
    vector<int> pos_v1(cant_puntos);
    vector<int> elem_pos_v1(cant_puntos);

    int aux = 0, aux_v1 = 0;
    for(int i=0; i<cant_puntos; i++){
        if(i=0){
            pos[i] = valor + aux - 8;
            elem_pos[i] = elem_vector[valor + aux - 8];
        } 
        else{
            pos[i] = valor + aux;
            elem_pos[i] = elem_vector[valor + aux];
        }
        aux = elem_pos[i];


        if(i=0){
            pos_v1[i] = valor_v1 + aux_v1 - 800000;
            elem_pos_v1[i] = elem_vector_v1[valor_v1 + aux_v1 - 800000];
        } 
        else{
            pos_v1[i] = valor_v1 + aux_v1;
            elem_pos_v1[i] = elem_vector_v1[valor_v1 + aux_v1];
        }
        aux_v1 = elem_pos_v1[i];
        
    }

    // Se guarda en archivo csv
	file.open("Resultados/Tamaños_medianos_datos/Experimentacion_busquedas_posicion.csv", ios::out);
    file << "Posición" << ";" << "Tiempo_búsqueda_lineal" << ";" << "Tiempo_búsqueda_binaria" << ";" << "Tiempo_búsqueda_doblada" << endl;

	file_v1.open("Resultados/Tamaños_grandes_datos/Experimentacion_busquedas_posicion.csv", ios::out);
    file_v1 << "Posición" << ";" << "Tiempo_búsqueda_binaria" << ";" << "Tiempo_búsqueda_doblada" << endl;

    cout << "\nEVALUACION EXPERIMENTAL CON DIFERENTES POSICIONES (TAMANIO = " << tam_two_stage << ") y (TAMANIO = " << tam_two_stage_v1 << ")" << endl; 
    
    for(int i=0; i<elem_pos.size(); i++){
        elem = elem_pos[i];
        elem_v1 = elem_pos_v1[i];

        cout << "-- Cantidad de puntos evaluados: " << i+1 << " de " << cant_puntos << " -- " << endl; 

        // Busqueda del elemento, junto con su tiempo
        expBusqueda(replicas, elem_vector, elem, pos[i], file);
        expBusqueda_v1(replicas, elem_vector_v1, elem_v1, pos_v1[i], file_v1);
    }

    file.close();
    file_v1.close();

    return 0;
}

bool busquedaLineal(const vector<int> &vector, int elem){
    /*** Busqueda lineal solo para un vector ordenado ***/
    int cont = 0;
    bool flag = false;

    while(flag == false & cont < vector.size()){
        if(vector[cont] == elem){ // Elemento fue encontrado
            flag = true;
        }
        cont += 1;

        if(vector[cont] > elem) break; //Elemento no se encuentra en el vector ordenado
    }

    if (flag == false) return flag; // Elemento no fue encontrado
    else return flag; // Se encontro el elemento
}

bool busquedaBinaria(const vector<int> &vector, int elem){
    /*** Busqueda binaria para un vector ordenado ***/
    int inicio = 0, med, final = vector.size();
    int cont;
    bool flag = false;

    while(true){
        med = (inicio + final)/2;

        // Cambia intervalos de busqueda
        if(vector[med] > elem) final = med;
        else if(vector[med] < elem) inicio = med;
        else return flag = true; // Elemento fue encontrado

        if(inicio + 1 == final) break; //Elemento no se encuentra en el vector ordenado
    }
    return flag;
}

bool busquedaDoblada(const vector<int> &vector, int elem){
    /*** Busqueda doblada para un vector ordenado ***/
    int inicio, med, final;
    int i=0;

    while(true){
        inicio = pow(2, i);
        final = pow(2, i+1);
    
        // Condicion de termino
        if(final > vector.size()){ 
            final = vector.size() - 1;
            if(vector[inicio] <= elem <= vector[final]) // Elemento puede estar en el intervalo final del vector
                return busquedaBinaria(vector, elem);
            else return false; // Elemento no fue encontrado
        }

        if(vector[inicio] <= elem <= vector[final]) // Elemento puede estar en este intevarlo
            return busquedaBinaria(vector, elem);
        else i++;
    }
}

void expBusqueda(int replicas, const vector<int> &vector, int elem, int n, ofstream &file){
    /** Busca el elemento ingresado mediante los algoritmos de busqueda lineal, 
        binaria y doblada y guarda el tiempo computacional en cada uno de ellos***/

    bool bl, bb, bd;

    // Variables de tiempo
    float tpo_Blineal = 0.0, tpo_Blineal_prom = 0.0;
    float tpo_Bbinaria = 0.0, tpo_Bbinaria_prom = 0.0;
    float tpo_Bdoblada = 0.0, tpo_Bdoblada_prom = 0.0;

    // Replicas por tamanio
    for(int i=0; i<replicas; i++){

        // Experimentación busqueda lineal
        start = chrono::high_resolution_clock::now();
        bl = busquedaLineal(vector,elem);
        finish = chrono::high_resolution_clock::now();
        tpo_Blineal += chrono::duration_cast<chrono::nanoseconds> (finish - start).count();

        // Experimentación busqueda binaria
        start = chrono::high_resolution_clock::now();
        bb = busquedaBinaria(vector,elem);
        finish = chrono::high_resolution_clock::now();
        tpo_Bbinaria += chrono::duration_cast<chrono::nanoseconds> (finish - start).count();

        // Experimentación busqueda doblada
        start = chrono::high_resolution_clock::now();
        bd = busquedaDoblada(vector,elem);
        finish = chrono::high_resolution_clock::now();
        tpo_Bdoblada += chrono::duration_cast<chrono::nanoseconds> (finish - start).count();
    }

    // Tiempo promedio por cada tamanio
    tpo_Blineal_prom = tpo_Blineal/replicas;
    tpo_Bbinaria_prom = tpo_Bbinaria/replicas;
    tpo_Bdoblada_prom = tpo_Bdoblada/replicas;

    // Se guarda en el archivo csv
    file << n << ";" << tpo_Blineal_prom << ";" << tpo_Bbinaria_prom << ";" << tpo_Bdoblada_prom << endl;
}

void expBusqueda_v1(int replicas, const vector<int> &vector, int elem, int n, ofstream &file){
    /** Busca el elemento ingresado mediante los algoritmos de binaria y doblada 
     * y guarda el tiempo computacional en cada uno de ellos***/

    bool bl, bb, bd;

    // Variables de tiempo
    float tpo_Blineal = 0.0, tpo_Blineal_prom = 0.0;
    float tpo_Bbinaria = 0.0, tpo_Bbinaria_prom = 0.0;
    float tpo_Bdoblada = 0.0, tpo_Bdoblada_prom = 0.0;

    // Replicas por tamanio
    for(int i=0; i<replicas; i++){

        // Experimentación busqueda binaria
        start = chrono::high_resolution_clock::now();
        bb = busquedaBinaria(vector,elem);
        finish = chrono::high_resolution_clock::now();
        tpo_Bbinaria += chrono::duration_cast<chrono::nanoseconds> (finish - start).count();

        // Experimentación busqueda doblada
        start = chrono::high_resolution_clock::now();
        bd = busquedaDoblada(vector,elem);
        finish = chrono::high_resolution_clock::now();
        tpo_Bdoblada += chrono::duration_cast<chrono::nanoseconds> (finish - start).count();
    }

    // Tiempo promedio por cada tamanio
    tpo_Blineal_prom = tpo_Blineal/replicas;
    tpo_Bbinaria_prom = tpo_Bbinaria/replicas;
    tpo_Bdoblada_prom = tpo_Bdoblada/replicas;

    // Se guarda en el archivo csv
    file << n << ";" << tpo_Bbinaria_prom << ";" << tpo_Bdoblada_prom << endl;
}