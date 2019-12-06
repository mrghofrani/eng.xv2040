//
// Created by engmrgh on 12/6/19.
//
#include "types.h"
#include "stat.h"
#include "user.h"
#include "defs.h"

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
        cprintf(1,"parent\n");
        cprintf(1,"%d %d \n", n1, n2);
        cprintf(1," my id is %d \n", getpid());
    }
    else if (n1 == 0 && n2 > 0){
        changePriority(2);
        cprintf(1,"First child\n");
        cprintf(1,"%d %d \n", n1, n2);
        cprintf(1,"my id is %d  \n", getpid());
    }
    else if (n1 > 0 && n2 == 0)
    {
        changePriority(4);
        cprintf(1,"Second child\n");
        cprintf(1,"%d %d \n", n1, n2);
        cprintf(1,"my id is %d  \n", getpid());
    }
    else {
        changePriority(5);
        cprintf(1,"third child\n");
        cprintf(1,"%d %d \n", n1, n2);
        cprintf(1," my id is %d \n", getpid());
    }
    return 0;
}