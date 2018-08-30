#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include<bits/stdc++.h>
//#include"copy.h"
using namespace std;
void deletedir(char *dir)

{
        //char * g="hello";
        //printf("hello %s\n",g);
        //printf("wd=%s\n",wd);
        DIR *dp,*desti;
        struct dirent *entry,*entry1;
        struct stat statbuf;
        if((dp = opendir(dir)) == NULL) 
              {
              fprintf(stderr,"cannot open directory: %s\n", dir);
              return;
              }
        dp=opendir(dir);
        //desti=opendir(wd);
        
        //chdir(wd);
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
              //cout<<"helllllll        "<<h<<endl;
              //char *h1=convert(wd,entry1->d_name);
              //cout<<"wd "<<wd<<endl;
              //char * r=mkdir1(h,wd);
              deletedir(h);
              rmdir(h);//remove directory sub
               }
              else
              { 
              remove(entry->d_name);

              }
        }
rmdir(dir);

//chdir("..");//for new
chdir("..");
//closedir(desti);
//closedir(dp);
}
//////////////////////////folder add done///////////////////////////////////////////////////////////////////////


  
