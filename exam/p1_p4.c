#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Record{
  char key[11];
  char value[11];
}Record_t;

typedef struct Result{
  Record_t* lines;
  int nL;
}Result_t;

int cmpLine(const void* ln1, const void* ln2){
  const char* l1=(char*)ln1;
  const char* l2=(char*)ln2;
  return strcmp(l1, l2);
}

int findKey(Record_t records[], int n, Record_t toFind){
  for (int i=0; i<n; i++){
    if (strcmp(records[i].key, toFind.key)==0){
      return i;
    }
  }
  return -1;
}

Result_t readFile(FILE* f){
    int nL=0;
    Record_t* lines=malloc(1*sizeof(Record_t));
    if (!lines){
      return (Result_t){NULL, 0};
    }
    Record_t current;
    while (fscanf(f, "%10s = %10s", current.key, current.value)==2){
    //  printf("We have key=%s and value=%s\n", current.key, current.value);
      int foundPos=findKey(lines, nL, current);     //check if we allready have the same key
      if (foundPos==-1){    //if the is no such key in array
        Record_t* aux=realloc(lines, (nL+1)*sizeof(Record_t));
        if (!aux){
          free(lines);
          return (Result_t){NULL, 0};
        }
        else{
          lines=aux;
          lines[nL]=current;
          nL++;
        }
      }
      else{ //if the key is there we simply replace it
        lines[foundPos]=current;
      }
    }
    return (Result_t){lines, nL}; //a package with both list of records and number of records
}

int main(int argc, char* argv[]){
  if (argc!=2){
    return -1;
  }
  FILE* f=fopen(argv[1], "r");
  if (!f){
    return -1;
  }

  Result_t r=readFile(f);
  qsort(r.lines, r.nL, sizeof(Record_t), cmpLine);

  for (int i=0; i<r.nL; i++){
    printf ("%s %s\n", r.lines[i].key, r.lines[i].value);
  }
  return 0;
}
