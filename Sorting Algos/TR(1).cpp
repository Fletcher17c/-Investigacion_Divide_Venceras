#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "timsort.cpp"
#include "merge.cpp"

using namespace std;
using namespace std::chrono;

duration<double> timer(steady_clock::time_point t1, steady_clock::time_point t2)
{
    return duration_cast<duration<double>>(t2 - t1);
}

vector<int> generarNumerosAleatorios(int n, int rango_min, int rango_max)
{
    vector<int> numerosAleatorios;
    numerosAleatorios.reserve(n); // Reservar espacio para n elementos para mejorar el rendimiento
    for (int i = 0; i < n; ++i)
    {
        int numero = rango_min + rand() % (rango_max - rango_min + 1);
        numerosAleatorios.push_back(numero);
    }
    return numerosAleatorios;
}

int main()
{
    // Inicializar la semilla del generador de numeros aleatorios
    srand(static_cast<unsigned>(time(0)));
    duration<double> time_span;
    steady_clock::time_point t1, t2;
    int n;
    int rango_min;
    int rango_max;

    cout << "Ingrese la cantidad de numeros aleatorios a generar: ";
    cin >> n;

    cout << "Ingrese el rango manimo: ";
    cin >> rango_min;

    cout << "Ingrese el rango maximo: ";
    cin >> rango_max;

    t1 = steady_clock::now();
    vector<int> numerosAleatorios = generarNumerosAleatorios(n, rango_min, rango_max);
    t2 = steady_clock::now();
    time_span = timer(t1, t2);
    float time_taken = time_span.count();
    printf("\n Duracion del generador de elementos random para %d elementos: %.4f ", n, time_taken);
    vector<int> set1 = numerosAleatorios;
    vector<int> set2 = numerosAleatorios;
    vector<int> set3 = numerosAleatorios;

    cout << endl << "--------------" << endl;
    t1 = steady_clock::now();
    tim_sort(set1, set1.size());
    t2 = steady_clock::now();
    time_span = timer(t1, t2);
    time_taken = time_span.count();
    printf("\n Duracion de Tim sort en segundos para %d elementos: %.4f ", n, time_taken);

    cout << endl << "--------------" << endl;
    t1 = steady_clock::now();
    merge_sort(set2, 0, set2.size() - 1);
    t2 = steady_clock::now();
    time_span = timer(t1, t2);
    time_taken = time_span.count();
    printf("\n Duracion de merge sort en segundos para %d elementos: %.4f ", n, time_taken);
    return 0;
}

// why does the program ends before the tim_sort is reached