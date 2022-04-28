#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define RWRWRW (S_IWUSR | S_IRUSR |S_IWGRP | S_IRGRP| S_IWOTH | S_IROTH)

int main(int argc, char* argv[]){

        if(argc!=4){
        printf("U need enter the 3 file name. \n");
        exit(-1);
}
umask(S_IWGRP | S_IRGRP | S_IWOTH | S_IROTH);  //umask(077);
int fd1=open(argv[1],O_CREAT | O_WRONLY | O_TRUNC,RWRWRW);
char buf1[]="Only owner can read and write this file.";
write(fd1,buf1,sizeof(buf1)-1);

umask(S_IROTH | S_IWOTH);   //umask(007);
int fd2=open(argv[2],O_CREAT | O_WRONLY | O_TRUNC,RWRWRW);
char buf2[]="Groups and owner can read and write this file.";
write(fd2,buf2,sizeof(buf2)-1);

umask(0);
int fd3=open(argv[3],O_CREAT | O_WRONLY | O_TRUNC,RWRWRW);
char buf3[]="Everyone can read and write this file.";
write(fd3,buf3,sizeof(buf3)-1);

close(fd1);
close(fd2);
close(fd3);
return 0;
}
