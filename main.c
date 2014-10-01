#include <stdlib.h>
#include <stdio.h>



struct busLine
{
  unsigned short line;
  char stations[10];
};



void getBusLine (char* filename,  char *buffer)
{
  FILE *file;
  file = fopen(filename, "r");
  if (file)
  {
    buffer = (char*) malloc (sizeof(char) * (50 + 1) );
    fgets(buffer, 30, file);
    printf("%s", buffer); 
  }
  fclose(file);
}


int main(int argc, char* argv[]) 
{
  char *buffer = NULL;
  getBusLine (argv[1], buffer);
    if (buffer) {
        free(buffer);
    }


  return 0;
}
