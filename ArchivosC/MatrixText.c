#include <stdio.h>
#include <cctype>
#include <stdlib.h>
#include<iostream>
using namespace std;
#include<wchar.h>

char finPrograma;

int main() {
	printf("%cDesea ejecutar el programa [S/N]?\n",168);
	scanf("%string",&finPrograma);	 
	while (toupper(finPrograma)== 'S')
	{
		system("cls");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("  Wake up, Gabo...\n");
		printf("\n");
		printf("  The Matrix has you...\n");
		//printf("%cDesea volver a ejecutar el programa [S/N]?\n",168);
			scanf("%string",&finPrograma);
	}

return 0;


}
