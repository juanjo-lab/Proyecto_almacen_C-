/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Juan José Martinez Cámara
 *
 * Created diciembre de 2018
 */

#include "funciones.h"


/*este es el fichero principal donde encontramos la lista de empleados con el tama�o maximo 
numero de empleados y luego ejecutaremos un bucle do while hasta que salgamos del programa
 * 
 */
int main(int argc, char** argv) {

    empleado listEmp[TAM];
    int nEmp=0;//Numero de empleados
    int opcion;
    rellenar(listEmp,&nEmp);
    do{//switch case que se ejecuta hasta que se cumpla la condicion de while de mientras ejecutara diferentes funciones
        opcion=menu();// menu es el que elige la opcion que queremos ejecutar es una funcion en funciones.c
    
        switch(opcion){//recibe como parametro un int y para cada valor ejecutara una funcion
            case 1:  printf("1.-  Alta empleado\n");
            altaEmpleado(listEmp,&nEmp);   
            break;
            case 2:  printf("2.-  Eliminar un empleado \n");
            eliminarEmp(listEmp,&nEmp);   
            break;
            case 3:  printf("3.-  Modificar dato de un empleado\n"); 
             modificarEmp(listEmp);  
            break;
            case 4:  printf("4.-  Listado proyecto de un empleado \n");
            listadoproy(listEmp);
            break;
            case 5:  printf("5.-  Alta proyecto para un empleado\n");   
               numeroproyimp(listEmp);
            break;
            case 6:  printf("6.-  Eliminar proyecto de un empleado\n");   
               eliminarproy(listEmp);
            break;
            case 7:  printf("7.-  Lista todos los empleados\n");   
            listadoempleados(listEmp,&nEmp);   
            break;
            case 8:  printf("8.-  Guardar en fichero\n");
            Guardarfichero(listEmp,&nEmp);
               break;
            case 9:  printf("9.-  Cargar de fichero\n");
            Cargarfichero(listEmp,&nEmp);
               break;
            case 10: printf("10.-  Salir\n");
               break; 
            default: printf("Has introducido una opcion incorrecta\n");
        }//fin del switch
    }while(opcion!=10);
    
    return (EXIT_SUCCESS);
}

