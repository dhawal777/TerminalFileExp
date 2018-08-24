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
#include "minimal.h"
//#include"canonical.h"
#include "ls.h"
#include "non_canonical.h"
//#include "copy.h"
//#include "xdg_open.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
using namespace std;
stack<string> stack1,stack2;

void func(string s)
{
clear();
printf("%s\n",s.c_str());
struct dirent **namelist;
    	int n;
     
    		n=scandir(s.c_str(),&namelist,NULL,alphasort);
    			
    		int i;
                for(i=0;i<n;i++)
    		{
    			printf("%s\n",namelist[i]->d_name);
  
  		}
 int x,y; 
gotoxy(1,1);
x=1;
y=1;
while(1){

char j;
j=getchar();
printf("%c",j);
if(j=='A')
{
x--;
gotoxy(x,y);
}
if(j=='B')
{
x++;
gotoxy(x,y);
}
if(j=='\n')
{
//string s;
s=s+"/"+namelist[x-2]->d_name;
stack1.push(s);
printf("%s\n",s);
func(s);

}
if(j=='D')
{
printf("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\n");
string s1=stack1.top();
stack1.pop();
stack2.push(s1);
func(s1);


}
if(j=='C')
{
string s1=stack2.top();
stack2.pop();
stack1.push(s1);
func(s1);

}


}
}
int main(int argc,char *argv[])
{

clear();



    printf("You Started In Normal Mode");
    printf("Press CTRL+C or Q to quit.\n");
 struct dirent **namelist;
    	int n;
      
    		n=scandir(argv[1],&namelist,NULL,alphasort);
    int p=n;
int i;
    		for(i=0;i<n;i++)
    		{
                      
    			printf("%s\n",namelist[i]->d_name);
    			
    		}
    		

gotoxy(1,1);
struct termios initial_settings, new_settings;
tcgetattr(0,&initial_settings);
new_settings = initial_settings;
new_settings.c_lflag &= ~ICANON;
new_settings.c_lflag &= ~ECHO;
if(tcsetattr(0, TCSANOW, &new_settings) != 0) 
fprintf(stderr,"could not set attributes\n");
printf("dhawal");

printf("p=%d\n",p);
int x,y;
x=1;
y=1;



while(1){

char j;
j=getchar();
printf("%c",j);
if(j=='A')
{
x--;
gotoxy(x,y);
}
if(j=='B')
{
x++;
gotoxy(x,y);
}
if(j=='\n')
{
string s;
s=argv[1];
s=s+"/"+namelist[x-2]->d_name;
/***************************
**************************/
if(namelist[x-2]->d_type==8)
{
string p ="xdg-open "+s;
system(p.c_str());
}
//xdg_open(s.c_str());
else
{
stack1.push(s);
printf("%s\n",s);
func(s);
}
}
/*******************
***********************/
if(j=='D')
{
printf("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\n");
string s1=stack1.top();
stack1.pop();
stack2.push(s1);
func(s1);

}
if(j=='C')
{
string s1=stack2.top();
stack2.pop();
stack1.push(s1);
func(s1);

}
if(j==':')
{tcsetattr(0,TCSANOW,&initial_settings);
//non_canonical();
clear();
non_canonical();
}
}
tcsetattr(0,TCSANOW,&initial_settings);

}
