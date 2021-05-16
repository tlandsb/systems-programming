//main.c

#include "assign2Headers.h"
int shouldRun = 1;
int answererPid;
int guesserPid;
  
void alarmHandler(int sig){
  kill(answererPid, TIME_OVER_SIGNAL);
  kill(guesserPid, TIME_OVER_SIGNAL);
  shouldRun = 0;
}

void ChldHandler (int sig)
{wait(NULL);
 shouldRun = 0; 
}


int main(){
  char line[LINE_LEN];
  
  snprintf(line,LINE_LEN,"%d",answererPid);
  
  struct sigaction act; 
  memset(&act, '\0', sizeof(struct sigaction));

  act.sa_handler = alarmHandler;
  sigaction(SIGALRM, &act, NULL);

  act.sa_handler = ChldHandler;
  sigaction(SIGCHLD, &act, NULL);

  answererPid = fork();

   if (answererPid == 0){
     execl(ANSWERER_PROGNAME, ANSWERER_PROGNAME, (char *) NULL);
     //printf("yep, its child");
   }

   else{
     sleep(1);
     snprintf(line, LINE_LEN, "%d", answererPid);

     guesserPid = fork();

     if (guesserPid == 0){
       execl(GUESSER_PROGNAME, GUESSER_PROGNAME, line, (char *) NULL);
     }

     else{
       alarm(NUM_SECONDS);
       while (shouldRun)
	 sleep(1);
       sleep(1);
	   printf("launcher finished\n");
       return (EXIT_SUCCESS);
     }
}
}
