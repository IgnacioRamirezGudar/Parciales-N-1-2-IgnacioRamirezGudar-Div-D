/*
 ============================================================================
 Name        : RECUPERATORIO.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <windows.h>
#include "VIVIENDA.h"
#include "input-UTN.h"
#include "CENSISTA.h"

#define TAMARRAY 4

static int cont = -1;

static int banderaIngesar;

static int banderaLegajo = 1;

static int idcomprobar = 20000;

static int banderaDesacID = 1;

int comprobar(){

	idcomprobar++;

	return idcomprobar;
}
/*
 *
 *
 *
 */
int ADDVIVIENDA(VIVIENDAS ListaVIVIENDAS[], CATASTROS ListaCATASTROS[],CENSISTAS ListaCENSISTAS[],int tam, int cont);
int MODIFICVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tam);
int LOWERVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tam);

int LISTCATASTRO(VIVIENDAS ListaVIVIENDAS[], CATASTROS ListaCATASTROS[],CENSISTAS ListaCENSISTAS[], int tam);
int LISTVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tam);
int LISTCENSISTA(CENSISTAS ListaCENSISTAS[], int tam);


int main(void) {

	setbuf(stdout, NULL);

	VIVIENDAS ListaVIVIENDAS[TAMARRAY];

	CATASTROS ListaCATASTROS[TAMARRAY];

	CENSISTAS ListaCENSISTAS[TAMARRAY];

	int opciones;

	if(banderaDesacID == 1){
		init(ListaVIVIENDAS,ListaCATASTROS, TAMARRAY);
		init2(ListaCENSISTAS, TAMARRAY);
		banderaDesacID = 0;
	}


	do{
		fflush(stdin);
		UTN_getNumero(&opciones,"\n==================CENSO NACIONAL 2022=================="
										"\n1) ALTA VIVIENDA"
										"\n2) MODIFICAR VIVIENDA"
										"\n3) BAJA VIVIENDA"
										"\n4) LISTAR VIVIENDA"
										"\n5) LISTAR CENSISTAS"
										"\n6) LISTAR CATASTRO-ORDENADO POR LOCALIDAD"
										"\n7) SALIR"
										"\n------------------------"
										"\nSELECCIONE UNA OPCION: ","\nERROR...ELIGA UNA OPCION VALIDA""\n",1,7,5);
		switch(opciones){
			case 1:
				comprobar();
				cont++;
				banderaIngesar = 1;
				ADDVIVIENDA(ListaVIVIENDAS, ListaCATASTROS,ListaCENSISTAS, TAMARRAY, cont);
				break;
			case 2:
				if(banderaIngesar == 1){
					MODIFICVIVIENDA(ListaVIVIENDAS, TAMARRAY);
				} else {
					printf("\nPRIMERO DEBE CARGAR UNA VIVIENDA");
				}
				break;
			case 3:
				if(banderaIngesar == 1){
					LOWERVIVIENDA(ListaVIVIENDAS, TAMARRAY);
				} else {
					printf("\nPRIMERO DEBE CARGAR UNA VIVIENDA");
				}
				break;
			case 4:
				if(banderaIngesar == 1){
					LISTVIVIENDA(ListaVIVIENDAS, TAMARRAY);
					printf("\n");
					system("pause");
				} else {
					printf("\nPRIMERO DEBE CARGAR UNA VIVIENDA");
				}
				break;
			case 5:
				if(banderaIngesar == 1){
					LISTCENSISTA(ListaCENSISTAS,TAMARRAY);
					printf("\n");
					system("pause");
				} else {
					printf("\nPRIMERO DEBE CARGAR UNA VIVIENDA");
				}

				break;
			case 6:
				if(banderaIngesar == 1){
					LISTCATASTRO(ListaVIVIENDAS, ListaCATASTROS,ListaCENSISTAS,TAMARRAY);
				} else {
					printf("\nPRIMERO DEBE CARGAR UNA VIVIENDA");
				}
				break;
			default:
				return 0;
				break;

		}
	}while(opciones != 7);

	return 0;
}

