typedef struct list *List;


typedef struct destination {
  int busLine, time; 
  struct station *station;
}destination, *Destination;

typedef struct station {  
  char* station; 
  List destinations; // lista med destination's
}station, *Station; // Station = struct* node_station

struct station central;

strscpy(central.station, array[i])

void createStation(char*); // Bygger noder.
station* stationExist(char*, station*); 
struct station* findStation(List, char*);



// void getDestinations(nätverk.txt, Destination);
