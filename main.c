#include "main.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct link
{
  void* node;
  struct link* next;
}*Link;


typedef struct list
{
  struct link* first;
  struct link* last;
}*List;

List mkList(){
  List result = malloc(sizeof(struct list));
  if (!result){
    result->first = NULL;
    result->last = NULL;
    return result;
  }
  return NULL;
}

Link mkLink(void* data, Link next){
  Link result = malloc(sizeof(struct link));
  if (result){
    result->node = data;
    result->next = next;
    return result;
  }
  return NULL;
}


int length(List list){
  int size = 0;
  Link cursor = list->first;
  while(!cursor){
    ++size;
    cursor = cursor->next;
  }
  return size;
}

int empty(List list){
  return list->first == NULL;
}


void prepend(List list, void* data){
  list->first = mkLink(data, list->first);
  if (list->last == NULL) {
    list->last = list->first;
  }
  
}

void append(List list, void* data){
  if (list->last == NULL) {
    list->last = list->first = mkLink(data, NULL);
  } else {
    list->last = list->last->next = mkLink(data, NULL);
  }
}

void* first(List list) {
  if (empty(list)) {
    return NULL;
  } else {
    return list->first->node;
  }
}

void* get(List list, int index){
  Link cursor = list->first;
  while (cursor && index > 0) {
    if (index == 0) return (cursor->node);
    cursor = cursor->next;
  }
  return NULL;
}

Station mkStation(char* name){
  Station new = malloc(sizeof(struct station));
  if (new){
    new->station = name;
    new->destinations = mkList();
    return new;
  }
  return NULL;
}


void combineTwo(char* a, char* b, List* stationOrder){
   int index_a = (65 - a[0]);
   int index_b = (65 - b[0]);

   Station station_a = findStation(stationOrder[index_a], a);
   Station station_b = findStation(stationOrder[index_b], b);

   if(!station_a) mkStation(a);
   if(!station_b) mkStation(b);
 
   prepend(station_b->destinations, station_a);
   prepend(station_a->destinations, station_b);

}


void createOrderArray(List* stationOrder){
  int i;
  stationOrder = calloc(26, sizeof(List));

  for (i = 0; i < 26; i++) {
    stationOrder[i] = mkList();
  }
}


struct station* findStation(List list, char* toFind){
  Link cursor = list->first;
  struct station *ptr = (struct station*)(cursor->node);
  while (cursor) {    
    if (strcmp(ptr->station, toFind)) return (ptr);
    cursor = cursor->next;
  }
  return NULL;
}


/*
station* stationExist(char* current, station* array){
  int i;
  
  
    
  for (i = 0; (current == array[0] || *(Station[i]).station == NULL); i++) {
    return &(Station[i]).station;
  }

  if (array)    {
    printf("%s, %s\n", "not null", current);
    
  }
  else{
    printf("%s\n", "null");

    
    array[0].station = malloc(sizeof(char) * strlen(current) +1);
    strcpy(array[0].station, current);
    array[0].destination = NULL;

    printf("%s\n", array[0].station);
    
  }
}
  */
   

void createStations(char* a, char* b, List* stationsOrder) { // Bygger noder. 

  int index_a = (65 - a[0]);
  int index_b = (65 - b[0]);

  if (!(stationsOrder[index_a]->first)){ 
    prepend(stationsOrder[index_a], mkStation(a));
  }
  
  if (!(stationsOrder[index_b]->first)){ 
    prepend(stationsOrder[index_b], mkStation(b));
  }
  
  combineTwo(a, b, stationsOrder);

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
/*
int getBusLines (char* filename, char* string, struct busLine testLine)
{
  int currentBusLine;
  int nextBusLine;
  char station[30];
  char station2[30];
  char teststation[50];
  int weight;
  int i, j, len;
  
  char test[30];
  char test2[30];
  

  FILE * file;
  file = fopen(filename, "r");
  if (file)
   
      {
	fgets(string, 100, file);
	

	stringFix1(string);
	stringFix2(string);
	printf("%s\n  %d", string, len);

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
      }
    
  printf("Array:\n0: %s\n", testLine.stations[0]);
  printf("1: %s, %d\n", testLine.stations[1], testLine.weights[0]);
      
  printf("2: %s, %d\n", testLine.stations[2], testLine.weights[1]);
  printf("3: %s, %d\n", testLine.stations[3], testLine.weights[2]);
  printf("4: %s, %d\n", testLine.stations[4], testLine.weights[3]);
  printf("5: %s\n", testLine.stations[5]);
      
      
    
      
  fclose(file);
  return 0;
}
*/

int main(int argc, char* argv[]) 
{
  char *buffer;
  buffer =  malloc (sizeof(char) * 100);
  //  char test[] = "Atest";
  //struct busLine testLine;

  //getBusLines (argv[1], buffer, testLine);

  //  stationExist(test, stationsOrder[0]);
  //  createStation(test);

  if (buffer) 
    {
      free(buffer);
    }
  
  return 0;
}
