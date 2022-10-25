#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct User{
  char uname[100];
  char shell[100];
}User_t;


int comPuser(const void* us1, const void* us2){
  const User_t u1=*(User_t*)us1;
  const User_t u2=*(User_t*)us2;
  return strcmp(u1.uname, u2.uname);
}

int readFile(FILE* f, User_t users[], int n){
    char line[1000];
    for (int i=0; i<n; i++){
       if(fgets(line, 1000, f)!=NULL){
          User_t current;
          char *pC=strchr(line, ':');
          strncpy(current.uname, line, pC-line);
          pC=strrchr(line, ':');
          strcpy(current.shell, pC+1);
          current.shell[strlen(current.shell)-1]='\0';
          users[i]=current;
        }
        else{
          return i;
        }
    }
    return n;
}

int main(int argc, char* argv[]){
  if (argc!=3){
    return -1;
  }
  FILE* f=fopen(argv[1], "r");
  if (!f){
    return -2;
  }

  //int nRecords=atoi(argv[2]);     //straightforward version
  //or
  int nRecords;
  if (sscanf(argv[2], "%u", &nRecords)!=1){
    printf("It seems it's not a number");
    return -3;
  }
  User_t users[nRecords];

  int n=readFile(f, users, nRecords );

  qsort(users, n, sizeof(User_t), comPuser);

  for (int i=0; i<n; i++){
    //printf ("%d: %s %s\n", i, users[i].uname, users[i].shell);
    printf ("%s\n", users[i].shell);
  }
  return 0;
}
