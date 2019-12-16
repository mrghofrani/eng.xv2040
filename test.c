//
// Created by engmrgh on 12/16/19.
//
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int pid = fork();
    if (pid == 0){
        for (int i = 0; i < 1000; ++i)
            printf(1, "hurray!\n");
        sleep(2);
        exit();
    } else if(pid > 0){
        struct timeVariable tv;
        waitForChild(&tv);
        printf(1, "creationTime %d\n", tv.creationTime);
        printf(1, "terminationTime %d\n", tv.terminationTime);
        printf(1, "readyTime %d\n", tv.readyTime);
        printf(1, "sleepingTime %d\n", tv.sleepingTime);
        printf(1, "runningTime %d\n", tv.runningTime);
        exit();
    }
}