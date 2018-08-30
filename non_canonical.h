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
//#include "search.h"
#include"copydir.h"
#include"deletedir.h"
#include"ls_r.h"
#include "move.h"
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
	//while(1)
	//{
		//clear();
struct winsize w;
ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
gotoxy(w.ws_row-10,0);
printf("                                              Welcome to Command Mode                                               \n");
printf("...........................................................................................................................");
gotoxy(w.ws_row-8,0);


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
}
if(strcmp(v[0].c_str(),"copy_dir")==0)
{
 char * r= mkdir1((char*)v[1].c_str(),(char*)v[2].c_str());
 copydir((char*)v[1].c_str(),0,r);
}
///1 create directory
///2 create file
///3 create file inside directory
if(strcmp(v[0].c_str(),"create_dir")==0)
{
for(i=1;i<n;i++)
{
	if(n>2)
	{
		string s=v[n-1]+"/"+v[i];
        const char *folderadd= s.c_str();
struct stat st = {0};
 if (stat(folderadd, &st) == -1)
 mkdir(folderadd,666);
 else
 printf("Folder Exist");
   }
   else
   {
   	 const char *folderadd= v[i].c_str();
struct stat st = {0};
 if (stat(folderadd, &st) == -1)
 mkdir(folderadd,666);
 else
 printf("Folder Exist");
   }
}
}
if(strcmp(v[0].c_str(),"create_file")==0)
{
	const char* folderr;
    //folderr = "C:\\Users\\SaMaN\\Desktop\\Ppln";
    folderr = v[n-1].c_str();
    struct stat sb;

    if (stat(folderr, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
    	for(i=1;i<n-1;i++)
    	{
         string s=v[n-1]+"/"+v[i];
         char *fileadd=(char *)s.c_str();
         FILE *fp;
        fp=fopen(fileadd,"w");
        fclose(fp);
        }
    }
    else
    {
    	for(i=0;i<n;i++)
    	{
    	FILE *fp;
        fp=fopen(v[i].c_str(),"w");
        fclose(fp);
        }
    }
}


////////////////////////////
//RENAME
/////////////////////////

if(strcmp(v[0].c_str(),"rename")==0)
{
	rename((char*)v[1].c_str(),(char*)v[n-1].c_str());
}

if(strcmp(v[0].c_str(),"delete_file")==0)
{
	remove(v[1].c_str());
}
if(strcmp(v[0].c_str(),"delete_folder")==0)
{
	deletedir((char*)v[1].c_str());
}
if(strcmp(v[0].c_str(),"goto")==0)
{
	//string p ="xdg-open "+v[1];
      system(v[1].c_str());////////////////NOT WORKING
}
if(strcmp(v[0].c_str(),"snapshot")==0)
{
	cout<<"hello snapshot"<<endl;
//printf("Directory scan of %s\n",topdir);

ls_r((char*)v[1].c_str(),(char*)v[2].c_str());
printf("done.\n");
}
if(strcmp(v[0].c_str(),"move")==0)
{

	struct stat mystat;
	stat(v[1].c_str(),&mystat);

   if(!S_ISDIR(mystat.st_mode))
   {
		   for(i=1;i<n;i++)
		   {
		    int b=copyfile1((char*)v[i].c_str(),(char*)v[n-1].c_str());
		     if(b==0)
		    {printf("Sorry U Entered Wrong Path");
		    break;
		    }
		    remove((char*)v[i].c_str());
		   }
   }
   else
   {
       char * r= mkdir1((char*)v[1].c_str(),(char*)v[2].c_str());
        move((char*)v[1].c_str(),0,r);
   }
}





scanf("%d",&k);

}
