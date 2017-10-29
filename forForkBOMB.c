



// 太极生两仪，两仪生四象，四象生八卦......

int main(int argc, char* argv[]){
	for ( int i = 1; i <= 2; i ++ ){
		fork();
		printf("%d: My PID = %d \n", i, (int) getpid());
	}

	sleep(1);
	printf("--> My PID = %d \n",  (int) getpid());

	return 0;




// fork() bomb to bomb one's computer
	// while (){
	// 	fork();
	// }

// kill process by kill command
}