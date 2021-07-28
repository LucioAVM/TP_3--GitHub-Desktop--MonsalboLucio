#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(LinkedList* this,int id, int index);
int employee_getid(LinkedList* this, int id, int index);

int employee_setNombre(LinkedList* this, char* nombre, int index);
char* employee_getNombre(LinkedList* this, char* nombre, int index);

int employee_setHorasTrabajadas(LinkedList* this, int horasTrabajadas, int index);
int employee_getHorasTrabajadas(LinkedList* this, int horasTrabajadas, int index)

int employee_setSueldo(LinkedList* this, int sueldo, int index);
int employee_getSueldo(LinkedList* this, int sueldo, int index);

int cargar_idEmpleado(void);
int cargar_nuevoId(void);

void mostrarUnEmpleado(Employee list);

#endif // employee_H_INCLUDED
