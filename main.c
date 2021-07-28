
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/

int main()
{
	FILE* pFile;
	int opcion;
	int validacion;
	int primeroTexto;
	char path[30];


	fopen("doc_id.csv","w");

	fwrite("0",sizeof(int),1,pFile);        // NOOO TESTEADOOOOOOOOOOOOOOOOO

	fclose(pFile);

	primeroTexto = 0;
	opcion = 0;

	LinkedList* listaEmpleados = ll_newLinkedList();
	do{
		printf("\nMenu:"
				"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
				"\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
				"\n3. Alta de empleado"
				"\n4. Modificar datos de empleado"
				"\n5. Baja de empleado"
				"\n6. Listar empleados"
				"\n7. Ordenar empleados"
				"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
				"\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
				"\n10. Salir");
		scanf("%d", &opcion);
		switch(opcion)
		{
		case 1://CARGAR TEXTO

			printf("\ningrese el nombre del archivo que desea abrir");
			scanf("%s", &path);

			controller_cargarDesdeTexto(path,listaEmpleados);
			primeroTexto = 1;
			break;


		case 2://CARGAR BINARIO

			if(primeroTexto == 0)
			{
				printf("\nprimero se debe cargar por lo menos una ves el archivo en formato texto");
			}else{
				printf("\ningrese el nombre del archivo que desea abrir");
				scanf("%s", &path);

				controller_cargarDesdeBinario(path,listaEmpleados);
			}
			break;

		case 3://ALTA
			controller_altaEmpleado(listaEmpleados);
			break;


		case 4://MODIFICACION
			controller_modificarEmpleado(listaEmpleados);
			break;


		case 5://BAJA
			controller_bajaEmpleado(listaEmpleados);
			break;


		case 6://LISTA
			controller_listaEmpleados(listaEmpleados);
			break;


		case 7://ORDENAR POR (NOMBRE------HORAS---SUELDO)
			controller_ordenarEmpleados(listaEmpleados);
			break;


		case 8://GUARDAR TEXTO

			if(primeroTexto == 0)
			{
				printf("\nprimero se debe cargar por lo menos una ves el archivo ");
			}else{
				printf("\ningrese el nombre del archivo que desea abrir");
				scanf("%s", &path);

				controller_guardarComoTexto(path,listaEmpleados);
			}
			break;


		case 9://GUARDAR BINARIO
			if(primeroTexto == 0)
			{
				printf("\nprimero se debe cargar por lo menos una ves el archivo ");
			}else{
				printf("\ningrese el nombre del archivo que desea abrir");
				scanf("%s", &path);

				controller_guardarComoBinario(path,listaEmpleados);
			}
			break;


		case 10://SALIR (HACER DESPEDIDA)
			printf( "\n           GRACIAS POR UTILIZAR ESTE PROGRAMA\n"
					"             PRODUCIDO POR Monsalbo lucio\n"
					"              EDITADO POR Lucio Monsalbo\n"
					"         BUILDEADO POR Alejandro Lucio Monsalbo\n"
					"        TESTEADO POR Valerio Alejandro Monsalbo\n"
					"        ENVIADO POR Monsalbo Lucio Alejandro Valerio\n"
					"   AGRADECIMIENTO ESPECIAL A Lucio Alejandro Valerio Monsalbo\n");
			break;///SI CARGO Y GUARDO SI
		}
	}while(opcion == 10);
	return 0;
}

