#include <iostream>
#include <chrono>

using namespace std;

// Para ejecutar la operació heapify en un árbol con raíz en el nodo i
// el cual es un índice en arr[]. n es el tamaño del heap
void heapify(int arr[], int N, int i)
{

    // Inilicializar el nodo más grande como la raíz
    int largest = i;

    // el hijo izquiero = 2 veces el índice + 1
    int l = 2 * i + 1;

    // el hijo derecho = 2 veces el índice + 2
    int r = 2 * i + 2;

    // si el hijo izquierdo es más grande que la raíz
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // si el hijo derecho es más grande que el nodo más grande
    // hasta ahora
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // si el nodo más grande no es la raíz
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursivamente hacer heapify en el sub-árbol afectado
        heapify(arr, N, largest);
    }
}

// Función principal para hacer el heap sort
void heapSort(int arr[], int N)
{

    // Construir un heap (reorganizar el arreglo)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // Un por uno extraer un elemento del heap
    for (int i = N - 1; i > 0; i--) {

        // Mover la raíz actual al final
        swap(arr[0], arr[i]);

        // llamar a heapify en el heap reducido
        heapify(arr, i, 0);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Programa principal
int main()
{
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    do {
        cin >> n;
        if (n < 0) {
            cout << "Ingrese un valor positivo: ";
        }
    } while (n < 0);
    int arr[n];
    for (int i = 0; i < 1000; i++)
    {
        arr[i] = rand() % 1000+1;
    }
    int N = sizeof(arr) / sizeof(arr[0]);

    // Llamar a la función de ordenamiento
    auto start = chrono::steady_clock::now();
    heapSort(arr, N);
    auto end = chrono::steady_clock::now();
    cout << "Sorted array is \n";
    printArray(arr, N);
    cout << "Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
}
