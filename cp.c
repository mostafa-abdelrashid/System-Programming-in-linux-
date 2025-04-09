#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#define size 100
int main(int argc ,char** argv){

        if(argc !=3){
                fprintf(stderr,"invalid number of inputs\n");
                return 1;
        }
        int fd_dest = open(argv[2],O_RDWR | O_CREAT | O_TRUNC,0644);
        if(fd_dest<0){
                fprintf(stderr,"Can't open destination file\n");
                return 2;
        }
        int fd_src = open(argv[1],O_RDONLY);
        if(fd_src<0){
                fprintf(stderr,"Can't open source file\n");
                return 3;
        }

        char buff[PATH_MAX];
        int bytes_count;
        while((bytes_count=read(fd_src,buff,PATH_MAX))>0){
                if(write(fd_dest,buff,bytes_count)<0){
                fprintf(stderr,"can't write in this file\n");
                return 4;
                }
        }





        if(close(fd_dest)<0){
        fprintf(stderr,"can't close the destination file\n");
        return 5;
        }

        if(close(fd_src)<0){
        fprintf(stderr,"can't close the source file\n");
        return 6;
        }

        return 0;


}
