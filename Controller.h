#include "LinkedList.h"
#include "Employee.h"
#include "parser.c"


void controller_cargarDesdeTexto(char* path , LinkedList* pArrayListEmployee);//MUY IMPORTANTE SUELDO

void controller_cargarDesdeBinario(char* path , LinkedList* pArrayListEmployee);//MUY IMPORTANTE SUELDO

void controller_altaEmpleado(LinkedList* pArrayListEmployee);//MUY IMPORTANTE SUELDO

void controller_modificarEmpleado(LinkedList* pArrayListEmployee);//MUY IMPORTANTE SUELDO

void controller_bajaEmpleado(LinkedList* pArrayListEmployee);//MUY IMPORTANTE SUELDO

void controller_listaEmpleados(LinkedList* pArrayListEmployee);

void controller_ordenarEmpleados(LinkedList* pArrayListEmployee);

void controller_guardarComoTexto(char* path , LinkedList* pArrayListEmployee);

void controller_guardarComoBinario(char* path , LinkedList* pArrayListEmployee);


