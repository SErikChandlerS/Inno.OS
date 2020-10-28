#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   int file1 = open("ex1.txt", O_RDWR);
   int file2 = open("ex1.memcpy.txt", O_RDWR);

   if(file1 < 0 | file2 < 0){
       printf("open error\n");
   }

   struct stat myStat1 = {};
   struct stat myStat2 = {};
   if (fstat(file1, &myStat1) | fstat(file2, &myStat2)){
       printf("fstat error\n");
   }

   char *addr1 = mmap(NULL, myStat1.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file1, 0);
   char *addr2 = mmap(NULL, myStat2.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file2, 0);
   
   if (addr1 == MAP_FAILED | addr2 == MAP_FAILED){
       printf("mmap error\n");
   }
   
   ftruncate(file2, strlen(addr1));
   memcpy(addr2, addr1, strlen(addr1));
   

   return 0;
}