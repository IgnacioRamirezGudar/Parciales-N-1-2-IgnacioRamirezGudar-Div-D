/*
 * VIVIENDA.h
 *
 *  Created on: 23 jun. 2022
 *      Author: ignac
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "input-UTN.h"

struct{
	int id;
	char street[25];
	int cantPersons;
	int cantRooms;
	int typeApartment;
	int legCen;
}typedef VIVIENDAS;

struct{
	int idCatastro;
	char localidad[51];
	char manzana[25];
	char parcela[25];
}typedef CATASTROS;


int init(VIVIENDAS ListaVIVIENDAS[],CATASTROS ListaCATASTROS[], int tamArray);

int AddNewVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tamArray, char addstreet[], int addCantPersons, int addCantRooms, int addTypeApartment, int addLegCen);

int CheckLEGAJO(VIVIENDAS ListaVIVIENDAS[], int tamArray, int checkLegCen);

int AddNewCATASTRO(CATASTROS ListaCATASTROS[], int tamArray, char localidad[], char manzana[], char parcela[]);

int ModVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tamArray, int searchID);

int lowVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tamArray, int searchID);

int showListVIVIENDA(VIVIENDAS ListaVIVIENDAS[], int tamArray);

#endif /* VIVIENDA_H_ */
