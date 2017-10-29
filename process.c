#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Process, fork(), wait, getpid()
 *  
 */

// For illustration on ps -a and concurrent programming
// void doSomeWork(void){
// 	const int NUM_TIMES = 5;
// 	for (int i  = 0; i < NUM_TIMES; i++) {
// 		sleep(rand()%4);
// 		printf("Done Work in %dth loop \n", i);
// 	}
// }

void doSomeWork(char *name){
	const int NUM_TIMES = 5;
	for (int i  = 0; i < NUM_TIMES; i++) {
		sleep(rand() % 4);
		printf("Done Work in %dth loop for %s \n", i, name);
	}
}

// Simple idea of fork():
/*
int main(int argc, char* argv[]){
	printf("I am : %d \n", (int) getpid());

	//fork();
	//pid_t pid = fork();
	//printf("fork returned : %d \n", (int) pid );

	//printf("I am : %d \n", (int) getpid());

	return 0;
}
*/


// Parent and child processes

// int main(int argc, char* argv[]){
// 	printf("I am : %d \n", (int) getpid());

// 	pid_t pid = fork();

// 	printf("fork returned: %d \n", (int) pid);

// 	if (pid < 0) {
// 		perror ("Fork Failed");
// 	}

// 	if (pid == 0) {
// 		printf("I am the child with pid %d\n", (int) getpid());
		// exit(0)
// 	} 
		//
//		// we must be the parent
//	    //printf("I am the parent\n");
// 	else if (pid > 0 )
// 	{
// 		printf("I am the parent : %d \n", (int) getpid() );
// 	}

// 	return 0;
// }

// wait until child finished with sleeping
/*
int main(int argc, char* argv[]){
	printf("I am : %d \n", (int) getpid());

	pid_t pid = fork();

	printf("fork returned: %d \n", (int) pid);

	if (pid < 0) {
		perror ("Fork Failed");
	}

	if (pid == 0) {
		printf("I am the child with pid %d\n", (int) getpid());
		sleep(5);
		printf("child exiting\n");
		exit(0);
	} 

	printf("I am the parent, waiting for child to end\n");
	wait(NULL);
	printf("Parent Ending\n");
	return 0;
}
*/

// wait until child finished with doSomeWork Function
/*
int main(int argc, char* argv[]){
	printf("I am : %d \n", (int) getpid());

	// To check -ps -a 
	//sleep(5);
	pid_t pid = fork();

	// srand((int) pid);
	printf("fork returned: %d \n", (int) pid);

	if (pid < 0) {
		perror ("Fork Failed");
	}

	if (pid == 0) {
		printf("I am the child with pid %d\n", (int) getpid());
		doSomeWork("Child");
		exit(0);

		// for wait part
		// exit(233);
	} 

	printf("I am the parent, waiting for child to end\n");
	doSomeWork("Parent");
	wait(NULL);
	// the wait() function returns child pid
	//pid_t childpid = wait(NULL);
	//printf("Parent Knows the child %d finished\n", (int) childpid);

	// int status = 0;
	// pid_t childpid = wait(&status);
	//printf("Parent Knows the child %d finished with status %d\n", (int) childpid, status);
	
	//int childReturnValue = WEXITSTATUS(status);
	//printf("	Return Value was %d\n", (int) childReturnValue);
	

	return 0;
}
*/


// A zombie process demo:
// when child ends quickly and not been cleared using wait()
/*
int main(int argc, char* argv[]){
	printf("I am : %d \n", (int) getpid());


	pid_t pid = fork();

	 srand((int) pid);
	printf("fork returned: %d \n", (int) pid);

	if (pid < 0) {
		perror ("Fork Failed");
	}

	if (pid == 0) {
		printf("I am the child with pid %d\n", (int) getpid());
		doSomeWork("Child");

		exit(233);
	} 

	printf("I am the parent, waiting for child to end\n");
	sleep(20);
	doSomeWork("Parent");

	int status = 0;
	pid_t childpid = wait(&status);
	printf("Parent Knows the child %d finished with status %d\n", (int) childpid, status);
	
	int childReturnValue = WEXITSTATUS(status);
	printf("	Return Value was %d\n", (int) childReturnValue);
	

	return 0;
}
*/
