#include "assign2Headers.h"
int shouldRun = 1;



void correcthandler(int sig){
printf("That was correct!\n");}

void incorrecthandler(int sig){
printf("Sorry, that was not correct\n");}

void timeuphandler (int sig){
shouldRun = 0;
printf("time is up!\n");}

void winhandler (int sig){
 shouldRun = 0;
 printf("you've won the game!\n");}


int main (int argc, char* argv[]){

  //printf("made it guesser\n");

struct sigaction act;

char guess;

memset(&act, '\0', sizeof(act));

act.sa_handler = timeuphandler;
sigaction(TIME_OVER_SIGNAL, &act, NULL);

act.sa_handler = correcthandler;
sigaction(CORRECT_SIGNAL, &act, NULL);

act.sa_handler = incorrecthandler;
sigaction(INCORRECT_SIGNAL, &act, NULL);

act.sa_handler = winhandler;
sigaction(WIN_SIGNAL, &act, NULL);



//int pid =fork();
	 pid_t pid = strtol(argv[1], NULL, 10);

	 while (shouldRun){
	     printf("What would you like your next guess to be? 0 or 1? ");
	     scanf("%c", &guess);

	     //printf("your guess is %c\n", guess);

	     if(guess == '0'){
	     kill(pid,ZERO_SIGNAL);
	     } else if (guess == '1'){
	     kill(pid, ONE_SIGNAL);
	     }  else{}
	     sleep(1);
	   }

	 sleep(1);
	 sleep(1);

	 printf("guess finished\n");
	 return(EXIT_SUCCESS);
	 }




