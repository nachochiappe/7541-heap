#include "heap.h"
#include "testing.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

        // Funciones auxiliares //

int comp(const void* clave_vieja, const void* clave_nueva) {
	// Si las claves son iguales, devuelve 0
	int vieja = *(int*) clave_vieja;
	int nueva = *(int*) clave_nueva;
	if (vieja == nueva) return 0;
	// Si clave nueva es mayor a clave vieja, return -1
	else if (nueva > vieja) return (-1);
	// Si clave nueva es menor a clave vieja, return 1
	return 1;
}
cmp_func_t cmp = &comp;

heap_t* crear_heap_vacio(int num_prueba){
    printf ("\nPrueba Heap %i:\n", num_prueba);
    heap_t* heap = heap_crear(cmp);
	print_test("Prueba heap vacio: ", heap);
	print_test("Cantidad de heap es 0: ", heap_cantidad(heap) == 0);
	print_test("Heap esta vacio: ", heap_esta_vacio(heap));
    return heap;
}


        // Prueba Heap vacio //
void pruebas_heap_vacio(){
    heap_t* heap = crear_heap_vacio(1);
	print_test("Encolar NULL en heap es false: ", !heap_encolar(heap, NULL));
	print_test("Cantidad de heap es 0: ", heap_cantidad(heap) == 0);
	print_test("Ver maximo en heap es NULL: ", !heap_ver_max(heap));
	print_test("Desencolar en heap vacio es NULL: ", !heap_desencolar(heap));
	print_test("Cantidad de heap es 0: ", heap_cantidad(heap) == 0);
    heap_destruir(heap, NULL);
    print_test("Destruir heap: ", true);
    return;
}

        // Prueba Heap estandar //
void pruebas_heap_estandar(){
    heap_t* heap = crear_heap_vacio(2);
    int vector_numeros[] = {1, 2, 3, 4};
	print_test("Encolar '1' en heap: ", heap_encolar(heap, &vector_numeros[0]));
	print_test("Cantidad de heap es 1: ", heap_cantidad(heap) == 1);
	print_test("Ver maximo en heap es '1': ", *(int*) heap_ver_max(heap) == 1);
	print_test("Heap no esta vacio: ", !heap_esta_vacio(heap));
    print_test("Encolar '1' en heap: ", heap_encolar(heap, &vector_numeros[0]));
	print_test("Cantidad de heap es 1: ", heap_cantidad(heap) == 2);
	print_test("Ver maximo en heap es '1': ", *(int*) heap_ver_max(heap) == 1);
	print_test("Heap no esta vacio: ", !heap_esta_vacio(heap));
	print_test("Desencolar en heap es '1': ", *(int*) heap_desencolar(heap) == 1);
	print_test("Desencolar en heap es '1': ", *(int*) heap_desencolar(heap) == 1);
	print_test("Cantidad de heap es 0: ", heap_cantidad(heap) == 0);
	print_test("Heap esta vacio: ", heap_esta_vacio(heap));
    for (int i = 0; i < 4; i++){
        printf ("Encolar %i en heap", i + 1);
    	print_test(": ", heap_encolar(heap, &vector_numeros[i]));
        printf ("Cantidad de heap es %i", i + 1);
	    print_test(": ", heap_cantidad(heap) == i + 1);
    }
	print_test("Ver maximo en heap es '4': ", *(int*) heap_ver_max(heap) == 4);
    for (int i = 0; i < 4; i++){
        printf ("Desencolar en heap es '%i'", 4 - i);
    	print_test(": ", *(int*) heap_desencolar(heap) == 4 - i);
        printf ("Cantidad de heap es %i", 3 - i);
	    print_test(": ", heap_cantidad(heap) == 3 - i);
    }
    heap_destruir(heap, NULL);
    print_test("Destruir heap: ", true);
    return;
}

void pruebas_heapsort(){
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    void *vector_numeros[] = {&n1, &n2, &n3, &n4};
    heap_sort(vector_numeros, 4, cmp);
    for (int i = 0; i < 4; i++){
        printf ("%i. %i\n", i, *(int*)vector_numeros[i]);
    }
}

void pruebas_heap_alumno(void){
    pruebas_heap_vacio();
    pruebas_heap_estandar();
    pruebas_heapsort();
}
