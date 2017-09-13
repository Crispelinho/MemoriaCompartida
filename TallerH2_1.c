#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
struct Datos{
    int idluz;
	double tiempo;
	int estado;
	int salir;
}ptr;

int sw;
int *mensaje;
int *time1;
int CHILOS=0;
void * funcion_hilo(void *arg){
	
	int ID = (int)arg;//Convierte el parametro de tipo void a int
	while(ptr.salir==1){
		if (sw==1)
		{
		  break;	
		}
	}
	while(ptr.salir==0||sw==1){

		while(ID!=ptr.idluz){}

			printf("\nCliente %d\n",ID);
			printf("Mi ID es %lu\n",pthread_self());
			printf("Ingrese en que estado quiere la luz (1)Encendido o (0)Apagado\n");
			scanf("%d",&ptr.estado);
			//mensaje[ptr.idluz]=ptr.estado;
			printf("Ingrese el tiempo:\n");
			scanf("%lf",&ptr.tiempo);
			//time1[ptr.idluz]=ptr.tiempo;
			sleep(ptr.tiempo);
			printf("Mi tiempo de ejecucion fue %lf \n",ptr.tiempo);
			printf("Mi estado es %d \n",ptr.estado);
			printf("Desea continuar (0) si desea salir(1):\n");
			scanf("%d",&ptr.salir);
			if (ptr.salir==0)
			{	
				printf("Ingrese la luz a modificar\n");
				scanf("%d",&ptr.idluz);	
			}
			else
			{
			  break;
    printf("Ingrese el numero de hilos:\n");
			}
	}
   	printf("Ingrese el numero de hilos:\n");
	pthread_exit(NULL);
	return NULL;
}

int main(){
    printf("Ingrese el numero de hilos:\n");
	scanf("%d",&CHILOS);
	//Inicializa el vector de hilos
	pthread_t hilos[CHILOS];
	ptr.salir=1;
	for (int j = 0; j < 50; j++){
		pthread_create(&hilos[j],NULL,funcion_hilo,(void *)j);
	}
	
	printf("Ingrese la luz a modificar\n");
	scanf("%d",&ptr.idluz);	
	sw=1;

	for (int i = 0; i < CHILOS; i++){
		pthread_join(hilos[i],NULL);
	}
	
	return 0;
}
