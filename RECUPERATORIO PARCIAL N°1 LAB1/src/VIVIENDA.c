/*
 * VIVIENDA.c
 *
 *  Created on: 23 jun. 2022
 *      Author: ignac
 */

#include "VIVIENDA.h"

static int idGenerate = 20000;

static int idGenerateCATASTRO = 0;

int generateId(){

	idGenerate++;

	return idGenerate;
}

int generateId2(){

	idGenerateCATASTRO++;

	return idGenerateCATASTRO;
}

int init(VIVIENDAS ListaVIVIENDAS[], CATASTROS ListaCATASTROS[],int tamArray){

	for(int i = 0; i <= tamArray; i++){
		ListaVIVIENDAS[i].id = 0;
		ListaVIVIENDAS[i].legCen = 0;
		ListaVIVIENDAS[i].cantPersons = 0;
		ListaVIVIENDAS[i].cantRooms = 0;
		strcpy(ListaVIVIENDAS[i].street, "");
		ListaVIVIENDAS[i].typeApartment = 0;
		ListaCATASTROS[i].idCatastro = 0;
		strcpy(ListaCATASTROS[i].localidad,"");
		strcpy(ListaCATASTROS[i].manzana,"");
		strcpy(ListaCATASTROS[i].parcela,"");
	}

	return 0;
}

int AddNewVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tamArray, char addstreet[], int addCantPersons, int addCantRooms, int addTypeApartment, int addLegCen){

	ListaVIVIENDAS[tamArray].id = generateId();
	strcpy(ListaVIVIENDAS[tamArray].street,addstreet);
	ListaVIVIENDAS[tamArray].cantPersons = addCantPersons;
	ListaVIVIENDAS[tamArray].cantRooms = addCantRooms;
	ListaVIVIENDAS[tamArray].typeApartment = addTypeApartment;
	ListaVIVIENDAS[tamArray].legCen = addLegCen;

	return 0;
}

int CheckLEGAJO(VIVIENDAS ListaVIVIENDAS[], int tamArray, int checkLegCen){

	int retorno = 0;

	for(int i = 0; i <= tamArray; i++){
			if(ListaVIVIENDAS[i].legCen == checkLegCen){
				retorno = 1;
			} else {
				retorno = 0;
			}
	}


	return retorno;
}

int AddNewCATASTRO(CATASTROS ListaCATASTROS[], int tamArray, char localidad[], char manzana[], char parcela[]){

	ListaCATASTROS[tamArray].idCatastro = generateId2();
	strcpy(ListaCATASTROS[tamArray].localidad, localidad);
	strcpy(ListaCATASTROS[tamArray].manzana, manzana);
	strcpy(ListaCATASTROS[tamArray].parcela, parcela);

	return 0;
}

int ModVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tamArray, int searchID){


	VIVIENDAS auxVIVIENDAS;

	int opciones;

	char typeApartment[51];
	char newstreat[25];
	int newcantPersons;
	int newcantRooms;
	int newType;

	for(int i = 0; i <= tamArray; i++){
			if(ListaVIVIENDAS[i].id == searchID){
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

							printf("\n==================CENSO NACIONAL 2022 / VIVIENDA A MODIFICAR======================");
							printf("\nID: %d", ListaVIVIENDAS[i].id);
							printf("\nCALLE: %s", ListaVIVIENDAS[i].street);
							printf("\nCANT PERSONAS: %d", ListaVIVIENDAS[i].cantPersons);
							printf("\nCANT HABITACIONES: %d", ListaVIVIENDAS[i].cantRooms);
							printf("\nTIPO: %s", typeApartment);
							printf("\nLEGAJO: %d", ListaVIVIENDAS[i].legCen);

							UTN_getNumero(&opciones,"\n==================================================================================="
													"\n1) Cambiar datos de la calle"
													"\n2) Cambiar la cantidad de personas que viven"
													"\n3) Cambiar la cantidad de habitaciones que hay"
													"\n4) Cambiar el tipo de vivienda"
													"\n5) SALIR"
													"\nELIGA UNA OPCION: ","\nERROR...ELIGA UNA OPCION VALIDA",1,5,10);

							switch(opciones){
								case 1:
									UTN_getAlfaNum(newstreat,25,"\n-INGRESE NUEVA CALLE Y DIRECCION DE LA CASA: ","\nERROR AL INTRODUCIR CALLE O DIRECCION DE LA CASA", 5);

									strcpy(ListaVIVIENDAS[i].street,newstreat);

									break;
								case 2:

									UTN_getNumero(&newcantPersons,"\n-NUEVA CANTIDAD DE PERSONAS QUE VIVEN EN LA CASA: ","\nERROR AL INGRESAR LA CANTIDAD DE PERSONAS",1,10,5);

									ListaVIVIENDAS[i].cantPersons = newcantPersons;

									break;
								case 3:

									UTN_getNumero(&newcantRooms,"\n-NUEVA CANTIDAD DE HABITACIONES: ","\nERROR AL INGRESAR LA CANTIDAD DE HABITACIONES",1,10,5);

									ListaVIVIENDAS[i].cantRooms = newcantRooms;

									break;
								case 4:

									UTN_getNumeroRange(&newType,"\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO| \nELIGA SU TIPO DE VIVIENDA: ","\nERROR AL ELEGIR EL TIPO DE VIVIENDA",1,4,5);

									ListaVIVIENDAS[i].typeApartment = newType;

									break;
								default:
									return 0;
									break;
							}

							auxVIVIENDAS.id = ListaVIVIENDAS[i].id;
							strcpy(auxVIVIENDAS.street, ListaVIVIENDAS[i].street);
							auxVIVIENDAS.cantPersons = ListaVIVIENDAS[i].cantPersons;
							auxVIVIENDAS.cantRooms = ListaVIVIENDAS[i].cantRooms;
							auxVIVIENDAS.typeApartment = ListaVIVIENDAS[i].typeApartment;
							auxVIVIENDAS.legCen = ListaVIVIENDAS[i].legCen;

							ListaVIVIENDAS[i].id = auxVIVIENDAS.id;
							strcpy(ListaVIVIENDAS[i].street,auxVIVIENDAS.street);
							ListaVIVIENDAS[i].cantPersons = auxVIVIENDAS.cantPersons;
							ListaVIVIENDAS[i].cantRooms = auxVIVIENDAS.cantRooms;
							ListaVIVIENDAS[i].typeApartment = auxVIVIENDAS.typeApartment;
							ListaVIVIENDAS[i].legCen = auxVIVIENDAS.legCen;

					}
	}

	return 0;
}

int lowVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tamArray, int searchID){

	char opcion[51];

	for(int i = 0; i <= tamArray; i++){
			if(ListaVIVIENDAS[i].id == searchID){

				printf("\n==================CENSO NACIONAL 2022 / CONFIRMAR BAJA DE VIVIENDA======================");
				printf("\nDESEA BAJAR LA SIGUIENTE ID [%d] ? (ACEPTAR / CANCELAR): ", ListaVIVIENDAS[i].id);
				fflush(stdin);
				gets(opcion);
				if(strcmp(opcion,"ACEPTAR") == 0 || strcmp(opcion,"aceptar") == 0){
					ListaVIVIENDAS[i].id = 0;
					return 0;
				} else{
					if(strcmp(opcion,"CANCELAR") == 0 || strcmp(opcion,"cancelar") == 0){
						return 0;
					}
				}

			}
	}

	return 0;
}

int showListVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tamArray){

	char typeApartment[51];
	int anchoColumnaID = 10;
	int anchoColumnaCALLE = 10;
	int anchoColumnaPERSONAS = 10;
	int anchoColumnaHABITACIONES = 10;
	int anchoColumnaVIVIENDA = 10;
	int anchoColumnaLEGAJO = 10;

						printf("\n|============================CENSO NACIONAL 2022/ LISTA VIVIENDAS==========================|");
						printf("\n| %*s | %*s | %*s | %*s | %*s | %*s |",anchoColumnaID,"ID",anchoColumnaCALLE,"CALLE",anchoColumnaPERSONAS,"CANT PERSONAS",
								anchoColumnaHABITACIONES,"CANT HABITACIONES",anchoColumnaVIVIENDA,"TIPO VIVIENDA", anchoColumnaLEGAJO, "LEGAJO");
						printf("\n|==========================================================================================|");
		for(int i = 0; i <= tamArray; i++){
				if(ListaVIVIENDAS[i].typeApartment == 1){
					strcpy(typeApartment , "CASA");
				} else {
					if(ListaVIVIENDAS[i].typeApartment == 2){
						strcpy(typeApartment , "DEPARTAMENTO");
					} else {
						if(ListaVIVIENDAS[i].typeApartment == 3){
							strcpy(typeApartment , "CASILLA");
						}  else {
							if(ListaVIVIENDAS[i].typeApartment == 4){
								strcpy(typeApartment , "RANCHO");
							}
						}
					}
				}

				if(ListaVIVIENDAS[i].id != 0){
					printf("\n| %10d | %10s | %13d |%18d | %13s | %10d |", ListaVIVIENDAS[i].id,ListaVIVIENDAS[i].street ,ListaVIVIENDAS[i].cantPersons,ListaVIVIENDAS[i].cantRooms,typeApartment,ListaVIVIENDAS[i].legCen);
					printf("\n|==========================================================================================|");
				}
		}
	return 0;
}
