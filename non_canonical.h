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
#include "copy.h"
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
int i,k;
vector<string> v;
string x;
while(cin.peek()!='\n')
{cin>>x;
v.push_back(x);
}
int n=v.size();
if(strcmp(v[0].c_str(),"copy")==0)
{
for(i=1;i<n;i++)
{
int b=copyfile1((char*)v[i].c_str(),(char*)v[n-1].c_str());
if(b==0)
{printf("Sorry U Entered Wrong Path");
break;
}
}
printf("Copied");
scanf("%d",&k);
}
}

