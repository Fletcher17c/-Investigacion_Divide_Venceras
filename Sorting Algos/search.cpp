#include <iostream>

using namespace std;

int busqueda(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Ingrese el numero de elementos dentro del arreglo: ";
    cin >> n;
    int arr[n];
    cout << "Ingrese los elementos: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cout << "Ingrse el elemento para buscar: ";
    cin >> x;
    int indice = busqueda(arr, n, x);
    if (indice == -1) {
        cout << "Elemento no encontrado" << endl;
    } else {
        cout << "Elemento encontrado en el indice: " << indice << endl;
    }
    return 0;
}