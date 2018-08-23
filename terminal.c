#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>                   
#include <string.h>
#include <errno.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include<dirent.h>
#include "minimal.h"
#include "ls.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

int main(int argc,char **argv)
{
    int c;
 
    if (terminal_init()) {
        if (errno == ENOTTY)
            fprintf(stderr, "This program requires a terminal.\n");
        else
            fprintf(stderr, "Cannot initialize terminal: %s.\n", strerror(errno));
        return EXIT_FAILURE;
    }
clear();
gotoxy(1,1);
 int fd, res;
        struct termios oldtio,newtio;
        char buf[255];
        
        fd = open("/dev/ttyS1", O_RDWR | O_NOCTTY ); 
        if (fd <0) {perror("/dev/ttys1"); exit(-1); }
        
        tcgetattr(fd,&oldtio); /* save current port settings */
        
       // bzero(&newtio, sizeof(newtio));
        //newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
        //newtio.c_iflag = IGNPAR;
        //newtio.c_oflag = 0;
        
        /* set input mode (non-canonical, no echo,...) */
        newtio.c_lflag = 1;
    printf("Press CTRL+C or Q to quit.\n");
//printf("%c\n",**argv);
 struct dirent **namelist;
    	int n;
        //printf("%d\n",argc);
    	
    		n=scandir(".",&namelist,NULL,alphasort);
    
    		while (n--)
    		{
    			printf("%s\n",namelist[n]->d_name);
    			free(namelist[n]);
    		}
    		free(namelist);



//ls();
struct stat st = {0};
 if (stat("/home/dhawal/Desktop/cfolder", &st) == -1)
 mkdir("/home/dhawal/Desktop/cfolder",666); 
//printf("hello\n");
int r=1;
    while ((c = getc(stdin)) != EOF) {
       if (c >= 33 && c <= 126)
            printf("0x%02x = 0%03o = %3d = '%c'\n", c, c, c, c);
        else
            printf("0x%02x = 0%03o = %3d\n", c, c, c);
 
        if (c == 3 || c == 'Q' || c == 'q')
            {
                   r=0;
                  break;
            }
    }
    printf("Done.\n");
 
    return EXIT_SUCCESS;
}
