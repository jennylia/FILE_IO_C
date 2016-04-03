#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
 * Play 
 * 1. Create a dir if a file doesn't exist
 * 2. Then create a file in it
 * 3. make the name of a file encrupted*/

#define NAME "FOLDER"
int main(){
  DIR * dp;
  int status;
  if ((dp = opendir(NAME)) == NULL){
      printf("what the hell\n"); 
      status = mkdir(NAME, 0777);
      if (status < 0){
        printf("shit\n");
      }else{
        printf("yay\n");
      } 
  }

}
