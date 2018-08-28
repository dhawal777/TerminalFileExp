#include<bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
using namespace std;
void filewrite(char *c,char * f)
{
FILE *fptr;

   fptr = fopen(f, "a");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   
  // printf("Enter a sentence:\n");
  // gets(sentence);

   fprintf(fptr,"%s\n",c);
   fclose(fptr);
}
void printdir(char *dir, int depth,char *file_name)
{
DIR *dp;
struct dirent *entry;
struct stat statbuf;
if((dp = opendir(dir)) == NULL) {
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

//printf("%*s%s/\n",depth,"",entry->d_name);
/* Recurse at a new indent level */
printdir(entry->d_name,depth+4,file_name);
filewrite(entry->d_name,file_name);
}
else
{ 
	filewrite(entry->d_name,file_name);
	//printf("%*s%s\n",depth,"",entry->d_name);
}
}
chdir("..");
closedir(dp);
}
int main(int argc, char* argv[])
{
char *topdir = ".";
char *c="output.txt";
if (argc >= 2)
topdir=argv[1];
printf("Directory scan of %s\n",topdir);
printdir(topdir,0,c);
printf("done.\n");
}
