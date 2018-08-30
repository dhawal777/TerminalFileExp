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
#include "lsls.h"
#include "non_canonical.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
using namespace std;
stack<string> stack1,stack2;

void func(string s)
{
 clear();
 struct winsize w;
 ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    //printf ("lines %d\n", w.ws_row);
    //printf ("columns %d\n", w.ws_col);
 int r=0;
printf("%s\n",s.c_str());
struct dirent **namelist;
    	int n;
     
    		n=scandir(s.c_str(),&namelist,NULL,alphasort);
    			
    		int i;
lsls(s,0);
 int x,y; 
gotoxy(1,1);
x=1;
y=1;
while(1){

char j,j1,j2;
j=getchar();
if(j=='\n')
{
//string s;
stack1.push(s);
s=s+"/"+namelist[x-2]->d_name;
//stack1.push(s);
printf("%s\n",s);
if(namelist[x-2]->d_type==8)
{
string p ="xdg-open "+s;
system(p.c_str());
}
else
{
//stack1.push(s);
printf("%s\n",s);
func(s);
}
}
else if(j=='h')
{
string p=".";
stack2.push(s);
func(p);
}
else if(j==127)
{
//printf("%cCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",j2);
string s1=stack1.top();
stack1.pop();
stack2.push(s);
func(s1);
}
/*else if(j==':')
{
    tcsetattr(0,TCSANOW,&initial_settings);
    //clear();
    non_canonical();

}*/
else
{
j1=getchar();
j2=getchar();
printf("jjjjjjjjjjjjjjjjjjjjjjj= %c",j2);
if(j2=='A')
{
x--;
if(x<=r)
lsls(s,r--);
gotoxy(x,y);
}
if(j2=='B')
{
++x;
if(x>w.ws_row)
    lsls(s,r++);
gotoxy(x,y);
}

if(j2=='D')
{
string s1=stack1.top();
stack1.pop();
stack2.push(s);
func(s1);


}
if(j2=='C')
{
string s1=stack2.top();
stack2.pop();
stack1.push(s);
func(s1);

}
}
}
}
int main(int argc,char *argv[])
{
  //  struct winsize w;
   // ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    //printf ("lines %d\n", w.ws_row);
    //printf ("columns %d\n", w.ws_col);
//printf("hello\n");

clear();


    struct winsize w;
 ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); 
 
    printf("Welcome to Normal Mode\n");
    //printf("Press CTRL+C or Q to quit.\n");
    struct dirent **namelist;
    int n;
    int r=0;
    n=scandir(argv[1],&namelist,NULL,alphasort);
    int p=n;
    int i;
    lsls(argv[1],0);
     r++;
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
    printf ("lines %d\n", w.ws_row);
    int x,y;
    x=1;
    y=1;

while(1){
string s;
s=argv[1];
char j,j1,j2;
j=getchar();
if(j=='\n')
{
stack1.push(s);
s=s+"/"+namelist[x-2]->d_name;
if(namelist[x-2]->d_type==8)
{
string p ="xdg-open "+s;
system(p.c_str());
}
else
{
//stack1.push(s);
printf("%s\n",s);
func(s);
}
}
else if(j=='h')
{
string p=".";
stack2.push(p);
func(p);
}
else if(j==127)
{
//printf("%cCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",j2);
string s1=stack1.top();
stack1.pop();
stack2.push(s);
func(s1);
}
else if(j==':')
{
    tcsetattr(0,TCSANOW,&initial_settings);
    //clear();
    non_canonical();

}
else
{
j1=getchar();
j2=getchar();
//printf("%cllllllllllllllllllllllllllllllllllllllllllllllll",j2);
    if(j2=='A'&&x>=1)
    {
    x--;
    if(x<=r&&x>=0)
        {clear();
    lsls(s,r--);
    }
    gotoxy(x,y);
    }
    if(j2=='B')
    {
    x++;
    if(x>w.ws_row-10-r)
    {
        clear();
      lsls(s,r++);
    }
    gotoxy(x-r,y);
    }

    if(j2=='D')
    {
    //printf("%cCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",j2);
    string s1=stack1.top();
    stack1.pop();
    stack2.push(s);
    func(s1);

    }
    if(j2=='C')
    {
    //printf("%cllllllllllllllllllllllllllllllllllllllllllllllll",j2);
    string s1=stack2.top();
    stack2.pop();
    stack1.push(s);
    func(s1);

}
}
}
tcsetattr(0,TCSANOW,&initial_settings);

}
