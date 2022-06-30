/*
 * CENSISTA.h
 *
 *  Created on: 21 may. 2022
 *      Author: ignac
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <windows.h>
#include "input-UTN.h"

struct{
	int legajoCensista;
	char nombre[51];
	int edad;
	int telefono;
}typedef CENSISTAS;


int init2(CENSISTAS ListaCENSISTAS[],int tamArray);

int AddNewCENSISTA(CENSISTAS ListaCENSISTAS[],int tamArray,int addLegajoCensista, char addNombre[], int addEdad, int addTelefono);

int showListCENSISTA(CENSISTAS ListaCENSISTAS[], int tamArray);

#endif /* CENSISTA_H_ */
