#include <pwd.h>
#include <grp.h>
#include<time.h>
#include<dirent.h>
#include<sys/ioctl.h>
#include<bits/stdc++.h>
//#include "minimal.h"
//#include"canonical.h"
//#include "non_canonical.h"
//#include "copy.h"
//#include "xdg_open.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
using namespace std;
bool ans1=false;
vector<string> v;
void search2(char *dir, int depth,char *check)
{
DIR *dp;

struct dirent *entry;
struct stat statbuf;
if((dp = opendir(dir)) == NULL) {
fprintf(stderr,"cannot open directory: %s\n", dir);
//return 
//return false;
}
chdir(dir);
while((entry = readdir(dp)) != NULL) {
lstat(entry->d_name,&statbuf);
if(S_ISDIR(statbuf.st_mode)) {
/* Found a directory, but ignore . and .. */
if(strcmp(".",entry->d_name) == 0 || 
strcmp("..",entry->d_name) == 0)
continue;

if(strcmp(entry->d_name,check)==0)
{
ans1=true;
}

//printf("%*s%s/\n",depth,"",entry->d_name);
/* Recurse at a new indent level */
search2(entry->d_name,depth+4,check);
}
else 
{
if(strcmp(entry->d_name,check)==0)
{
    string s1="/";
	string s=dir;
	s=s+s1+entry->d_name;
	v.push_back(s);
	//cout<<"hello strcmp"<<endl;
    ans1=true;
}
//printf("%*s%s\n",depth,"",entry->d_name);
}
}
chdir("..");
closedir(dp);
clear();
gotoxy(1,1);
for(int i=0;i<v.size();i++)
   cout<<v[i]<<endl;
//gotoxy(29,0);
struct winsize w;
ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
gotoxy(w.ws_row-8,0);
printf("                                              Welcome to Command Mode                                               \n");
printf("...........................................................................................................................");
gotoxy(w.ws_row-6,0);
}