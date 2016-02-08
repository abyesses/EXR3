//
//  main.c
//  ExR3
//
//  Created by Abraham Esses on 2/8/16.
//  Copyright © 2016 Abraham Esses. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
pid_t pid;
int hijos;
int estado;
pid_t pid;

void creaHijos(int n){
    //int * arrayHijos = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        pid = fork();
        if(pid < 0 ){
        
            printf("El proceso no fue creado\n");
            printf("Tenemos %d procesos hijos\n",hijos);
            break;
        }
        if (pid==0) {
            printf("Creando hijo con PID: %d\n",getpid());
            printf("Promedio entre PID: %d y PPID: %d Promedio: %d\n",getpid(),getppid(),(getpid()+getppid())/2);
            estado = 1;
            hijos++;
        }
        else{
            //for(int j=0;j<n;j++){
                //pid = fork();
                //*(arrayHijos+j) = pid;
                if(pid==0){
                    printf("Creando hijo con PID: %d\n",getpid());
                    printf("Promedio entre PID: %d y PPID: %d Promedio: %d\n",getpid(),getppid(),(getpid()+getppid())/2);
                    estado = 1;
                    hijos++;
                }
            //}
            wait(NULL);
                
            
                if (waitpid(pid, &estado, 0) != -1)
                {
                    if (WIFEXITED(estado))
                        printf("Ya terminó el hijo con PID %d con valor de retorno %d \n", pid, WEXITSTATUS (estado));
                }
        
            
        
        }
    
    }
    printf("Hijos: %d\n",hijos);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    creaHijos(5);
    //printf("Hello, World!\n");
    return 0;
}
