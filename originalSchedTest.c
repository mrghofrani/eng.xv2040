//
// Created by amir2040 on 12/16/19.
//
#include "types.h"
#include "stat.h"
#include "user.h"
#define PROCESS_NUMBER 10
#define ITERATION 1000

int main(){
    int pid = getpid();
    for(int i = 0 ; i < 10 ; ++i) { // TODO: Think 15 minutes on this to figure out B-)
        if (pid > 0)
            pid = fork();
    }
    changeAlgorithm(1);
    if(pid > 0){
        struct timeVariable tv;
        struct timeVariable prc[PROCESS_NUMBER];
        int chid[PROCESS_NUMBER];
        int wt = 0;
        int cbt = 0;
        int tt = 0;
        int chpid;
        for (int i = 0; i < PROCESS_NUMBER; ++i) {
            chpid = waitForChild(&tv);
            chid[i] = chpid;
            prc[i] = tv;
            wt += (tv.readyTime + tv.sleepingTime);
            cbt += tv.runningTime;
            tt += (tv.terminationTime - tv.creationTime);
        }
        for (int i = 0; i < PROCESS_NUMBER; ++i) {
            tv = prc[i];
            chpid = chid[i];
            printf(1, "Process %d left created %d, run duration was %d, slept for %d, was ready for %d, terminated at %d\n",
                   chpid, tv.creationTime, tv.runningTime, tv.sleepingTime, tv.readyTime, tv.terminationTime);
            printf(1, "CBT: %d, WT: %d, TT: %d\n", tv.runningTime, tv.readyTime, tv.terminationTime - tv.creationTime);
        }
        printf(1, "Average WT: %d, Average CBT: %d, Average TT: %d\n", wt/PROCESS_NUMBER, cbt/PROCESS_NUMBER, tt/PROCESS_NUMBER);
        exit();
    }
    else{
        for (int i = 0; i < ITERATION; ++i)
            printf(1, "%d: %d\n", getpid(), i);
        exit();
    }
}