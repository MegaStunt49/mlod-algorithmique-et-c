#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* scanLine(){
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n'){
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

int scanLineAsInt(){
	int buf;
	scanf("%i\n",&buf);
	return buf;
}


int main(void){
	int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n",nbGagnants);
	int yearFirstWinner = scanLineAsInt();
	printf("yearFirstWinner = %i\n",yearFirstWinner);
	char *nameFirstWinner = scanLine();
	printf("nameFirstWinner = %s\n",nameFirstWinner);
	return EXIT_SUCCESS;
}