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
#include"copydir.h"
#include"deletedir.h"
#include"ls_r.h"
#include "move.h"
#include "print.h"
#include "search.h"
#include "search_wh.h"
//#include "normal_2.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
using namespace std;
string non_canonical(string s,int r,stack<string> stack1,stack<string> stack2)
{
	//while(1)
	//{
		//clear();
	
		int k5=0;
struct winsize w;
ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
gotoxy(w.ws_row-8,0);
printf("                             Welcome to Command Mode ...................PRESS ESC TO QUIT                                              \n");
printf("...........................................................................................................................");
gotoxy(w.ws_row-6,0);


printf("Enter Your Command\n");
int x1=w.ws_row-6+1;
int y=1;
int i;
vector<string> v;
string x;
char c;
while(1)
{  

  
  gotoxy(x1,y);
  c=getchar();
  if(c==27)
    return s;
  if(c=='\n')break;
  else if(c==127){
       y--;
       gotoxy(x1,y);
       cout<<" ";
       x.pop_back();

  }
  else {
        x.push_back(c);
        cout<<c;
        y++;
  }


}
int n1=x.length();
for(i=0;i<n1;)
{
	string s;
	
   while(x[i]!=' '&& i<n1)
   {
      s=s+x[i];
      i++;
   }
   v.push_back(s);
   i++;
}
int n=v.size();
////////////COPY////////////////////////////////////
if(strcmp(v[0].c_str(),"copy")==0)
{

 struct stat mystat;
  stat(v[1].c_str(),&mystat);

   if(S_ISDIR(mystat.st_mode))
   {
    char * r= mkdir1((char*)v[1].c_str(),(char*)v[2].c_str());
     copydir((char*)v[1].c_str(),0,r);
   }
else
{
for(i=1;i<n;i++)
{
int b=copyfile1((char*)v[i].c_str(),(char*)v[n-1].c_str());
if(b==0)
{gotoxy(w.ws_row-4,0);
  printf("Sorry U Entered Wrong Path.................PRESS ENTER TO CONTINUE");

char c1=getchar();
//char c2=getchar();
break;
}
}
}
}
/*if(strcmp(v[0].c_str(),"copy_dir")==0)
{
 char * r= mkdir1((char*)v[1].c_str(),(char*)v[2].c_str());
 copydir((char*)v[1].c_str(),0,r);
}*/

///1 create directory
///2 create file
///3 create file inside directory

else if(strcmp(v[0].c_str(),"create_dir")==0)
{
for(i=1;i<n;i++)
{
	if(n>2)
	{
		string s1=v[n-1]+"/"+v[i];
        const char *folderadd= s1.c_str();
struct stat st = {0};
 if (stat(folderadd, &st) == -1)
 mkdir(folderadd,666);
 else
 {gotoxy(w.ws_row-4,0);
 printf("Folder Exist.................PRESS ENTER TO CONTINUE");
 char c1=getchar();
}
   }
   else
   {
   	 const char *folderadd= v[i].c_str();
struct stat st = {0};
 if (stat(folderadd, &st) == -1)
 mkdir(folderadd,666);
 else
 {gotoxy(w.ws_row-4,0);
 printf("Folder Exist.................PRESS ENTER TO CONTINUE");
 char c1=getchar();
}
   }
}
}
////////////////CREATE FILE/////////////////////////////////
else if(strcmp(v[0].c_str(),"create_file")==0)
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

else if(strcmp(v[0].c_str(),"rename")==0)
{
	string s=".";
	bool y=search1((char*)s.c_str(),0,(char*)v[1].c_str());
	if(y)
	rename((char*)v[1].c_str(),(char*)v[n-1].c_str());
    else
    {
      gotoxy(w.ws_row-4,0);
    cout<<"NO SUCH FILE IN CURRENT DIRECTORY.................PRESS ENTER TO CONTINUE"<<endl;
    char c1=getchar();
  }
}
////////////////////DELETE FILE/////////////////////////////
else if(strcmp(v[0].c_str(),"delete_file")==0)
{
	cout<<"file"<<endl;
	string s=".";
	bool y=search1((char*)s.c_str(),0,(char*)v[1].c_str());
	if(y)
	{remove(v[1].c_str());
    gotoxy(w.ws_row-4,0);
	printf("Deleted Files.................PRESS ENTER TO CONTINUE");
  char c1=getchar();
    }
    else
    {
      gotoxy(w.ws_row-4,0);
    	cout<<"NO SUCH FILE.................PRESS ENTER TO CONTINUE"<<endl;
      char c1=getchar();
    }

}
//////////////////////DELETE FOLDER/////////////////////////
else if(strcmp(v[0].c_str(),"delete_folder")==0)
{
	deletedir((char*)v[1].c_str());
  gotoxy(w.ws_row-4,0);
	printf("Deleted.................PRESS ENTER TO CONTINUE");
  char c1=getchar();
}
/////////////////GOTO////////////////////////////////////////
else if(strcmp(v[0].c_str(),"goto")==0)
{
	return v[1];

}
/////////////////////SNAPSHOT/////////////////////////////////
else if(strcmp(v[0].c_str(),"snapshot")==0)
{
	//cout<<"hello snapshot"<<endl;
//printf("Directory scan of %s\n",topdir);

ls_r((char*)v[1].c_str(),(char*)v[2].c_str());
gotoxy(w.ws_row-4,0);
printf("Snapshot done open file %s\n.................PRESS ENTER TO CONTINUE",(char*)v[2].c_str());
char c1=getchar();
}
////////////////////////MOVE///////////////////////////////////
else if(strcmp(v[0].c_str(),"move")==0)
{

	struct stat mystat;
	stat(v[1].c_str(),&mystat);

   if(!S_ISDIR(mystat.st_mode))
   {
   	int xx=0;
		   for(i=1;i<n;i++)
		   {
		    int b=copyfile1((char*)v[i].c_str(),(char*)v[n-1].c_str());
		     if(b==0)
		    {gotoxy(w.ws_row-4,0);
          printf("Sorry U Entered Wrong Path.................PRESS ENTER TO CONTINUE");
		       xx=1;
           char c1=getchar();
		    break;
		    }
		    remove((char*)v[i].c_str());
		   }
		   if(xx==0)
       {gotoxy(w.ws_row-4,0);
		   printf("Moved Files.................PRESS ENTER TO CONTINUE");
       char c1=getchar();
     }
   }
   else
   {
       char * r= mkdir1((char*)v[1].c_str(),(char*)v[2].c_str());
        move((char*)v[1].c_str(),0,r);
        gotoxy(w.ws_row-4,0);
        printf("+Moved Directories.................PRESS ENTER TO CONTINUE");
        char c1=getchar();
   }
}
///////////////////////////SEARCH/////////////////////////////////////////
else if(strcmp(v[0].c_str(),"search")==0)
{
	//cout<<"hello"<<endl;
	string s1=".";
	bool y=search1((char*)s1.c_str(),0,(char*)v[1].c_str());
	if(y)
	{
		//cout<<"champ"<<endl;
		search2((char*)s1.c_str(),0,(char*)v[1].c_str(),s);
		k5=1;
		//cout<<"I am back"<<endl;
		
	}
	else
	{gotoxy(w.ws_row-4,0);
		cout<<"NO SUCH FILE EXIST.................PRESS ENTER TO CONTINUE"<<endl;
	}	
  //break;
}
else
{
  gotoxy(w.ws_row-4,0);
    cout<<"No Such Command in Explorer.................PRESS ENTER TO CONTINUE"<<endl;
   char c=getchar();
}
if(k5==1)
    {
    	char a,b,c;
    	a=getchar();
    	b=getchar();
    	c=getchar();
    	if(c=='D')
    		{clear();
    		return s;
    	    }
    }
/*{clear();
 //func(s);
print(s,r);
gotoxy(29,0);
k=getchar();
}
else
scanf("%d",&k);
*/
//scanf("%d",&k);
    return s;
}

