#include<bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
using namespace std;
bool ans=false;
void delete1(char *dir, int depth)
{
DIR *dp;
struct dirent *entry;
struct stat statbuf;
if((dp = opendir(dir)) == NULL) {
printf("shutt\n");
fprintf(stderr,"cannot open directory: %s\n", dir);
return;
}
chdir(dir);
while((entry = readdir(dp)) != NULL) {
lstat(entry->d_name,&statbuf);
if(S_ISDIR(statbuf.st_mode)) {
/* Found a directory, but ignore . and .. */
if(strcmp(".",entry->d_name) == 0 || 
strcmp("..",entry->d_name) == 0)
continue;
/*{
	printf("hello");
remove(entry->d_name);
}*/
//printf("%*s%s/\n",depth,"",entry->d_name);
/* Recurse at a new indent level */
delete1(entry->d_name,depth+4);
//if(entry->d_type==4)
rmdir(entry->d_name);
}
else
{
	remove(entry->d_name);
	//printf("%*s%s\n",depth,"",entry->d_name);
}
}
printf("hello\n");
rmdir(entry->d_name);
chdir("..");
//closedir(dp);
}
bool printdir(char *dir, int depth,char *check)
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
printdir(entry->d_name,depth+4,check);
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
int main()
{
string x;
cin>>x;
char *topdir = ".";
char * str4 ="/";
printf("Directory scan of %s\n",topdir);
bool found=printdir(topdir,0,(char*)x.c_str());
if(found)
{
      char * str3 = (char *) malloc(4 + strlen(topdir)+ strlen((char*)x.c_str()) );
      strcpy(str3, topdir);
      strcat(str3,str4);
      strcat(str3, (char*)x.c_str());
      printf("Directory scan of %s\n",str3);
      delete1("/home/dhawal/Desktop/ostemp/dhawal",0);
}
else
printf("Not Found");
}
