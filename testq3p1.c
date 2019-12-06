//
// Created by engmrgh on 12/6/19.
//
#include "types.h"
#include "user.h"
#include "stat.h"

int main(){
    int pid = fork();
    if(pid > 0){
        for (int i = 0; i < 100000; ++i)
            printf("I'M DAD");
    } else if(pid == 0){
        for (int i = 0; i < 100000; ++i)
            printf("I'M SON");
        exit(0);
    } else {
        printf("fork error\en");
    }
}