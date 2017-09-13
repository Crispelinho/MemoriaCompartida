/*
	Juan David Rodriguez Cervantes
	2013114113
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

struct Datos{
	int compuerta;
	char *estado;
	int tiempo;
	int salir;
}ptr;

int n;


void * f(void *arg){
	
	int r = *(int*)arg;//Convierte el parametro de tipo void a int
	int i,j,k,a;
	while(r==ptr.compuerta){  //diagonal superior
		
		printf("Soy la compuerta %d\n\n",r);
		printf("Ingrese en que estado quiere la compuerta (A)Abierto o (C)Cerrado\n");
		scanf("%s",&ptr.estado);
		printf("Ingrese el tiempo:\n");
		scanf("%d",&ptr.tiempo);
		sleep(ptr.tiempo);
		ptr.salir=0;
		break;
	}
	
	return NULL;
}



int main(){
	
	printf("Ingrese el numero de hilos:\n");
	scanf("%d",&n);
	pthread_t *h;
	int i,j;
	ptr.salir=0;
	//Inicializa el vector de hilos
	h = (pthread_t*)malloc(sizeof(pthread_t)*3);
	

	while(ptr.salir==0){
		printf("Digite la compuerta que desea modificar:\n");
		scanf("%d",&ptr.compuerta);
		if(ptr.compuerta<=n){
			for(i=0;i<n;i++ ){
				int *var = (int*)malloc(sizeof(int));
				*var = i;
				pthread_create(&h[i],NULL,f,(void*)var);
			}
			
			for(i=0;i<n;i++ ){
				pthread_join(h[i],NULL);
			}
			printf("Desea continuar (0) si desea salir(1):\n");
			scanf("%d",&ptr.salir);
		}
	}
	printf("Soy la compuerta %d",ptr.compuerta);
	printf(" mi tiempo de ejecucion fue %d",ptr.tiempo);
	printf(" mi estado es %c",ptr.estado);
	
	return 0;
}