int ADDVIVIENDA(VIVIENDAS ListaVIVIENDAS[], CATASTROS ListaCATASTROS[], CENSISTAS ListaCENSISTAS[],int tam, int cont){
	char opcion[51];

	/*VIVIENDAS*/
	char street[25];
	int cantPersons;
	int cantRooms;
	int typeApartment;
	int legCen;

	/*CATASTROS*/
	char localidad[51];
	char manzana[25];
	char parcela[25];

	/*CENSISTA*/
	char nombre[51];
	int edad;
	int telefono;

	UTN_getAlfaNum(street,25,"\n-INGRESE CALLE Y DIRECCION DE LA CASA: ","\nERROR AL INTRODUCIR CALLE O DIRECCION DE LA CASA", 5);
	UTN_getNumero(&cantPersons,"\n-CANTIDAD DE PERSONAS QUE VIVEN EN LA CASA: ","\nERROR AL INGRESAR LA CANTIDAD DE PERSONAS",1,10,5);
	UTN_getNumero(&cantRooms,"\n-CANTIDAD DE HABITACIONES QUE HAY EN LA CASA: ","\nERROR AL INGRESAR LA CANTIDAD DE HABITACIONES", 1,10,5);
	UTN_getNumeroRange(&typeApartment,"\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO| \nELIGA SU TIPO DE VIVIENDA: ","\nERROR AL ELEGIR EL TIPO DE VIVIENDA",1,4,5);
	UTN_getNumero(&legCen,"\n-INGRESE UN LEGAJO (LEGAJO CENSISTA): ","\nERROR AL INGRESAR EL NUMERO DEL LEGAJO",1,1000000,5);

	if(banderaLegajo == 1){
			UTN_getAlfaNum(localidad, 25,"\n INGRESE LA LOCALIDAD EN DONDE VIVE: ","\n ERROR AL INGRESAR LA LOCALIDAD",5);
			UTN_getAlfaNum(manzana, 23, "\n INGRESE LA MANZANA: ", "\n ERROR AL INGRESAR LA MANZANA", 5);
			UTN_getAlfaNum(parcela, 23, "\n INGRESE LA PARCELA DE SU CASA: ", "\n ERROR AL INGRESAR LA PARCELA", 5);

			UTN_getString(nombre,51,"\n-INGRESE NOMBRE DEL ENCARGADO DE LA CASA: ","\n ERROR...AL INGRESAR ESE NOMBRE",10);
			UTN_getNumero(&edad,"\n-INGRESE LA EDAD DEL CENSISTA: ","\nERROR... AL INGRESAR LA EDAD",20,100,5);
			printf("\n-INGRESE SU NUMERO DE TELEFONO: ");
			scanf("%d", &telefono);

			AddNewVIVIENDA(ListaVIVIENDAS, cont,street,cantPersons,cantRooms,typeApartment,legCen);
			AddNewCATASTRO(ListaCATASTROS,cont,localidad,manzana,parcela);
			AddNewCENSISTA(ListaCENSISTAS, cont, legCen,nombre, edad, telefono);

			banderaLegajo = 0;

	} else {
		if(banderaLegajo == 0){
			for(int i = 0; i <= tam; i++){
					if(ListaVIVIENDAS[i].legCen == legCen){
						printf("\nEL LEGAJO INGRESADO YA SE HA INGRESADO ANTERIORMENTE");
						printf("\n¿QUIERE INGRESAR ESTA NUEVA VIVIENDA A ESTE LEGAJO? (ACEPTAR / CANCELAR): ");
						fflush(stdin);
						gets(opcion);
						if(strcmp(opcion,"ACEPTAR") == 0 || strcmp(opcion,"aceptar") == 0){
							for(int i = 0; i <= tam; i++){
								UTN_getAlfaNum(localidad, 25,"\n INGRESE LA LOCALIDAD EN DONDE VIVE: ","\n ERROR AL INGRESAR LA LOCALIDAD",5);
								UTN_getAlfaNum(manzana, 23, "\n INGRESE LA MANZANA: ", "\n ERROR AL INGRESAR LA MANZANA", 5);
								UTN_getAlfaNum(parcela, 23, "\n INGRESE LA PARCELA DE SU CASA: ", "\n ERROR AL INGRESAR LA PARCELA", 5);

								AddNewVIVIENDA(ListaVIVIENDAS, cont,street,cantPersons,cantRooms,typeApartment,legCen);
								AddNewCATASTRO(ListaCATASTROS,cont,localidad,manzana,parcela);
								AddNewCENSISTA(ListaCENSISTAS, cont, legCen,ListaCENSISTAS[i].nombre, ListaCENSISTAS[i].edad, ListaCENSISTAS[i].telefono);

								return 0;
							}
						} else{
							if(strcmp(opcion,"CANCELAR") == 0 || strcmp(opcion,"cancelar") == 0){
								return 0;
							}
						}
					} else {
						UTN_getAlfaNum(localidad, 25,"\n INGRESE LA LOCALIDAD EN DONDE VIVE: ","\n ERROR AL INGRESAR LA LOCALIDAD",5);
						UTN_getAlfaNum(manzana, 23, "\n INGRESE LA MANZANA: ", "\n ERROR AL INGRESAR LA MANZANA", 5);
						UTN_getAlfaNum(parcela, 23, "\n INGRESE LA PARCELA DE SU CASA: ", "\n ERROR AL INGRESAR LA PARCELA", 5);

						UTN_getString(nombre,51,"\n-INGRESE NOMBRE DEL ENCARGADO DE LA CASA: ","\n ERROR...AL INGRESAR ESE NOMBRE",10);
						UTN_getNumero(&edad,"\n-INGRESE LA EDAD DEL CENSISTA: ","\nERROR... AL INGRESAR LA EDAD",20,100,5);
						printf("\n-INGRESE SU NUMERO DE TELEFONO: ");
						scanf("%d", &telefono);

						AddNewVIVIENDA(ListaVIVIENDAS, cont,street,cantPersons,cantRooms,typeApartment,legCen);
						AddNewCATASTRO(ListaCATASTROS,cont,localidad,manzana,parcela);
						AddNewCENSISTA(ListaCENSISTAS, cont, legCen,nombre, edad, telefono);

					}
			}

		}

	}

	return 0;

}

int MODIFICVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tam){

	int id;

	printf("\n==================CENSO NACIONAL 2022 / MODIFICAR VIVIENDA==================");
	UTN_getNumero(&id,"\n- INGRESE ID DE LA VIVIENDA QUE DESEA MODIFICAR (rango de ID apartir desde 20001): ","\nERROR AL INGRESAR LA ID",20001,1000000,10);

	ModVIVIENDA(ListaVIVIENDAS, tam,id);

	return 0;
}

int LOWERVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tam){

	int id;

	printf("\n==================CENSO NACIONAL 2022 / BAJAR VIVIENDA==================");
	UTN_getNumero(&id,"\n- INGRESE ID DE LA VIVIENDA QUE DESEA BAJAR (rango de ID apartir desde 20001): ","\nERROR AL INGRESAR LA ID",20001,1000000,10);

	lowVIVIENDA(ListaVIVIENDAS, tam,id);

	return 0;
}

int LISTVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tam){

	showListVIVIENDA(ListaVIVIENDAS, tam);

	return 0;
}

int LISTCENSISTA(CENSISTAS ListaCENSISTAS[], int tam){

	showListCENSISTA(ListaCENSISTAS, tam);

	return 0;
}

int LISTCATASTRO(VIVIENDAS ListaVIVIENDAS[], CATASTROS ListaCATASTROS[],CENSISTAS ListaCENSISTAS[], int tam){

	int opciones;
	char typeApartment[51];
	int tipoDeVivienda;
	char localidad[51];
	char Searchlocalidad[51];
	int contLocalidad = 0;
	int contCASAS = 0;
	int contDEPARTAMENTO = 0;
	int legCen;

	UTN_getNumero(&opciones, "\n1)Elegir un tipo de vivienda y mostrar todos los datos de la vivienda, nombre del censista y datos de catastro del tipo seleccionado."
								"\n2)Elegir una Localidad y mostrar todos los datos de la vivienda y nombre del censista de la Localidad seleccionada"
								"\n3)Cantidad de viviendas censadas en la localidad de Avellaneda"
								"\n4)Elegir un censista y mostrar todas las viviendas que censó con los datos de catastro."
								"\n5)Cantidad de viviendas de tipo “casa” censadas."
								"\n6)Cantidad de viviendas de tipo “departamento” de la localidad de Lanús."
								"\n7)SALIR"
								"\nELIGA UNA OPCION: ", "\n ERROR AL ELEGIR UNA OPCION",1,7,10);

	switch(opciones){
		case 1:

			UTN_getNumeroRange(&tipoDeVivienda,"\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO| \nELIGA TIPO DE VIVIENDA: ","\nERROR AL ELEGIR EL TIPO DE VIVIENDA",1,4,5);

			for(int i = 0; i <= tam; i++){
				if(ListaVIVIENDAS[i].id <= idcomprobar && ListaVIVIENDAS[i].id >= idcomprobar){
					if(ListaVIVIENDAS[i].typeApartment == tipoDeVivienda){

						if(ListaVIVIENDAS[i].typeApartment == 1){
							strcpy(typeApartment , "CASA");
						}else {
							if(ListaVIVIENDAS[i].typeApartment == 2){
								strcpy(typeApartment , "DEPARTAMENTO");
							}else {
								if(ListaVIVIENDAS[i].typeApartment == 3){
									strcpy(typeApartment , "CASILLA");
								}else {
									if(ListaVIVIENDAS[i].typeApartment == 4){
										strcpy(typeApartment , "RANCHO");
									}
								}
							}
						}
						printf("\n|==========================================================================================|");
						printf("\n| %5d | %5s | %5d | %5d | %5s | %5d || %5s || %5d | %5s | %5s | %5s |", ListaVIVIENDAS[i].id,ListaVIVIENDAS[i].street ,ListaVIVIENDAS[i].cantPersons,ListaVIVIENDAS[i].cantRooms
								,typeApartment,ListaVIVIENDAS[i].legCen, ListaCENSISTAS[i].nombre, ListaCATASTROS[i].idCatastro, ListaCATASTROS[i].localidad
								, ListaCATASTROS[i].manzana, ListaCATASTROS[i].parcela);
						printf("\n|==========================================================================================|");
					}
				}
			}

			break;
		case 2:
			UTN_getAlfaNum(localidad, 51,"\n INGRESE LA LOCALIDAD EN DONDE VIVE: ","\n ERROR AL INGRESAR LA LOCALIDAD",5);
			for(int i = 0; i <= tam; i++){
					strcpy(Searchlocalidad, localidad);
					if(strcmp(ListaCATASTROS[i].localidad,Searchlocalidad) == 0){

						if(ListaVIVIENDAS[i].typeApartment == 1){
							strcpy(typeApartment , "CASA");
						}else {
							if(ListaVIVIENDAS[i].typeApartment == 2){
								strcpy(typeApartment , "DEPARTAMENTO");
							}else {
								if(ListaVIVIENDAS[i].typeApartment == 3){
									strcpy(typeApartment , "CASILLA");
								}else {
									if(ListaVIVIENDAS[i].typeApartment == 4){
										strcpy(typeApartment , "RANCHO");
									}
								}
							}
						}
						printf("\n|==========================================================================================|");
						printf("\n| %d | %s | %d | %d | %s | %d || %s || %d | %s      | %s | %s |", ListaVIVIENDAS[i].id,ListaVIVIENDAS[i].street ,ListaVIVIENDAS[i].cantPersons,ListaVIVIENDAS[i].cantRooms
								,typeApartment,ListaVIVIENDAS[i].legCen, ListaCENSISTAS[i].nombre, ListaCATASTROS[i].idCatastro, ListaCATASTROS[i].localidad
								, ListaCATASTROS[i].manzana, ListaCATASTROS[i].parcela);
						printf("\n|==========================================================================================|");
					}
			}
			break;
		case 3:
			UTN_getAlfaNum(localidad, 51,"\n INGRESE LA LOCALIDAD EN DONDE VIVE: ","\n ERROR AL INGRESAR LA LOCALIDAD",5);
			for(int i = 0; i <= tam; i++){
					if(strcmp(localidad,"AVELLANEDA") == 0 || strcmp(localidad,"avellaneda") == 0){
						if(strcmp(ListaCATASTROS[i].localidad,localidad) == 0){
							contLocalidad++;
						}
					}
			}
			printf("La cantidad viviendad censadas en Avellaneda son : %d" ,contLocalidad);
			break;
		case 4:
			UTN_getNumero(&legCen,"\n-INGRESE UN LEGAJO (LEGAJO CENSISTA): ","\nERROR AL INGRESAR EL NUMERO DEL LEGAJO",1,1000000,5);
			for(int i = 0; i <= tam; i++){
					if(ListaCENSISTAS[i].legajoCensista == legCen){
						if(ListaVIVIENDAS[i].typeApartment == 1){
							strcpy(typeApartment , "CASA");
						}else {
							if(ListaVIVIENDAS[i].typeApartment == 2){
								strcpy(typeApartment , "DEPARTAMENTO");
							}else {
								if(ListaVIVIENDAS[i].typeApartment == 3){
									strcpy(typeApartment , "CASILLA");
								}else {
									if(ListaVIVIENDAS[i].typeApartment == 4){
										strcpy(typeApartment , "RANCHO");
									}
								}
							}
						}
						printf("\n|==========================================================================================|");
						printf("\n| %d | %s | %d | %d | %s | %d || %d | %s      | %s | %s |", ListaVIVIENDAS[i].id,ListaVIVIENDAS[i].street ,ListaVIVIENDAS[i].cantPersons,ListaVIVIENDAS[i].cantRooms
									,typeApartment,ListaVIVIENDAS[i].legCen, ListaCATASTROS[i].idCatastro, ListaCATASTROS[i].localidad
									, ListaCATASTROS[i].manzana, ListaCATASTROS[i].parcela);
						printf("\n|==========================================================================================|");
					}
			}
			break;
		case 5:
			for(int i = 0; i <= tam ; i++){
				if(ListaVIVIENDAS[i].id <= idcomprobar && ListaVIVIENDAS[i].id >= idcomprobar){
					if(ListaVIVIENDAS[i].typeApartment == 1){
						contCASAS++;
					}
				}
			}
			printf("\n|==========================================================================================|");
			printf("La cantidad de casas censadas son : %d" ,contCASAS);
			printf("\n|==========================================================================================|");
			break;
		case 6:
			for(int i = 0; i <= tam ; i++){
				if(ListaVIVIENDAS[i].id <= idcomprobar && ListaVIVIENDAS[i].id >= idcomprobar){
					if(ListaVIVIENDAS[i].typeApartment == 2){
						contDEPARTAMENTO++;
					}
				}
			}
			printf("\n|==========================================================================================|");
			printf("La cantidad de departamentos censados son : %d" ,contDEPARTAMENTO);
			printf("\n|==========================================================================================|");
			break;
		default:
			break;
	}

	return 0;
}
