#include "Employee.h"


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldosStr)
{
	Employee nuevoEmpleado;

	nuevoEmpleado = NULL;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldosStr != NULL)
	{
		nuevoEmpleado.id = atoi(idStr);
		strcpy(nuevoEmpleado.nombre,nombreStr);
		nuevoEmpleado.horasTrabajadas = atoi(horasTrabajadasStr);
		nuevoEmpleado.sueldo = atoi(sueldosStr);
	}
	return nuevoEmpleado;
}

int employee_setId(LinkedList* this,int id, int index)
{
	int retorno;
	void* auxiliar;
	Employee empleado;

	retorno = -1;

	if(this != NULL && id >0)
	{
		auxiliar = test_getNode( this, index);
		if(auxiliar != NULL)
		{
			empleado = &auxiliar;
			empleado.id = id;
			ll_set( this, index, empleado);
		}
	}
	return retorno;
}

int employee_getid(LinkedList* this, int id, int index)
{
	int retorno;
	Node* aux;
	Employee empleado;

	retorno = -1;

	if(this != NULL && id >0)
	{
		aux = test_getNode( this, index);
		if(aux != NULL)
		{
			empleado = aux->pElement;
			retorno = empleado.id ;
		}
	}
	return retorno;
}

int employee_setNombre(LinkedList* this,char* nombre, int index)
{
	int retorno;
	Node* aux;
	Employee empleado;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		aux = test_getNode( this, index);
		if(aux != NULL)
		{
			empleado = aux->pElement;
			strcpy(empleado.nombre, nombre);
			ll_set( this, index, empleado);
		}
	}
	return retorno;
}


char* employee_getNombre(LinkedList* this,char* nombre, int index)
{
	int retorno;
	Node* aux;
	Employee empleado;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		aux = test_getNode( this, index);
		if(aux != NULL)
		{
			empleado = aux->pElement;
			retorno = empleado.nombre ;
		}
	}
	return retorno;
}

int employee_setHorasTrabajadas(LinkedList* this,int horasTrabajadas, int index)
{
	int retorno;
	Node* aux;
	Employee empleado;

	retorno = -1;

	if(this != NULL && horasTrabajadas >0)
	{
		aux = test_getNode( this, index);
		if(aux != NULL)
		{
			empleado = aux->pElement;
			empleado.id = horasTrabajadas;
			ll_set( this, index, empleado);
		}
	}
	return retorno;
}
int employee_getHorasTrabajadas(LinkedList* this,int horasTrabajadas, int index)
{
	int retorno;
	Node* aux;
	Employee empleado;

	retorno = -1;

	if(this != NULL && horasTrabajadas >-1)
	{
		aux = test_getNode( this, index);
		if(aux != NULL)
		{
			empleado = aux->pElement;
			retorno = empleado.horasTrabajadas ;
		}
	}
	return retorno;
}

int employee_setSueldo(LinkedList* this,int sueldo, int index)
{
	int retorno;
	Node* aux;
	Employee empleado;

	retorno = -1;

	if(this != NULL && sueldo >0)
	{
		aux = test_getNode( this, index);
		if(aux != NULL)
		{
			empleado = aux->pElement;
			empleado.id = sueldo;
			ll_set( this, index, empleado);
		}
	}
	return retorno;
}
int employee_getSueldo(LinkedList* this,int* sueldo, int index)
{
	int retorno;
	Node* aux;
	Employee empleado;

	retorno = -1;

	if(this != NULL && sueldo >0)
	{
		aux = test_getNode( this, index);
		if(aux != NULL)
		{
			empleado = aux->pElement;
			retorno = empleado.sueldo;
		}
	}
	return retorno;
}

int cargar_idEmpleado(void)
{
	int retorno;

	retorno = -1;

	fopen("id.csv","r");

	fread(&retorno,sizeof(retorno),1,"id.csv");

	return retorno;
}

int cargar_nuevoId(void)
{
	int retorno;

	retorno = -1;

	fopen("id.csv","r");

	fread(&retorno,sizeof(retorno),1,"id.csv");

	return retorno++;
}

void mostrarUnEmpleado(Employee list)
{
	printf("\n%d %16s %17s %16.2f %15d", list.id,
			list.nombre,
			list.horasTrabajadas,
			list.sueldo);
}

int buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	Employee pAuxElement;
	int i;
	int tam;

	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);

		for(i=0; i<tam; i++)
		{
			pAuxElement = ll_get(pArrayListEmployee, i);

			if(pAuxElement.id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int ordenarNombre(void* empleado1,void* empleado2)
{

    if(((Employee*)empleado1)->nombre > ((Employee*)empleado2)->nombre)
    {
        return 1;
    }
    if(((Employee*)empleado1)->nombre < ((Employee*)empleado2)->nombre)
    {
        return -1;
    }
    return 0;
}

int ordenarPorSueldo(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->sueldo > ((Employee*)pEmployeeB)->sueldo)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->sueldo < ((Employee*)pEmployeeB)->sueldo)
    {
        return -1;
    }
    return 0;


}int ordenarPorHorasTrabajadas(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->horasTrabajadas > ((Employee*)pEmployeeB)->horasTrabajadas)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->horasTrabajadas < ((Employee*)pEmployeeB)->horasTrabajadas)
    {
        return -1;
    }
    return 0;


}
