/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.h"
// primera funcion
int menu(){
    int op;
  printf("\n 1.- Alta empleado.\n");
  printf("2.- Eliminar un empleado.\n");
  printf("3.- Modificar datos de un empleado.\n");
  printf("4.- Listado proyectos de un empleado.\n");
  printf("5.- Alta proyecto para un empleado.\n");
  printf("6.- Eliminar proyecto de un empleado\n");
  printf("7.- Listar todos los empleados.\n");
  printf("8.- Guardar en fichero.\n");
  printf("9.- Cargar de fichero.\n");
  printf("10.- Salir.\n");
  printf("Opcion: \n");
  scanf("%i",&op);
  return op;
}

void rellenar(empleado listEmp [TAM],int *n){
    strcpy(listEmp[*n].identificativo,"1");
    strcpy(listEmp[*n].nombre,"Fernando");
    strcpy(listEmp[*n].apellidos,"mc");
    listEmp[*n].anyo = 334567;
    listEmp[*n].edad = 23;
    listEmp[*n].nproy = 0;
    
    (*n)++;
    
    strcpy(listEmp[*n].identificativo,"2");
    strcpy(listEmp[*n].nombre,"Paco");
    strcpy(listEmp[*n].apellidos,"merlas");
    listEmp[*n].anyo = 111111;
    listEmp[*n].edad = 11;
    listEmp[*n].nproy = 1;
    strcpy(listEmp[*n].listaProy[0].nombre,"Barrer");
    listEmp[*n].listaProy[0].presupuesto = 33000;
    
    (*n)++;
}



/*PUNTO 1 DAR EL ALTA A UN EMPLEADO*/


void altaEmpleado( empleado listEmp [TAM],int *n){
    /* para hacer este procedimiento vamos a preguntar algun dato el cual nos
     permita viajar a traves de un for hasta el empleado deseado para darle el
     alta*/
    int i,c,j;
    printf("Introduce el dni del empleado=\n");
    getchar();
    gets(listEmp[*n].identificativo);
    /*usamos gets para leer string por teclado y scanf para todo lo que no sea string o char*/
   
    printf("Introduce el nombre del empleado=\n");
    
    gets(listEmp[*n].nombre);
    
    printf("Introduce los apellidos del empleado = \n");
   
    gets(listEmp[*n].apellidos);
    
    printf("Introduce el anyo del empleado = \n");
    scanf("%i",&listEmp[*n].anyo);
    
    printf("Introduce la edad del empleado = \n");
    scanf("%i",&listEmp[*n].edad);
    
    printf("numero de proyectos implicado = \n");
    scanf("%i",&listEmp[(*n)].nproy);
    c=listEmp[(*n)].nproy;
    for(i=0;i<c;i++){
       
        printf("Dime el nombre del proyecto = \n");
        getchar();
        gets(listEmp[*n].listaProy[i].nombre);
        printf("Dime el presupuesto = \n");
        scanf("%f",&listEmp[*n].listaProy[i].presupuesto);
        
    }
(*n)++;
}

/* PUNTO 2 ELIMINAR EMPLEADO DESEADO*/

void eliminarEmp(empleado listEmp[TAM],int *n){
    /*Para eliminar un empleado vamos a declarar unas cuantas variables y 
     despues vamos a preguntar que empleado deseamos eliminar, buscamos
     el empleado con un for y lo hacemos 0 y para que no se quede una casilla
     con todo 0 todos los empleados que se encuentren por encima del mismo
     los vamos a mover una casilla para que no queden huecos*/
    char m[10];
    int i,c,j;
    
   do{
        printf("Introduce el DNI del empleado que desea eliminar =\n ");
        getchar();
        gets(m);
 
        c=-76;/*igualamos c a un numero negativo . Si al comparar con otro empleado es que hemos encontrado si no cambia no lo hemos encontrado */
 
        for(i=0;i<(*n);i++){
            strcmp(m, listEmp[i].identificativo);
            if(strcmp(m, listEmp[i].identificativo)==0)
                c=i;
        }
        
        
        if(c != -76){
            for(i=c; i<((*n)-1); i++){
                /*  strcpy es para copiar desde char o string */
                strcpy(listEmp[i].identificativo,listEmp[i+1].identificativo);

                strcpy(listEmp[i].nombre,listEmp[i+1].nombre);
                strcpy(listEmp[i].apellidos,listEmp[i+1].apellidos);
                
                /*como solamente son enteros podemos simplemente igualarlos para copiarlos
                 sabiendo que se copia de derecha a izquierda*/

                listEmp[i].anyo = listEmp[i+1].anyo;
                listEmp[i].edad=listEmp[i+1].edad;
                listEmp[i].nproy=listEmp[i+1].nproy;

                for (int j = 0; j < listEmp[i].nproy; j++) {
                    strcpy(listEmp[i].listaProy[i].nombre, listEmp[i + 1].listaProy[i].nombre);
                    listEmp[i].listaProy[i].presupuesto=  listEmp[i+1].listaProy[i].presupuesto;
                }
            }

            (*n)--;
        }
    }while(c==-76);
       
  
 }
 

