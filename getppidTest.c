//
// Created by amir2040 on 11/21/19.
//

#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int pid=fork();
    if(pid<0){
        printf(1,"Cannot generate a child\n");
        exit();
    }else if(pid == 0){
        printf(1,"I'm Child process\n");
        printf(1,"My parent's pid is: %d\n",getppid());
        exit();
    }else{
        wait();
        printf(1,"I'M PARENT PROCESS\n");
        printf(1,"MY PROCESS ID IS %d\n", getpid());
    }
}