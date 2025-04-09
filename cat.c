#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define count 100
int main (int argc,char** argv){

        if(argc!=2){
                printf("Usage: %s file-name\n",argv[0]);
                exit(-1);
        }

        int fd=open(argv[1],O_RDONLY);
        if(fd<0){
                printf("can't open the file");
                exit(-5);
        }
        int buf[count];
        int output;
        while((output = read(fd,buf,count))>0){

                if(write(1,buf,output)<0){
                        printf("failed write");
                        exit(-10);
                }
        }
        if(close(fd)<0){
                printf("can't close the file");
        }

        return 0;

}
