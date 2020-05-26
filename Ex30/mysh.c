#include	<stdio.h>
#include	<unistd.h>
#include	<sys/wait.h>

int main(){
	int  pid;
	int  rtc = -1;

	// char *path = "/Users/segawakenji/Desktop/Ex30/Ex30/hello";
	char *path = "./hello";
	char *argv[] = {"./hello","Apple","Banana","Candy",NULL};

	pid = fork();
	switch(pid){
		case -1:
			printf("ERROR\n");
			break;
		case 0:
			printf("CHILD PROCESS!\n");
			execv(path,argv);

			printf("HELLO?\n");

			break;
		default:
			wait(&rtc);
			printf("PARENT PROCESS\n");
			break;
	}

	printf("FINISH!\n");
	if(pid != 0){
		printf("rtc : %d\n",rtc);
	}

	return 0;
}
