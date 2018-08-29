#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include"copy.h"
using namespace std;
char * mkdir1(char *s,char *d)
{
  char * bname = basename(s); 
  //printf("bname=%s\n",bname);
  char *folderadd= bname;
  char * str="/";
  char * str4 = (char *) malloc(1 + strlen(s)+ strlen(d) );
  strcpy(str4,d);
  strcat(str4,str);
  strcat(str4,bname);

 // const char * e=(const char *)d + (const char *)str3 + (const char*)folderadd;
 //string e=d+str3+folderadd;
 //cout<<e<<endl;
  struct stat st = {0};
  if (stat(str4, &st) == -1)
  { 
     mkdir(str4,0777);
  }
  return str4;
 }
char *convert(char * a,char *b)
{
            char * str3 = (char *) malloc(1 + strlen(a)+ strlen(b) );
             strcpy(str3,a);
             char *str="/";
              strcat(str3,str);
             strcat(str3,b);

             return str3;
}
 void printdir(char *dir, int depth,char *wd)

{
        char * g="hello";
        printf("hello %s\n",g);
        printf("wd=%s\n",wd);
        DIR *dp,*desti;
        struct dirent *entry,*entry1;
        struct stat statbuf;
        if((dp = opendir(dir)) == NULL) 
              {
              fprintf(stderr,"cannot open directory: %s\n", dir);
              return;
              }
        dp=opendir(dir);
        desti=opendir(wd);
        
        chdir(wd);
        chdir(dir);
        //entry1=readdir(desti);
        //cout<<"outside"<<endl;
        while((entry = readdir(dp)) != NULL)
        {
          // cout<<"hello"<<endl;
        lstat(entry->d_name,&statbuf);
          
        if(S_ISDIR(statbuf.st_mode))
               {
              if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
                continue;
              //cout<<endl;
              
              char *h=convert(dir,entry->d_name);
              cout<<"helllllll        "<<h<<endl;
              //char *h1=convert(wd,entry1->d_name);
              //cout<<"wd "<<wd<<endl;
              char * r=mkdir1(h,wd);
              printdir(h,depth+4,r);
              rmdir(h);//remove directory sub
               }
              else
              { 
              int b=copyfile1(entry->d_name,wd);//copying file
              if(b==0)
              {printf("Sorry U Entered Wrong Path");
              break;
              }
              remove(entry->d_name);

              }
        }
rmdir(dir);

//chdir("..");//for new
chdir("..");
closedir(desti);
//closedir(dp);
}
int main()
{
  string s,d;
  cin>>s>>d;
char * r= mkdir1((char*)s.c_str(),(char*)d.c_str());
 printdir((char*)s.c_str(),0,r);
}
//////////////////////////folder add done///////////////////////////////////////////////////////////////////////


  
