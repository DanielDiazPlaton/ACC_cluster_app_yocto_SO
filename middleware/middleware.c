//Ira el middelware
#include "middleware.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>/*delay*/



void *Ostask_app(void *arg)
{
    char *input_arg = (char *) arg;

    while(1)
    {
    printf("\nAqui iran las funcionalidades del cluster: %s\n",input_arg);
    sleep(1);
    }
}

void *Ostask_comm(void *arg)
{
    char *input_arg = (char *) arg;

    while(1)
    {
    printf("\nAqui iran el mensaje de CAN: %s\n",input_arg);
    sleep(1);
    }
}


void Ostask_create()
{
    pthread_t app_thread;
    static char *pApp = "Funciones" ; 

    pthread_t CAN_thread;
    static char *pCan = "Comunicacion CAN" ; 
    
    int thread_app = 0;
    thread_app = pthread_create(&app_thread,NULL,Ostask_app,(void*)pApp);
    if(thread_app != 0)
    {
        printf("Error");
        exit(0);
    }
    
    int comm_thread = 0;
    comm_thread = pthread_create(&CAN_thread,NULL,Ostask_comm,(void*)pCan);
    if(comm_thread != 0)
    {
        printf("Error");
        exit(0);
    }
    
    /*pthread_join(Middleware_thread,NULL);*/
}




