#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_cargarDesdeTexto(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	pFile = fopen(path,"r");

	int cantidadLeida;
	char auxiliarDatosChar[50];
	int validacion;

	if(pFile == NULL && pArrayListEmployee == NULL)
	{
		printf("ERROR, el archivo no puedo ser abierto");
	}else{

		cantidadLeida = fread(auxiliarDatosChar, sizeof(pArrayListEmployee), 1, pFile);

		if(cantidadLeida != sizeof(pArrayListEmployee))
		{
			printf("se ah leido incorrectamente el archivo, intente nuevamente");
		}

		validacion = ll_add(pArrayListEmployee, pFile);
		if(validacion!=0)
		{
			printf("ERROR, no se pudo cargar correctamente los datos");
		}
	}

	// DEVOLVER ID MAS GRANDE POR RETORNO O SI SE COMPLICA EN ALGO ARCHIVO CON ID

	fclose(path);

}// ABRE,COPIA Y CIERRA.

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_cargarDesdeBinario(char* path , LinkedList* pArrayListEmployee)
{
	pArrayListEmployee = fopen("data.csv","rb");

	if(pArrayListEmployee==NULL)//SI O SI TIENE QUE PASAR POR LA DE TEXTO Y GUARDAR BINARIO
	{
		printf("ERROR, el archivo no puede ser abierto");
	}
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_altaEmpleado(LinkedList* pArrayListEmployee)// fprintf
{
	int idEmpleado;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	Employee* empleado;
	int validacionNombre;
	int validacionHorasTrabajadas;
	int validacionSueldo;
	int largoLL;
	int id;
	int idStr;

	empleado = NULL;
	largoLL = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL)
	{
		//****************************************CARGA NOMBRE
		do
		{
			validacionNombre = getStringLetras("ingrese nombre del empleado", nombre);
			if(validacionNombre!=0)
			{
				printf("no se pudo cargar correctamente el nombre");
			}
		}while(validacionNombre != 0);

		//***************************************CARGA HORAS TRABAJADAS
		do
		{
			validacionHorasTrabajadas = getNumeros("ingrese la cantidad de horas trabajadas del empleado",horasTrabajadas);
			if(validacionHorasTrabajadas!=0)
			{
				printf("no se pudo cargar correctamente las horas trabajadas");
			}
		}while(validacionHorasTrabajadas != 0);
		//***************************************CARGA SUELDO
		do
		{
			validacionSueldo = getNumeros("ingrese el sueldo del empleado",sueldo);
			if(validacionSueldo!=0)
			{
				printf("no se pudo cargar correctamente sueldo");
			}
		}while(validacionSueldo != 0);

		//CREA NUEVO NODO Y PIDE ID
		empleado = employee_new();

		cargarUltimoID ( "doc_id.csv", idStr);

		id = atoi(idStr);
		id++;

		guardarUltimoID("doc_id.csv",id);

		//PONE LA NUEVA ESTRUCTURA CARGADA DENTRO DEL NODO
		empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
		if(empleado != NULL)
		{
			ll_add(pArrayListEmployee,empleado);
		}

	}
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_modificarEmpleado(LinkedList* pArrayListEmployee)
{
	Employee empleadoPedido;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int largoLL;
	int posicion;
	int subMenu;
	int validacion;
	int confirmacionLL;

	largoLL = ll_len(pArrayListEmployee);
	if(largoLL > 0)
	{
		getInt("\ningrese el id del empleado a modificar", &id);

		//HACER FUNCION QUE BUSQUE EMPLEADO POR ID
		posicion = buscarEmpleadoPorId(pArrayListEmployee,id);

		empleadoPedido = ll_get(pArrayListEmployee, id);

		if(empleadoPedido != NULL)
		{
			printf("\nempleado encontrado: ");
			printf("\nID ******** NOMBRE ******** HORAS TRABAJADAS ******** SUELDO");

			mostrarUnEmpleado(empleadoPedido);

			do
			{
				printf("\ningrese la opcion que decea modificar: "
						"\n1) Nombre"
						"\n2) Horas Trabajadas"
						"\n3) Sueldo"
						"\n4) Volver al menu principal\n ");
				scanf("%d", &subMenu);

				switch(subMenu)
				{
				case 1:
					getChar("\ningrese nuevo nombre del empleado", &nombre);
					do
					{
						printf("\nesta seguro de cambiar el nombre a %s?\n 1) SI \n2) NO\n ",nombre);
						scanf("%d", &validacion);
						if(validacion == 1)
						{
							confirmacionLL = employee_setNombre(pArrayListEmployee, nombre, posicion);
							if(confirmacionLL == -1)
							{
								printf("\nerror al intentar cargar el nombre a la linkedList, intente nuevamente");
							}
						}else{
							if(validacion == 2)
							{
								printf("\nse canselo la modificacion");
							}
						}
					}while(validacion != 1 && validacion != 0);

					break;

				case 2:
					getInt("\ningrese las nuevas horasTrabajadas del empleado", &horasTrabajadas);
					do
					{
						printf("\nesta seguro de cambiar las horas trabajadas a %d?\n 1) SI \n2) NO\n ",horasTrabajadas);
						scanf("%d", &validacion);
						if(validacion == 1)
						{
							confirmacionLL = employee_setHorasTrabajadas(pArrayListEmployee, horasTrabajadas, posicion);
							if(confirmacionLL == -1)
							{
								printf("\nerror al intentar cargar el nombre a la linkedList, intente nuevamente");
							}
						}else{
							if(validacion == 2)
							{
								printf("\nse canselo la modificacion");
							}
						}
					}while(validacion != 1 && validacion != 0);
					break;

				case 3:
					getInt("\ningrese el nuevo sueldo del empleado: ", &sueldo);
					do
					{
						printf("esta seguro de cambiar las horas trabajadas a %d?\n 1) SI \n2) NO\n ",sueldo);
						scanf("%d", &validacion);
						if(validacion == 1)
						{
							confirmacionLL = employee_setNombre(pArrayListEmployee, nombre, posicion);
							if(confirmacionLL == -1)
							{
								printf("\nerror al intentar cargar el nombre a la linkedList, intente nuevamente");
							}
						}else{
							if(validacion == 2)
							{
								printf("\nse canselo la modificacion");
							}
						}
					}while(validacion != 1 && validacion != 0);
					break;
				case 4:
					break;
				}
			}while(subMenu != 4);
		}else{
			printf("no se ah podido encontrar el empleado");
		}
	}
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_bajaEmpleado(LinkedList* pArrayListEmployee)
{
	int largoLL;
	int id;
	Employee empleadoPedido;
	int posicion;
	int validacion;
	int confirmacionLL;

	largoLL = ll_len(pArrayListEmployee);
	if(largoLL > 0)
	{
		getInt("\ningrese el id del empleado a dar de baja", &id);

		//HACER FUNCION QUE BUSQUE EMPLEADO POR ID
		posicion = buscarEmpleadoPorId(pArrayListEmployee,id);
		if(posicion != NULL)
		{
			empleadoPedido = ll_get(pArrayListEmployee, id);

			if(empleadoPedido != NULL)
			{
				printf("\nempleado encontrado: ");
				printf("\nID ******** NOMBRE ******** HORAS TRABAJADAS ******** SUELDO");

				mostrarUnEmpleado(empleadoPedido);
				printf("esta seguro que quiere dar de baja dicho empleado?\n 1) SI \n2) NO\n ");
				scanf("%d", &validacion);
				if(validacion == 1)
				{
					confirmacionLL = ll_remove(pArrayListEmployee, posicion);
					if(confirmacionLL == -1)
					{
						printf("\nerror al intentar dar de baja el empleado, intente nuevamente");
					}else{
						printf("baja realizada con exito");
					}
				}else{
					if(validacion == 2)
					{
						printf("\nse canselo la baja");
					}
				}
			}else{
				printf("no se ah podido encontrar el empleado");
			}
		}else{
			printf("no existe empleado que posea el id ingresado");
		}
	}
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_listaEmpleados(LinkedList* pArrayListEmployee)
{
	int i;
	int largo;
	void* pEmpleado;
	Employee empleado;

	largo = ll_len(pArrayListEmployee);

	if(largo > 0)
	{
		puts("\nEMPLEADOS: ");
		puts("\nID ******** NOMBRE ******** APELLIDO ******** SALARIO ******** SECTOR");
		for(i=0; i<largo; i++)
		{
			pEmpleado = ll_get(pArrayListEmployee,i);
			empleado = &pEmpleado;
			mostrarUnEmpleado(empleado);
		}
	}
	else
	{
		puts("\nNo hay empleados cargados para mostrar.");
	}
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_ordenarEmpleados(LinkedList* pArrayListEmployee)
{
	int subMenu;
	int orden;
	LinkedList* thisCLone;
	int validacion;
	void* pEmpleado;
	Employee empleado;
	int i;
	int largo;

	if(pArrayListEmployee != NULL)
	{
		largo = ll_len(pArrayListEmployee);
		thisCLone = ll_clone(pArrayListEmployee);

		do
		{
			getInt("\ningrese opcion por la cual desea ordenar: "
					"\n1) Nombre"
					"\n2) Sueldo"
					"\n3) Horas Trabajadas"
					"4) volver al menu principal\n ",&subMenu);
			getInt("\ningrese: \n1) Ascendente\n2) Descendente", &orden);
			switch(subMenu)
			{
			case 1:
				validacion = ll_sort(thisCLone,ordenarNombre,orden);
				break;

			case 2:
				validacion = ll_sort(ordenarPorSueldo,ordenarNombre,orden);
				break;

			case 3:
				validacion = ll_sort(thisCLone,ordenarPorHorasTrabajadas,orden);
				break;
			}
			if(validacion == 0)
			{
				printf("\nse ordeno conrrectamente la lista: ");
				for(i=0; i<largo; i++)
				{
					pEmpleado = ll_get(pArrayListEmployee,i);
					empleado = pEmpleado;
					mostrarUnEmpleado(empleado);
				}
			}
		}while(subMenu != 4);
	}
	ll_deleteLinkedList(thisCLone);
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_guardarComoTexto(char* path , LinkedList* pArrayListEmployee)
{

	FILE* pArchivoTexto;
	Employee* empleado;
	int tam;
	int i;

	tam = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee !=NULL)
	{
		pArchivoTexto = fopen(path,"w");

		if(pArchivoTexto !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee,i);
				fwrite(empleado,sizeof(Employee),1,pArchivoTexto);
			}
		}
		fclose(pArchivoTexto);
	}
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_guardarComoBinario(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivoBinario;
	Employee* empleado;
	int tam;
	int i;

	tam = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee !=NULL)
	{
		pArchivoBinario = fopen(path,"wb");

		if(pArchivoBinario !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee,i);
				fwrite(empleado,sizeof(Employee),1,pArchivoBinario);
			}
		}
		fclose(pArchivoBinario);
	}
}

