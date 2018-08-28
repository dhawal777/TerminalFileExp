#include <pwd.h>
#include <grp.h>
#include<time.h>
#include<bits/stdc++.h>
//#include "minimal.h"
//#include"canonical.h"
//#include "non_canonical.h"
//#include "copy.h"
//#include "xdg_open.h"
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
using namespace std;
bool ans=false;

bool search1(char *dir, int depth,char *check)
{
DIR *dp;
struct dirent *entry;
struct stat statbuf;
if((dp = opendir(dir)) == NULL) {
fprintf(stderr,"cannot open directory: %s\n", dir);
return false;
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
ans=true;

//printf("%*s%s/\n",depth,"",entry->d_name);
/* Recurse at a new indent level */
search1(entry->d_name,depth+4,check);
}
else 
{
if(strcmp(entry->d_name,check)==0)
ans=true;
//printf("%*s%s\n",depth,"",entry->d_name);
}
}
chdir("..");
closedir(dp);
return ans;
}