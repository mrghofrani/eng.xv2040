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
    else if(pid > 0){
        pid = fork();
        if(pid == 0){
            for(;;);
            exit();
        }
        else if(pid > 0){
            pid = fork();
            if(pid == 0){
                for(;;);
                exit();
            }
            else if(pid > 0){
                pid = fork();
                if(pid == 0){
                    for(;;);
                    exit();
                }
                else if(pid > 0){
                    //‌ sweet child of mine
                    // come on my children
                    // Welcome HOME
                    int childs = getChildren();
                    printf(1,"My sweet children are %d but I can't identify their pid :( Such a bad daddy.\n",childs);
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