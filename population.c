#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXBUFFERSIZE   80

void getInput(void);
int getStartSize(void);
int getAnInt(void);
int years(int startPopulation, int endPopulation);



int getAnInt(void) {
    char    ch;                     /* handles user input */
	char    buffer[MAXBUFFERSIZE];  /* sufficient to handle one line */
	int     char_count;             /* number of characters read for this line */
	int     number, valid_choice;
    
    valid_choice = 0;

    do {
		ch = getchar();
		char_count = 0;
	    while( (ch != '\n')  &&  (char_count < MAXBUFFERSIZE)) {
				buffer[char_count++] = ch;
				ch = getchar();
		}
		buffer[char_count] = 0x00;      /* null terminate buffer */
		number = atoi( buffer );
		if (number > 8)
            valid_choice = 1;
            else
                printf("Enter a number > 8");
    } while ( valid_choice == 0 );
return number;
}

int years(int startPopulation, int endPopulation)  {
     int n = 1;
    int born = startPopulation / 3;
    int passAway = startPopulation / 4;
    int diff = born - passAway;
   
    while (startPopulation  < endPopulation) {
        diff = (startPopulation / 3) - (startPopulation / 4);
       startPopulation += diff;
       n++;
    }
return n - 1;
}

int main(void) {
    // TODO: Prompt for start size
    
    int startSize;
    int endPopulationSize = 0;
    
     printf("Enter the Starting Population Size : ");
    startSize = getAnInt();

// TODO: Prompt for end size

    printf("Enter the Ending Population Size : ");
    endPopulationSize = getAnInt();
    while (endPopulationSize < startSize) {
        printf("Enter a number >=  %i ", startSize);
       endPopulationSize = getAnInt();
    }
    
    printf("Start size : %i\n ", startSize);
    
    printf("End Size : %i\n", endPopulationSize);

    // TODO: Calculate number of years until we reach threshold
    int n = years(startSize, endPopulationSize);
    // TODO: Print number of years
    printf("Years : %i\n", n);

}