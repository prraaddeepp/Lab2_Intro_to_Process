#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int  main(void) {
  
//   two child processes because of less than equals sign in line 23
  int child_num = 1;
  int  pid[child_num];

	// child process loop
  int total_process_loop = 20;

//   sleep time
  int sleep_time = 5;
  int i, j;

  for (i=0; i <= child_num; i++) {
    pid[i] = fork();
    if (pid[i] < 0) {
      printf("Fork failed!\n");
    } else if (pid[i] == 0) {
      int childPID = getpid();
      int parendPID = getppid();
      srand(childPID);

	//   choosing a random number between 1 to 20 for the process loop
      int rand_loop = 1 + rand() % total_process_loop;
      for (j =0; j <rand_loop; j++) {
		//   choosing a random number between 1 to 5 for sleep
        int rand_time = 1 + rand() % sleep_time;
        printf("Child Pid: <%d> is going to sleep!\n", childPID);
        sleep(rand_time);
		// two lines following the procedure of the awake child to distinguish between sleep
        printf("Child Pid: <%d> is awake!\nWhere is my Parent Pid: [%d]?\n\n", childPID, parendPID);
      }
      exit(0);
    }
  }
  for (i=0; i < child_num; i++) {
    int status;
    int childPID = wait(&status);
  }
  return 0;
}