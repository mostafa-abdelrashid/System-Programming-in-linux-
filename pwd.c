#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>


int main(int argc,char** argv){
        if(argc!=1){
                fprintf(stderr,"Usage : %s",argv[0]);
                return 1;
        }
        char buf[PATH_MAX];
        char* pwd= getcwd(buf,PATH_MAX);
        if(pwd  == NULL ){
                fprintf(stderr,"error getting the current dir");
                return 1;
        }
        printf("Current directory : %s\n",pwd);
        return 0;



}
