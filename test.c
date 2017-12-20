#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int var = 1;
	int status;
	int r = fork();

	if (r==0){ // process X
		var++;
		r = fork();
		if (r==0){
			var ++;
			exit(var);} 
		else { // process Y
			if (wait(&status) != -1) {
				if (WIFEXITED(status)){
					printf("A %d\n", WEXITSTATUS(status));}
			}
			var += 2;
		}}
	else{ // process Z
		printf("W %d\n", var);
		if (wait(&status) != -1){
			if (WIFEXITED(status)){
				printf("B %d\n", WEXITSTATUS(status));}
		}

	}
	printf("C %d\n", var);
	return 0;
}