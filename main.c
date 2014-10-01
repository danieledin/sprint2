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

  int string_size,read_size;
  file = fopen(filename, "r");
  if (file)
  {
    //seek the last byte of the file
    fseek(file, 0, SEEK_END);

    //offset from the first to the last byte, or in other words, filesize
    string_size = ftell (file);
    string_size = 10;

    //go back to the start of the file
    rewind(file);

    //allocate a string that can hold it all
    buffer = (char*) malloc (sizeof(char) * (string_size + 1) );

    //read it all in one operation
    read_size = fread(buffer,sizeof(char),string_size,file);
    //fread doesnt set it so put a \0 in the last position
    //and buffer is now officialy a string
    buffer[string_size] = '\0';

    if (string_size != read_size) {
      //something went wrong, throw away the memory and set
      //the buffer to NULL
      free(buffer);
      buffer = NULL;
    }

  }
  fclose(file);
}


int main(int argc, char* argv[]) 
{
  char *buffer = NULL;
  getBusLine (argv[1], buffer);
  printf("%s\n", buffer);
  return 0;
}
