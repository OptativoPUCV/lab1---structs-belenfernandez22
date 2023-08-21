#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/

int encontrar_elemento_mayor(int arreglo[], int tamaño) {
    if (tamaño <= 0) {
        return -1;
    }
    
    int elemento_mayor = arreglo[0];
    
    for (int i = 1; i < tamaño; i++) {
        if (arreglo[i] > elemento_mayor) {
            elemento_mayor = arreglo[i];
        }
    }
    
    return elemento_mayor;
}

int main() {
    int arreglo[] = {5, 12, 8, 3, 10, 7};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);
    
    int resultado = encontrar_elemento_mayor(arreglo, 
    tamaño);
    if (resultado != -1) {
        printf("El elemento mayor es: %d\n", resultado);
    } else {
        printf("El arreglo es inválido o está vacío.\n");
    }
    
    return 0;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/

int *filterEvenNumbers(int arr[], int size, int *newSize) {
    int evenCount = 0;
    for (int i = 0; i < size; i++) {
        evenCount += (arr[i] % 2 == 0);
    }

    int *evenArr = (int *)malloc(evenCount * sizeof(int));
    if (!evenArr) {
        *newSize = 0;
        return NULL;
    }

    for (int i = 0, index = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[index++] = arr[i];
        }
    }

    *newSize = evenCount;
    return evenArr;
}

int main() {
    int arreglo[] = {5, 12, 8, 3, 10, 7};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    int nuevoTamaño;
    int *arregloPares = filterEvenNumbers(arreglo, tamaño, &nuevoTamaño);

    if (arregloPares) {
        printf("Arreglo original: ");
        for (int i = 0; i < tamaño; i++) {
            printf("%d ", arreglo[i]);
        }

        printf("\nArreglo de números pares: ");
        for (int i = 0; i < nuevoTamaño; i++) {
            printf("%d ", arregloPares[i]);
        }

        free(arregloPares);
    } else {
        printf("No se pudo asignar memoria para el nuevo arreglo.\n");
    }

    return 0;
}


/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }
    
    while (i < size1) {
        result[k] = arr1[i];
        i++;
        k++;
    }
    
    while (j < size2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int arreglo1[] = {2, 5, 8, 12};
    int tamaño1 = sizeof(arreglo1) / sizeof(arreglo1[0]);

    int arreglo2[] = {3, 6, 9, 15};
    int tamaño2 = sizeof(arreglo2) / sizeof(arreglo2[0]);

    int tamañoResultado = tamaño1 + tamaño2;
    int arregloResultado[tamañoResultado];

    mergeSortedArrays(arreglo1, tamaño1, arreglo2, tamaño2, arregloResultado);

    printf("Arreglo 1: ");
    for (int i = 0; i < tamaño1; i++) {
        printf("%d ", arreglo1[i]);
    }

    printf("\nArreglo 2: ");
    for (int i = 0; i < tamaño2; i++) {
        printf("%d ", arreglo2[i]);
    }

    printf("\nArreglo fusionado: ");
    for (int i = 0; i < tamañoResultado; i++) {
        printf("%d ", arregloResultado[i]);
    }

    return 0;
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/

int checkSorted(int arr[], int size) {
    int ascending = 1, descending = 1;

    for (int i = 1; i < size; i++) {
        ascending &= (arr[i] >= arr[i - 1]);
        descending &= (arr[i] <= arr[i - 1]);
    }

    return ascending ? 1 : (descending ? -1 : 0);
}

int main() {
    int arregloAscendente[] = {1, 3, 5, 7, 9};
    int tamañoAscendente = sizeof(arregloAscendente) / sizeof(arregloAscendente[0]);

    int arregloDescendente[] = {10, 8, 6, 4, 2};
    int tamañoDescendente = sizeof(arregloDescendente) / sizeof(arregloDescendente[0]);

    int arregloNoOrdenado[] = {5, 2, 9, 1, 7};
    int tamañoNoOrdenado = sizeof(arregloNoOrdenado) / sizeof(arregloNoOrdenado[0]);

    printf("Arreglo ascendente: %d\n", checkSorted(arregloAscendente, tamañoAscendente));
    printf("Arreglo descendente: %d\n", checkSorted(arregloDescendente, tamañoDescendente));
    printf("Arreglo no ordenado: %d\n", checkSorted(arregloNoOrdenado, tamañoNoOrdenado));

    return 0;
}


/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/


typedef struct {
    char nombre[50];
    int anioNacimiento;
} Autor;

typedef struct {
    char titulo[100];
    Autor autor;
    int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {
    strcpy(libro->titulo, titulo);
    strcpy(libro->autor.nombre, nombreAutor);
    libro->autor.anioNacimiento = anioNacimiento;
    libro->anioPublicacion = anioPublicacion;
}

int main() {
    Libro miLibro;
    inicializarLibro(&miLibro, "Título del Libro", "Nombre del Autor", 1980, 2005);

    printf("Título: %s\n", miLibro.titulo);
    printf("Autor: %s\n", miLibro.autor.nombre);
    printf("Año de Nacimiento del Autor: %d\n", miLibro.autor.anioNacimiento);
    printf("Año de Publicación: %d\n", miLibro.anioPublicacion);

    return 0;
}


/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct Nodo {
    int num;
    struct Nodo *sig;
} Nodo;

Nodo *crearLista(int arr[], int size) {
    if (size == 0) return NULL;

    Nodo *primero = (Nodo *)malloc(sizeof(Nodo));
    if (!primero) return NULL;

    primero->num = arr[0];
    primero->sig = NULL;

    Nodo *actual = primero;

    for (int i = 1; i < size; i++) {
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        if (!nuevo) {
            Nodo *temp = primero;
            while (temp != NULL) {
                Nodo *siguiente = temp->sig;
                free(temp);
                temp = siguiente;
            }
            return NULL;
        }

        nuevo->num = arr[i];
        nuevo->sig = NULL;

        actual->sig = nuevo;
        actual = nuevo;
    }

    return primero;
}

void imprimirLista(Nodo *inicio) {
    Nodo *temp = inicio;
    while (temp != NULL) {
        printf("%d ", temp->num);
        temp = temp->sig;
    }
    printf("\n");
}

int main() {
    int arreglo[] = {3, 6, 9, 12, 15};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    Nodo *inicioLista = crearLista(arreglo, tamaño);
    if (inicioLista) {
        printf("Lista enlazada creada: ");
        imprimirLista(inicioLista);
    } else {
        printf("No se pudo crear la lista enlazada debido a problemas de memoria.\n");
    }

    return 0;
}
