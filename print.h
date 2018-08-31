#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>                   
#include <string>
#include <errno.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include<dirent.h>
#include<bits/stdc++.h>
#include<sys/ioctl.h>
//#include "lsls.h"
//#include "non_canonical.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
using namespace std;
int  print(string s,int r)
{

struct dirent **namelist;
    	int n;
     
    		n=scandir(s.c_str(),&namelist,NULL,alphasort);
    			
    		//int i;
clear();    		
lsls(s,r);
gotoxy(1,1);
return 0;
}