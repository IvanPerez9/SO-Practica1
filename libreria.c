#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** SacarLongitud ( char ** lista , char * buff , int N); // Cabecera necesaria. Declaracion implicita 

int head(int N){

	char buff[1024];
	int contador = 0;

	while((contador<N) && (fgets(buff,1024,stdin)!= NULL)){
		printf("%s" , buff);
		contador++;
	}

	return 0;

}

int tail (int N){

	char buff[1024]; // Almacen temporal
	char ** pila ; // Pila resultante, de mayor a menor ordenada 
	int i;
	int pos=0;
	int imprimir;
	int aux=0;
	int indice;

	// Reservar memoria dinámica. Usar malloc

	pila = (char **) malloc (N*sizeof(char*)); // El array que crea es de 10 en el peor caso, por lo que miro lineas mas grandes al mismo tiempo 
	for(i=0; i<N ; i++){
		pila[i] = (char *) malloc (1024*sizeof(char));  // Reservo N espacios con tamaño 1024 en cada  ;
	}

	// Comprobar que se ha creado bien la memoria dinámica

	if(pila == NULL){
		fprintf(stderr, "El malloc ha fallado");
		return 1;
	}

	// Recorrer el archivo hasta el final.

	while(fgets(buff , 1024 , stdin) != NULL){     	     // Mientras que no sea EOF, recorro	
		if(strlen(buff)>strlen(pila[0])){
			while((pos<N) && (strlen(buff)>strlen(pila[pos]))){  // Emepezar en la posicion 0. Numero de veces que hay que imprimir 
				pos++;
			}
		}
		if(pos >0){				// Si ha metido un numero superior a 0
			indice = 0;
			while(indice<N-1){		// Deja espacio en la pila, moviendo todo. Le voy la vuelta a la pila ayudandome de buff.  
				strcpy(pila[indice],pila[indice+1]); // Hace que imprima tantos como N indicados 
				indice++;
			}
			strcpy(pila[pos-1],buff);	// Copia lo que habia en buff a la pila , le da la vuelta.
		}
	}


	//Resultado de la cadena.
	
	for(imprimir=0; imprimir<pos; imprimir++){
		printf("%s" , pila[imprimir]);
	}

	//Liberar espacio. De cada uno de los elementos y de la pila en general 

	while(aux < N){
		free(pila[aux]);
		aux++;
	}
	free(pila);
	return 0;
}

int longlines (int N){

	char buff[1024];
	char listaAux[1024];
	char ** lista;
	int j,i,aux,t;

	// Inicio la memoria dinamica

	lista = (char **) malloc (N*sizeof(char*));
	for(i=0; i<N ; i++){
		lista[i] = malloc (1024*sizeof(char));
		
	}

	// Comprobar que no da error 

	if(lista == NULL){
		fprintf(stderr,"El malloc ha fallado");
		return 1;
	}

	// Recorro la entrada estandar, guardo en la lista 	

	while(fgets(buff,1024,stdin) != NULL){ // Mientras no sea EOF meteme en buff lo que vaya llegando de stdin
		for(aux=0; aux<N; aux++){
			if(strlen(lista[aux]) < strlen(buff)){  // Longitud de la lista es menor que longitud en buff, entonces hago auxiliar y cambio
				strcpy(listaAux,lista[aux]);
				strcpy(lista[aux] , buff);
				strcpy(buff , listaAux);
			}
		}
	}

	// Imprimir 

	for(j=0; j<N ; j++){
		if(strcmp(lista[j],"")){
			printf("%s", lista[j]);
		}	
	}

	// Liberar memoria, de la lista y de cada elemento

	for(t=0; t<N; t++){
		free(lista[t]);
	}

	free(lista);

	return 0;	
}









