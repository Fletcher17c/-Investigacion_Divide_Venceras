using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DivideYVencerasEj1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            const int size = 10; // Tamaño fijo del arreglo
            int[] array = new int[size];

            Console.WriteLine($"Introduce {size} elementos para el arreglo:");
            for (int i = 0; i < size; i++)
            {
                Console.Write($"Elemento {i + 1}: ");
                array[i] = int.Parse(Console.ReadLine());
            }

            int choice;

            do
            {
                Console.WriteLine("Menú:");
                Console.WriteLine("1. Mostrar arreglo original");
                Console.WriteLine("2. Ordenar arreglo usando Merge Sort");
                Console.WriteLine("3. Salir");
                Console.Write("Elige una opción: ");
                choice = int.Parse(Console.ReadLine());

                switch (choice)
                {
                    case 1:
                        MostrarArreglo(array);
                        break;
                    case 2:
                        MergeSort(array, 0, array.Length - 1);
                        Console.WriteLine("Arreglo ordenado:");
                        MostrarArreglo(array);
                        break;
                    case 3:
                        Console.WriteLine("Saliendo...");
                        break;
                    default:
                        Console.WriteLine("Opción no válida. Inténtalo de nuevo.");
                        break;
                }
            } while (choice != 3);
        }

        static void MostrarArreglo(int[] array)
        {
            foreach (int item in array)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }

        static void MergeSort(int[] array, int left, int right)
        {
            if (left < right)
            {
                int mid = left + (right - left) / 2;
                // Ordenar primera y segunda mitad
                MergeSort(array, left, mid);
                MergeSort(array, mid + 1, right);

                // Fusionar las mitades ordenadas
                Merge(array, left, mid, right);
            }
        }

        static void Merge(int[] array, int left, int mid, int right)
        {
            int subarray1 = mid - left + 1;
            int subarray2 = right - mid;
            int[] tempArrayLeft = new int[subarray1];
            int[] tempArrayRight = new int[subarray2];

            for (int i = 0; i < subarray1; i++)
            {
                tempArrayLeft[i] = array[left + i];
            }
            // Aquí se copia a los vectores temporales los valores del vector principal
            for (int i = 0; i < subarray2; i++)
            {
                tempArrayRight[i] = array[mid + 1 + i];
            }

            int leftIndex = 0, rightIndex = 0, mergeIndex = left;

            while (leftIndex < subarray1 && rightIndex < subarray2)
            {
                if (tempArrayLeft[leftIndex] <= tempArrayRight[rightIndex])
                {
                    array[mergeIndex] = tempArrayLeft[leftIndex];
                    leftIndex++;
                }
                else
                {
                    array[mergeIndex] = tempArrayRight[rightIndex];
                    rightIndex++;
                }
                mergeIndex++;
            }

            while (leftIndex < subarray1)
            {
                array[mergeIndex] = tempArrayLeft[leftIndex];
                leftIndex++;
                mergeIndex++;
            }

            while (rightIndex < subarray2)
            {
                array[mergeIndex] = tempArrayRight[rightIndex];
                rightIndex++;
                mergeIndex++;
            }
        }

    }
}
