//
// Created by engmrgh on 12/6/19.
//
#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int pid;
    pid = fork();
    if(pid == 0){
        for(;;);
    }
    else{
        pid = fork();
        if(pid == 0){
            for(;;);
            exit();
        }
        else{
            pid = fork();
            if(pid == 0){
                for(;;);
                exit();
            }
            else{
                pid = fork();
                if(pid == 0){
                    for(;;);
                    exit();
                }
                else{
                    //‌ sweet child of mine
                    // come on my children
                    // Welcome HOME
                    int childs = getChildren();
                    printf(1,"My sweet children are %d but I can't identify their pid :( Such a bad daddy.",childs);
                    wait();
                    wait();
                    wait();
                    wait();
                    exit();
                }
            }
        }
    }
    return 0;
}