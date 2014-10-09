#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct busLine
{
  int line;
  char *stations[10];
  int weights[10];
 }busLine;


void stringFix2(char* string)
{
  char *copy = string;
  while (*copy != '\0')
    {
      if (*copy == ',')	
	{
	  *copy = ' ';
	}
      *string = *copy;
      string++;
      copy++;
    }
  *string = '\0';
}


void stringFix1(char* string)
{
  char *copy = string;
  
  while (*copy != '\0')
    {
      if (*copy != ' ')	
	{
	  *string++ = *copy;
	}
      copy++;
    }
  *string = '\0';

   
}

int getBusLines (char* filename, char* string, struct busLine testLine)
{
  int currentBusLine;
  int nextBusLine;
  char station[30];
  char station2[30];
  char teststation[50];
  int weight;
  int i;

  char test[30];
  char test2[30];
  

  FILE * file;
  file = fopen(filename, "r");
  if (file)
    {
      fgets(string, 100, file);
      stringFix1(string);
      stringFix2(string);
      printf("%s\n", string);


      sscanf(string, "%d%s%s%d",  &currentBusLine, station, station2, &testLine.weights[0]);
      printf("Original values:\n%d\n%s\n%s\n%d\n", currentBusLine, station, station2, weight);

      testLine.line = currentBusLine;
      //printf("%s\n", testLine.stations[0]);
            
      nextBusLine = currentBusLine;

      for (i = 0; i < 9; i++) {
	if ((testLine.stations[i] = malloc(sizeof(char) * 30)) == NULL) {
	    printf("Malloc fail\n");
	    return -1;
	  }

      }

      strcpy(testLine.stations[0], station);
      strcpy(testLine.stations[1], station2);

      for (i = 2; !(currentBusLine - nextBusLine); i++) 
	{
	  fgets(string, 100, file);
	  stringFix1(string);
	  stringFix2(string);
	  sscanf(string, "%d%s%s%d",  &nextBusLine, station, station2, &testLine.weights[i-1]);
	  printf("\n%d%d\n", currentBusLine, nextBusLine );
	  if (currentBusLine == nextBusLine) {
	    strcpy(testLine.stations[i], station2);
	  }
	}
      
	
      printf("Array:\n0: %s\n", testLine.stations[0]);
      printf("1: %s, %d\n", testLine.stations[1], testLine.weights[0]);
      
      printf("2: %s, %d\n", testLine.stations[2], testLine.weights[1]);
      printf("3: %s, %d\n", testLine.stations[3], testLine.weights[2]);
      printf("4: %s, %d\n", testLine.stations[4], testLine.weights[3]);
      printf("5: %s\n", testLine.stations[5]);
      
      
    }
      
  fclose(file);
  return 0;
}


int main(int argc, char* argv[]) 
{
  char *buffer;
  buffer =  malloc (sizeof(char) * 100);

  struct busLine testLine;

  getBusLines (argv[1], buffer, testLine);




  if (buffer) 
    {
      free(buffer);
    }
  
  return 0;
}
