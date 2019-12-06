//
// Created by engmrgh on 12/6/19.
//
#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    // Creating first child
    int n1 = fork();

    // Creating second child. First child
    // also executes this line and creates
    // grandchild.
    int n2 = fork();

    if (n1 > 0 && n2 > 0) {
        changePriority(1);
        printf(1,"parent\n");
        printf(1,"%d %d \n", n1, n2);
        printf(1," my id is %d \n", getpid());
        wait();
        wait();
        exit();
    }
    else if (n1 == 0 && n2 > 0){
        changePriority(2);
        printf(1,"First child\n");
        printf(1,"%d %d \n", n1, n2);
        printf(1,"my id is %d  \n", getpid());
        wait();
        exit();
    }
    else if (n1 > 0 && n2 == 0)
    {
        changePriority(4);
        printf(1,"Second child\n");
        printf(1,"%d %d \n", n1, n2);
        printf(1,"my id is %d  \n", getpid());
        exit();
    }
    else {
        changePriority(1);
        printf(1,"third child\n");
        printf(1,"%d %d \n", n1, n2);
        printf(1," my id is %d \n", getpid());
        exit();
    }
}