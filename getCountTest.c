#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int  n, id;

  if(argc < 2 )
    n = 1;       //default value
  else
    n = atoi ( argv[1] ); //from command line

  id = 0;
    id = fork ();
    if ( id < 0 ) {
      printf(1, "%d failed in fork!\n", getpid() );
    } else if ( id > 0 ) {  //parent
    getpid();
    getpid();
      printf(1, "Parent %d creating child  %d\n", getpid(), id );
      wait ();
      printf(1, "systemcall counter : %d in process %d\n", getCount(n), getpid() );
   } else {   // child
      printf(1, "Child %d created\n", getpid() );
      exit();
    }

  exit();
}