/*PUNTO 3 MODIFICAR DATOS DE UN EMPLEADO*/
void modificarEmp(empleado listEmp[TAM]){
    
    /* Para poder modificar un empleado primero preguntamos que empleado 
     deseamos modificar y despues procedemos a superponer la informacion
      al mismo y lo volvemos a rellenar preguntando todos los datos 
     necesarios */
    int empleado,c,i;
    
    
    printf("introduce el  empleado a modificar = \n");
    scanf("%i",&empleado);
    
    //En el lenguaje cotidiano usamos el empleado 1 pero en el ordenador se entendera como el 0
    empleado--;
    
    printf("Introduce el dni nuevo del empleado =\n");
    getchar();
    gets(listEmp[empleado].identificativo);
    /*usamos gets para leer string por teclado*/
    printf("nombre del empleado a modificar =\n");
    gets(listEmp[empleado].nombre);
    printf("apellidos del empleado a modificar = \n");
    gets(listEmp[empleado].apellidos);
    
    printf("introduce el anyo del empleado = \n");
    scanf("%i",&listEmp[empleado].anyo);
    printf("introduce la edad del empleado= \n");
    scanf("%i",&listEmp[empleado].edad);
    printf("introduce el numero de proyectos en los que trabaja el empleado =\n");
    scanf("%i",&listEmp[empleado].nproy);
    
    c=listEmp[empleado].nproy;
    
    for(i=0;i<c;i++){
        printf("Dime el nombre del proyecto = \n");
        getchar();
        gets(listEmp[empleado].listaProy[i].nombre);
        printf("Dime el presupuesto = \n");
        scanf("%f",&listEmp[empleado].listaProy[i].presupuesto);
    }
}

/*PUNTO 4 IMPRIMIR LISTADO DE PROYECTOS*/

void listadoproy(empleado listEmp[TAM]){
    /* Para hacer este punto que es imprimir el listado de proyectos en el 
     cual participa un empleado vamos a preguntar primero que empleado es
     y despues vamos a usar un for que vaya recorriendo las casillas e 
     imprimiendo el nombre del proyecto y su presupuesto*/
    int i,empleado;
    printf("Â¿De quien desea usted imprimir el listado de proyectos (introduzca "
            "el empleado)? \n ;");
    scanf("%i",&empleado);
    empleado--;
    for(i=0;i<listEmp[empleado].nproy;i++){
        printf("el nombre del proyecto y su presupuesto son : %s , %f $\n"
                ,listEmp[empleado].listaProy[i].nombre
                ,listEmp[empleado].listaProy[i].presupuesto);
    }
    }


/* PUNTO 5 PARA DAR DE ALTA EN UN PROYECTO*/

void numeroproyimp(empleado listEmp[TAM]){
    /*vamos a dar de alta a un empleado en un proyecto para ello necesitamos
     saber de quien se trata y el nombre del proyecto */
    int empleado,p;
    printf("introduce el numero del empleado = \n");
    scanf("%i",&empleado);
    empleado--;
    
    p=listEmp[empleado].nproy;
    if(p<10){

        printf("dime el nombre del proyecto = \n");
        getchar();
        gets(listEmp[empleado].listaProy[p].nombre);

        printf("dime el presupuesto del proyecto = \n");
        scanf("%f",&listEmp[empleado].listaProy[p].presupuesto);
        
        listEmp[empleado].nproy++;
    }
    else printf("el empleado que quieres incluir ya tiene asignado mas de 10 proyectos.\n");
}

