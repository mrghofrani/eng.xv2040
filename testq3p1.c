//
// Created by engmrgh on 12/6/19.
//
#include "types.h"
#include "user.h"
#include "stat.h"

int main(){
    int pid = fork();
    if(pid > 0){
        for (int i = 0; i < 100; ++i)
            printf(1,"I'M DAD pid %d repeating %d\n", pid, i);
    } else if(pid == 0){
        for (int i = 0; i < 100; ++i)
            printf(1,"I'M SON pid %d repeating %d\n", pid, i);
        exit();
    } else {
        printf(2,"fork error\en");
    }
}