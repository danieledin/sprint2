#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct busLine
{
  int line;
  char *stations[10];
 }busLine;

void getBusLine (char* filename)
{
  FILE *file;
  char string1[100];
  char string2[100];
  char* strings[10];
  int i;


  file = fopen(filename, "r");
  if (file)
    {
      fgets(string1, 100, file);
      fgets(string2, 100, file);
      printf("%s", string1);
      strings[0] = string1;
      
      for (i = 1; (string1[0] == string2[0]  && string1[1] == string2[1] && string1[2] == string2[2]); i++) 
	{
	  strings[1] = string2;
	  fgets(string2, 100, file);

	  strings[2] = string2;
	  fgets(string2, 100, file);


	  strings[3] = string2;
	  fgets(string2, 100, file);


	  strings[4] = string2;
	  fgets(string2, 100, file);

	}

      for (int k = 0; k < 5; k++)
	{
	  printf("\n%s", strings[k]);
	}

 
  }
  fclose(file);
}


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




void parseBusLines(char* string, struct busLine testLine)
{ 
  char *copy = string;

  int comma = 44;
  printf("%c\n", comma);
 
  char* ptr;
  ptr = strchr(string, comma);
  printf("%s\n", ptr+1);

  /*
  testLine.stations[0] = station;

  printf("%s\n", testLine.stations[0]);
  */

}




int getBus (char* filename, char* string, struct busLine testLine)
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


      sscanf(string, "%d%s%s%d",  &currentBusLine, station, station2, &weight);
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
	  sscanf(string, "%d%s%s%d",  &nextBusLine, station, station2, &weight);
	  printf("\n%d%d\n", currentBusLine, nextBusLine );
	  if (currentBusLine == nextBusLine) {
	    strcpy(testLine.stations[i], station2);
	  }
	}
      
	
      printf("Array:\n0: %s\n", testLine.stations[0]);
      printf("1: %s\n", testLine.stations[1]);
      
      printf("2: %s\n", testLine.stations[2]);
      printf("3: %s\n", testLine.stations[3]);
      printf("4: %s\n", testLine.stations[4]);
      printf("4: %s\n", testLine.stations[5]);
      
      
    }
      
  fclose(file);
  return 0;
}


int main(int argc, char* argv[]) 
{
  char *buffer;
  buffer =  malloc (sizeof(char) * 100);
  /*
  getBusLine (argv[1]);
    if (buffer) {
        free(buffer);
    }
  */
  struct busLine testLine;

  getBus (argv[1], buffer, testLine);




  if (buffer) 
    {
      free(buffer);
    }
  
  return 0;
}
