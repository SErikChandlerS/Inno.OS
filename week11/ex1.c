#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   int myFile = open("ex1.txt", O_RDWR);
   
   if(myFile < 0){
       printf("open error\n");
   }

   struct stat myStat = {};
   
   if (fstat(myFile, &myStat)){
       printf("fstat error\n");
   }

   char *addr = mmap(NULL, myStat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);
   
   if (addr == MAP_FAILED){
       printf("mmap error\n");
   }
   
   ftruncate(myFile, 18);
   strcpy(addr, "This is a nice day");
   

   return 0;
}