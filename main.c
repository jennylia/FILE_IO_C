#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
/*
 * Play 
 * 1. Create a dir if a file doesn't exist
 * 2. Then create a file in it
 * 3. make the name of a file encrupted*/

#define DIR_NAME "FOLDER"
#define FILE_NAME "file.txt"
int main(){
  DIR * dp;
  int status;
  if ((dp = opendir(DIR_NAME)) == NULL){
      printf("what the hell\n"); 
      status = mkdir(DIR_NAME, 0777);
      if (status < 0){
        printf("shit\n");
        exit(1);//some error
      }else{
        printf("yay\n");
      } 
  }

  //part 2
  int len = strlen(DIR_NAME) + strlen(FILE_NAME) + 1;
  char path[len];
  bzero(path, len);
  strcat(path, DIR_NAME);
  strcat(path, "/");
  strcat(path, FILE_NAME);
  printf("%s\n", path);

  FILE *fp;
  if ((fp = fopen(path, "a+")) == NULL){
    printf("fail to open a file, create one?");
    exit(1); // just exist
  }else{
    printf("a file exist so very good\n");
    int stat = fputs("sup sup", fp); 
    printf("whats the bytes written%d\n", stat); 
  }
}
