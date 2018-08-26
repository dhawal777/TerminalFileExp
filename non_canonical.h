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
//#include "minimal.h"
//#include"canonical.h"
//#include "ls.h"
//#include "copy.h"
//#include "xdg_open.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
using namespace std;
void non_canonical()
{
	printf("                                              Welcome to Command Mode                                               \n");
gotoxy(29,0);
printf("...........................................................................................................................");
gotoxy(30,0);

printf("Enter Your Command\n");
vector<string> v;
int n,i,k;
scanf("%d",&n);
printf("%d",n);
scanf("%d",&k);
}

