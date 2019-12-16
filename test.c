//
// Created by engmrgh on 12/16/19.
//
#include "types.h"
#include "user.h"

int main(void) {
    int pid = fork();
    if (pid == 0){
        for (int i = 0; i < 10; ++i);
        exit();
    } else if(pid > 0){
        exit();
    }
}