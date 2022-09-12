/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: linpc
 *typedef (declaracion) (empleado) es darle nombres a los tipos 
 * 
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 500
#define NPROY 10
//definimos estructura de proyecto y empleado

typedef struct proyecto{
    char nombre [60];
    float presupuesto;
    
}proyecto;

typedef struct empleado{
    char identificativo[10];
    char nombre [30];
    char apellidos[50];
    int anyo;
    int edad;
    int nproy;
    proyecto listaProy[NPROY];
}listEmp[TAM];


void rellenar(empleado listEmp [TAM],int *n);

//cabecera
int menu();
void altaEmpleado( empleado listEmp [TAM],int *n);
void eliminarEmp(empleado listEmp[TAM],int *n);
void modificarEmp(empleado listEmp[TAM]);
void listadoproy(empleado listEmp[TAM]);
void numeroproyimp(empleado listEmp[TAM]);
void eliminarproy(empleado listEmp[TAM]);
void listadoempleados(empleado listEmp[TAM],int *n);
void Guardarfichero(empleado listEmp[TAM],int *n);
void Cargarfichero(empleado listEmp[TAM],int *n);
#endif /* FUNCIONES_H */

