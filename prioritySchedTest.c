//
// Created by amir2040 on 12/16/19.
//
#include "types.h"
#include "stat.h"
#include "user.h"
#define PROCESS_NUMBER 5
#define ITERATION 500
#define PRIORITY_LEVEL 5

int main(){
    int pid = getpid();
    changeAlgorithm(2);
    for(int i = 0 ; i < PROCESS_NUMBER ; ++i) { // TODO: Think 25 minutes on this to figure out B-)
        if (pid > 0)
            pid = fork();
        if (pid == 0) {
            printf(1, "%d", PRIORITY_LEVEL - (int) (i / PRIORITY_LEVEL));
            changePriority(PRIORITY_LEVEL - (int) (i / PRIORITY_LEVEL));
        }
    }
    if(pid > 0){
        struct timeVariable tv;
        struct timeVariable prc[PRIORITY_LEVEL][((int) PROCESS_NUMBER / PRIORITY_LEVEL) + 1];
        int chid[PRIORITY_LEVEL][((int) PROCESS_NUMBER / PRIORITY_LEVEL) + 1];
        int wt = 0;
        int cbt = 0;
        int chpid;
        for (int i = 0; i < PROCESS_NUMBER; ++i) {
            chpid = waitForChild(&tv);
            chid[PRIORITY_LEVEL - i /PRIORITY_LEVEL][i % PRIORITY_LEVEL] = chpid;
            prc[PRIORITY_LEVEL - i / PRIORITY_LEVEL][i % PRIORITY_LEVEL] = tv; // B/
        }
        for (int i = 0; i < PRIORITY_LEVEL; ++i) {
            for (int j = 0; j < (PROCESS_NUMBER / PRIORITY_LEVEL) + 1; ++j) {
                tv = prc[i][j];
                chpid = chid[i][j];
                printf(1, "Process %d left created %d, run duration was %d, slept for %d, was ready for %d, terminated at %d\n",
                       chpid, tv.creationTime, tv.runningTime, tv.sleepingTime, tv.readyTime, tv.terminationTime);
                printf(1, "CBT: %d, WT: %d\n", tv.runningTime, tv.readyTime);
                wt += tv.readyTime;
                cbt += tv.runningTime;
            }
        }
        printf(1, "Average WT: %d, Average CBT: %d\n", wt/PROCESS_NUMBER, cbt/PROCESS_NUMBER);
        exit();
    }
    else{
        for (int i = 0; i < ITERATION; ++i)
            printf(1, "%d: %d\n", getpid(), i);
        exit();
    }
}