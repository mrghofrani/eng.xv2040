//
// Created by amir2040 on 12/16/19.
//
#include "types.h"
#include "stat.h"
#include "user.h"
#define PROCESS_NUMBER 25
#define ITERATION 500
#define PRIORITY_LEVEL 5

int main(){
    int pid = getpid();
    changeAlgorithm(2);
    for(int i = 0 ; i < PROCESS_NUMBER; ++i) { // TODO: Think 25 minutes on this to figure out B-)
        if (pid > 0)
            pid = fork();
        if (pid == 0) {
            int priority =  PRIORITY_LEVEL - (int) (i / PRIORITY_LEVEL);
            changePriority(priority);
        }
    }
    if(pid > 0){
        struct timeVariable tv;
        struct timeVariable prc[PRIORITY_LEVEL][(int)(PROCESS_NUMBER / PRIORITY_LEVEL) + 1];
        int chid[PRIORITY_LEVEL][(int)(PROCESS_NUMBER / PRIORITY_LEVEL) + 1];
        int chpid;

        for (int i = 0; i < PROCESS_NUMBER; ++i) {
            chpid = waitForChild(&tv);
            chid[PRIORITY_LEVEL - (int) (i / PRIORITY_LEVEL) - 1][(int)(i % PRIORITY_LEVEL)] = chpid;
            prc[PRIORITY_LEVEL - (int) (i / PRIORITY_LEVEL) - 1][(int)(i % PRIORITY_LEVEL)] = tv;
        }
        int lwt = 0; // local waiting time
        int lcbt = 0; // local Cognitive behavioral therapy
        int gwt = 0; // global waiting time
        int gcbt = 0; // global Cognitive behavioral therapy
        for (int i = 0; i < PRIORITY_LEVEL; ++i) {
            lwt = 0;
            lcbt = 0;
            for (int j = 0; j < PROCESS_NUMBER / PRIORITY_LEVEL; ++j) {
                tv = prc[i][j];
                chpid = chid[i][j];
                printf(1, "Process %d left created %d, run duration was %d, slept for %d, was ready for %d, terminated at %d\n",
                       chpid, tv.creationTime, tv.runningTime, tv.sleepingTime, tv.readyTime, tv.terminationTime);
                printf(1, "CBT: %d, WT: %d\n", tv.runningTime, tv.readyTime);
                lwt += tv.readyTime;
                lcbt += tv.runningTime;
            }
            printf(1, "---------->");
            printf(1, "Group %d: Average WT %d, Average CBT %d\n", PRIORITY_LEVEL-i, lwt/(PROCESS_NUMBER / PRIORITY_LEVEL), lcbt/(PROCESS_NUMBER / PRIORITY_LEVEL));
            gcbt += lcbt;
            gwt += lwt;
        }
        printf(1, "Total Average WT: %d, Average CBT: %d\n", gwt/PRIORITY_LEVEL, gcbt/PRIORITY_LEVEL);
        exit();
    }
    else{
        for (int i = 0; i < ITERATION; ++i)
            printf(1, "%d: %d\n", getpid(), i);
        exit();
    }
}