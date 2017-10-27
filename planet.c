#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 8

int main(int argc, char *argv[])
{	
	int a;
	a = sizeof("chrismas");
	printf("%d\n", a);
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
	int i, j;
	for (i = 1; i < argc; i++)
	{
		for (j = 0; j < NUM_PLANETS; j++)
		{
			if (strcmp(argv[i], planets[j]) == 0)
			{
				printf("%s is planet %d\n", argv[i], j+1 );
				break;
			}
			//if (j == NUM_PLANETS - 1)
			//{
			//printf("%s is not a planet\n", argv[i]);
			//}
		}
	}
	return 0;
}

