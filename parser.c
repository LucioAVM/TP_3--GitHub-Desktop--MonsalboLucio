#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char id[1000];
	char nombre[1000];
	char horasTrabajadas[1000];
	char sueldo;
	Employee* pEmpleados;
	int contador;

	contador = 0;
	retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas,sueldo);//falsa lectura

		do
		{
			contador++;
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas,sueldo)==4)
			{
				pEmpleados = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				if(pEmpleados != NULL)
				{
					ll_add(pArrayListEmployee,pEmpleados);
				}else{
					retorno = 0;
				}
			}
		}while(!feof(pFile));

	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char id[1000];
	char nombre[1000];
	char horasTrabajadas[1000];
	char sueldo;
	Employee* pEmpleados;
	int contador;

	contador = 0;
	retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas,sueldo);//falsa lectura

		do
		{
			contador++;
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas,sueldo)==4)
			{
				pEmpleados = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				if(pEmpleados != NULL)
				{
					ll_add(pArrayListEmployee,pEmpleados);
				}else{
					retorno = 0;
				}
			}
		}while(!feof(pFile));

	}
	return retorno;
}
