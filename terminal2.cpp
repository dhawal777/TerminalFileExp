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
string s5;
void func(string s,stack<string> stack1,stack<string> stack2,string s5)
{

   
 while(1)
 {

  clear();
  int r=0;
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
   
 
printf("%s\n",s.c_str());
struct dirent **namelist;
        int n;
     
            n=scandir(s.c_str(),&namelist,NULL,alphasort);
                
            int i;
lsls(s,0);
r++;
 int x,y,q; 
gotoxy(3,1);
q=3;
x=3;
y=1;
while(1){

char j,j1,j2;
j=getchar();
if(j=='\n')
{
    if(s==s5&&(strcmp(namelist[q-3]->d_name,"..")==0||strcmp(namelist[q-3]->d_name,".")==0))
        continue;
stack1.push(s);
s=s+"/"+namelist[q-3]->d_name;
/////////////////OPENING FILE//////////////////////////////////////////////
if(namelist[q-3]->d_type==8)
{
string p ="xdg-open "+s;
system(p.c_str());
}
else
{
func(s,stack1,stack2,s5);
}
}
else if(j=='h')///////////////////////HOME//////////////////////////////
{
//string p=".";
stack2.push(s);
func(s5,stack1,stack2,s5);
}
else if(j==127)////////////////BACKSPACE////////////////////////////////
{
string s1=stack1.top();
stack1.pop();
stack2.push(s);
func(s1,stack1,stack2,s5);
}
else if(j==':')////////////////////ENTERING COMMAND MODE//////////////////////
{
    break;

}
else
{
j1=getchar();
j2=getchar();
if(j2=='A')///////////////////////////////UPWARD KEY///////////////////////////////
    {
    x--;
    q--;
    if(x==2&&r==1)
    {
        q++;
        x++;
        gotoxy(x,y);
    }
    else if(x==2&&r>1)
    {
        x++;
        clear();
        lsls(s,r--);
        gotoxy(x,y);
    }
    else
        gotoxy(x,y);
    }
    if(j2=='B')///////////////////////DOWNWARD KEY/////////////////////////////
    {
    x++;
    q++;
    if(q==n+4)
    {
      x--;
      q--;
      gotoxy(x,y);
    }
    else if(x==w.ws_row-7&&r<n-(w.ws_row-9))
    {
       x--;
        clear();
      lsls(s,r++);
      gotoxy(x,y);
    }
    else if(x==w.ws_row-7&&r==n-w.ws_row+9)
    {
        q--;
        x--;
        gotoxy(x,y);
    }
    else
    gotoxy(x,y);
    }

if(j2=='D'&&!stack1.empty())//////////////////////LEFT KEY//////////////////////////
{
string s1=stack1.top();
stack1.pop();
stack2.push(s);
func(s1,stack1,stack2,s5);


}
if(j2=='C'&&!stack2.empty())//////////////////RIGHT KEY/////////////////////////////////
{
string s1=stack2.top();
stack2.pop();
stack1.push(s);
func(s1,stack1,stack2,s5);

}
}
}
string s1=non_canonical(s,r,stack1,stack2);
func(s1,stack1,stack2,s5);
}

}
int main(int argc,char *argv[])
{

clear();


    struct winsize w;
 ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); 
 
    ///SETTING INVERT///////////////////
    struct termios initial_settings, new_settings;
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    if(tcsetattr(0, TCSANOW, &new_settings) != 0) 
    fprintf(stderr,"could not set attributes\n");
while(1)
{
printf("Welcome to Normal Mode\n");
   
    struct dirent **namelist;
    int n;
    int r=0;
    n=scandir(argv[1],&namelist,NULL,alphasort);
    int p=n;
    int i;
    lsls(argv[1],0);
     r++;
    gotoxy(3,1);
    int x,y,q;
    x=3;
    q=3;
    y=1;
string s;
while(1){

s=argv[1];
string s5=argv[1];
char j,j1,j2;
j=getchar();
if(j=='\n')
{
    if(strcmp(namelist[q-3]->d_name,"..")==0||strcmp(namelist[q-3]->d_name,".")==0)
        continue;
stack1.push(s);
s=s+"/"+namelist[q-3]->d_name;
if(namelist[q-3]->d_type==8)
{
string p ="xdg-open "+s;
system(p.c_str());
}
else
{
func(s,stack1,stack2,s5);
}
}
else if(j=='h')////////////////////HOME///////////////////////////////
{
//string p=".";
stack2.push(s);
func(s5,stack1,stack2,s5);
}
else if(j==127)
{

string s1=stack1.top();
stack1.pop();
stack2.push(s);
func(s1,stack1,stack2,s5);
}
else if(j==':')
{
    break;

}
else
{
j1=getchar();
j2=getchar();
    if(j2=='A')
    {
    x--;
    q--;
    if(x==2&&r==1)
    {
        q++;
        x++;
        gotoxy(x,y);
    }
    else if(x==2&&r>1)
    {
        x++;
        clear();
        lsls(s,r--);
        gotoxy(x,y);
    }
    else
        gotoxy(x,y);
    }
    if(j2=='B')
    {
    x++;
    q++;
    if(q==n+4)
    {
      x--;
      q--;
      gotoxy(x,y);
    }
    else if(x==w.ws_row-7&&r<n-(w.ws_row-9))
    {
       x--;
        clear();
      lsls(s,r++);
      gotoxy(x,y);
    }
    else if(x==w.ws_row-7&&r==n-w.ws_row+9)
    {
        q--;
        x--;
        gotoxy(x,y);
    }
    else
    gotoxy(x,y);
    }
   if(j2=='D'&&!stack1.empty())
    {
    
    string s1=stack1.top();
    stack1.pop();
    stack2.push(s);
   func(s1,stack1,stack2,s5);

    }
    if(j2=='C'&&!stack2.empty())
    {
    string s1=stack2.top();
    stack2.pop();
    stack1.push(s);
    func(s1,stack1,stack2,s5);

}
}
}
string s1=non_canonical(s,r,stack1,stack2);
func(s1,stack1,stack2,s5);
}

}