/*PUNTO 6 ELIMINAR PROYECTO DE UN EMPLEADO*/

void eliminarproy(empleado listEmp[TAM]){
    int empleado,p,numero,i;
    printf("introduce el numero del empleado\n");
    scanf("%i",&empleado);
    empleado--;
    
    printf("¿que numero del proyecto desea eliminar?\n");
    scanf("%i",&numero);
    numero--;
     
    for (i = numero; i < listEmp[empleado].nproy; i++) {
                   strcpy(listEmp[empleado].listaProy[i].nombre,
                           listEmp[empleado].listaProy[i+1].nombre);
                   listEmp[empleado].listaProy[i].presupuesto=
                           listEmp[empleado].listaProy[i+1].presupuesto;
    }
    listEmp[empleado].nproy--;
 }

/* PUNTO 7 IMPRIMIR TODO EL LISTADO DE EMPLEADOS*/
 
  
void listadoempleados(empleado listEmp[TAM],int *n){
    int i,empleado,j;
    char m[10];//declaramos array de 10 elementos
    printf("el listado de empleados es = \n");
    
   for(i=0;i<(*n);i++){   
        printf("numero identidicativo = %s\n",listEmp[i].identificativo);
        printf("su nombre es = %s\n",listEmp[i].nombre);
        printf("su apellido es =%s\n",listEmp[i].apellidos);
        printf(" el anio es =%i\n",listEmp[i].anyo);
        printf("la edad del empleado es =%i\n",listEmp[i].edad);
        printf("trabaja en %i proyectos\n",listEmp[i].nproy);
    for (int j = 0; j < listEmp[i].nproy; j++) {
                   printf("el nombre del proyecto es %s \n",&listEmp[i].listaProy[j].nombre);
                   printf("su presupuesto es de %f $\n",listEmp[i].listaProy[j].presupuesto);
               }
    }
}

/*PUNTO 8 GUARDAR EN FICHERO LOS CAMBIOS*/

void Guardarfichero(empleado listEmp[TAM],int *n){
    int i,j;
    FILE * flujo = fopen("empleado.txt", "w");//declaramos un flujo abrimos un flujo que sera el encargado de escribir en el fichero empleados.txt y la w es para sobre escribir
    for(i =0; i < *n; i++){
        /*recorremos el array de empleados y imprimimos cada uno de sus 
         atributos*/
        fprintf(flujo, "DNI = %s\n",listEmp[i].identificativo);//funcion usada para escribir desde fichero
        fprintf(flujo, "NOMBRE = %s\n",listEmp[i].nombre);
        fprintf(flujo, "APELLIDOS = %s\n",listEmp[i].apellidos);
        fprintf(flujo, "ANYO = %i\n",listEmp[i].anyo);
        fprintf(flujo, "EDAD = %i\n",listEmp[i].edad);
        fprintf(flujo, "NUMERO DE PROYECTOS IMPLICADO = %i\n",listEmp[i].nproy);
        
        for (j = 0; j < listEmp[i].nproy; j++) {
                fprintf(flujo, "NOMBRE DEL PROYECTO = %s\n",listEmp[i].listaProy[j].nombre);
                fprintf(flujo, "PRESUPUESTO USADO EN EL PROYECTO = %f\n",listEmp[i].listaProy[j].presupuesto);
        }
    }
}
    
    
    
    /*PUNTO 9 CARGAR DESDE FICHERO*/

void Cargarfichero(empleado listEmp[TAM],int *n){
    FILE *fd;
    /* vamos a cargar un archivo txt y con la funcion fgetc, leer todo el 
      contenido*/
    printf("Cargando fichero...\n");
    int c;
    char direccion[]="empleado.txt";
    fd= fopen(direccion,"rt");/* leer archivo rt*/  
    if(fd == NULL){
        printf("Hay un error con el archivo\n");
    
}
    /* si no entra en el if significa que lo ha leido y voy a poner ahora  un
     bucle while y vamos a poner que va a ser igual a fgetc*/
    while((c=fgetc(fd))!=EOF){
        if(c=='\n'){
            printf("\n");
        }
        else{
            /* sirve para imprimir un char*/
            putchar(c);
        }
    }
}
