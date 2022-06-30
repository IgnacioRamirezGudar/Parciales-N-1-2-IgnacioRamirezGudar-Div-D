/*
 * CENSISTA.c
 *
 *  Created on: 23 jun. 2022
 *      Author: ignac
 */

#include "CENSISTA.h"


int init2(CENSISTAS ListaCENSISTAS[],int tamArray){

	for(int i = 0; i <= tamArray; i++){
		ListaCENSISTAS[i].edad = 0;
		ListaCENSISTAS[i].legajoCensista = 0;
		ListaCENSISTAS[i].telefono = 0;
		strcpy(ListaCENSISTAS[i].nombre, "");
	}

	return 0;
}

int AddNewCENSISTA(CENSISTAS ListaCENSISTAS[],int tamArray,int addLegajoCensista, char addNombre[], int addEdad, int addTelefono){

	ListaCENSISTAS[tamArray].legajoCensista = addLegajoCensista;
	strcpy(ListaCENSISTAS[tamArray].nombre,addNombre);
	ListaCENSISTAS[tamArray].edad = addEdad;
	ListaCENSISTAS[tamArray].telefono = addTelefono;

	return 0;
}

int showListCENSISTA(CENSISTAS ListaCENSISTAS[], int tamArray){

	for(int i = 0; i < tamArray; i++){
		if(ListaCENSISTAS[i].legajoCensista != 0 ){
			printf("\n|===================LISTA CENSISTAS=====================|");
			printf("\n|LEGAJO: %5d|NOMBRE: %5s|EDAD: %5d|TELEFONO: %5d|", ListaCENSISTAS[i].legajoCensista,ListaCENSISTAS[i].nombre ,ListaCENSISTAS[i].edad,ListaCENSISTAS[i].telefono);
			printf("\n|=======================================================|");
		}
	}
	return 0;
}
