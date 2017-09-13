//Segundo parcial Sistemas Operativos
//Cristhian Carpio 2016214160

#include <stdlib.h>
#include <sys/types.h>
#include <wait.h> 
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <sys/shm.h>
//write(fd[1], "algun mensaje\n", 14);
//n = read(fd[0], buff, 50);
//pid_t getpid();
//pid_t getppid();

typedef struct ban
{
	int turno;
}ban;

int main() {
	printf("Iniciando...\n");
	int shm_id;
	int shm_size = sizeof(struct ban);
	ban *ptr;
    shm_id = shmget(IPC_PRIVATE, shm_size,IPC_CREAT|0600);
    ptr = shmat(shm_id,0,0);

	int n=4;
	pid_t hijo[n];
	pid_t hijosub1;
	pid_t hijosub2;
	int i=0;
	int bandera=1;
	ptr->turno=1;

	printf("Bandera= %d\n", bandera);
	printf("ptr->turno= %d\n", ptr->turno);
	printf("\n");
	printf("\n");
	for(i=0;i<4;i++)
	{
		hijo[i]=fork();
		if(hijo[i]==0)//Soy hijo
		{
		 if (i==1)//Soy hijo2
		 {
		   hijosub1=fork();	
		   if (hijosub1==0)//Soy subhijo1
		   { 		
		   		while(ptr->turno!=3);
		   		printf("\n");
		   		printf("Soy el Hijo %d.1 [%d] -> Mi Padre es [%d]\n", i, getpid(), getppid());
		   		ptr->turno++;
		   		printf("Bandera= %d \n", ptr->turno);
				printf("\n");
      			shmdt(ptr);
		   	break;
		   }
		   else
		   {	printf("Bandera= %d\n", ptr->turno);
		   			
		   		while(ptr->turno!=2);
		   		printf("\n");
		   		printf("Soy el Hijo %d [%d] -> Mi Padre es [%d]\n", i, getpid(), getppid());
		   		ptr->turno++;
		   		printf("Bandera= %d \n", ptr->turno);
		   		printf("\n");
		   		shmdt(ptr);
		   } 
		 }

	     if (i==2)//Soy hijo3
		 {
		   hijosub2=fork();
		   if (hijosub2==0)//Soy subhijo1
		   {		
		   		while(ptr->turno!=7);
		   		printf("\n");
		   		printf("Soy el Hijo %d.1 [%d] -> Mi Padre es [%d]\n", i, getpid(), getppid());
				ptr->turno++;
				printf("Bandera= %d \n", ptr->turno);
				printf("\n");
				shmdt(ptr);
				break;
		   }
		   else
		   {		
		   	 	while(ptr->turno!=6);
		   	 	printf("\n");
		   		printf("Soy el Hijo %d [%d] -> Mi Padre es [%d]\n", i, getpid(), getppid());
		   		ptr->turno++;
		   		printf("Bandera= %d \n", ptr->turno);
		   		printf("\n");
		   		shmdt(ptr);
		   }	
		 }
		 if (i==0)
		 {		
		 		while(ptr->turno!=4);
		 		printf("\n");
		 	    printf("Soy el Hijo %d [%d] -> Mi Padre es [%d]\n", i, getpid(), getppid());
		 	    ptr->turno++;
		 	    printf("Bandera= %d \n", ptr->turno);
		 	    printf("\n");
		 	    shmdt(ptr);
		 }
		 if (i==3)
		 {	
		
		 		while(ptr->turno!=8);
		 		printf("\n");
		 	    printf("Soy el Hijo %d [%d] -> Mi Padre es [%d]\n", i, getpid(), getppid());
		 	    ptr->turno++;
		 	    printf("Bandera= %d \n", ptr->turno);
		 	    printf("\n");
		 	    shmdt(ptr);
		 }
		 break;
		}

	}

	if(i==4)
	{
			
			   printf("Bandera= %d\n", ptr->turno);
			   while(ptr->turno!=1){
			   	printf("Bandera= %d\n", ptr->turno);
		  		 }

			   printf("Soy el Padre [%d]\n", getpid());
			   ptr->turno++;
			   printf("ptr->turno= %d \n", ptr->turno);
			   printf("\n");

			   while(ptr->turno!=5);
			   printf("Soy el Padre [%d]\n", getpid());
			   ptr->turno++;
			   printf("Bandera= %d \n", ptr->turno);


			   for(i=0;i<n;i++)
			   {
			   wait(NULL);			   	
			   }

			   printf("FIN DEL PROCESO");
			   printf("\n");
			   shmdt(ptr);
      		   shmctl(shm_id, IPC_RMID,0);
	}
}