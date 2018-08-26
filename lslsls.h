#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>
#include<termios.h>
#include <grp.h>
#include<time.h>
#include<sys/ioctl.h>
#include<bits/stdc++.h>
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
using namespace std;

void lslsls(string s)
{
	struct termios initial_settings, new_settings;
tcgetattr(0,&initial_settings);
new_settings = initial_settings;
new_settings.c_lflag &= ~ICANON;
new_settings.c_lflag &= ~ECHO;
if(tcsetattr(0, TCSANOW, &new_settings) != 0) 
fprintf(stderr,"could not set attributes\n");
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    struct passwd  *pwd;
    struct group   *grp;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    char buf[512];
    mydir = opendir(s.c_str());
    vector<struct dirent*> v;
    int i=0;
    while((myfile = readdir(mydir)) != NULL)
    {
        v.push_back(myfile);
    }
   int j=-1;
   int n=v.size();
   while(i<n)
   {
      j++;
   for(i=j;i<min(w.ws_row-1+j,n);i++)
   {
   	myfile=v[i];
        sprintf(buf, "%s/%s", s.c_str(), myfile->d_name);
        stat(buf, &mystat);
   int fileMode = mystat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
  
        if ((fileMode & S_IRUSR) && (fileMode & S_IREAD))
          printf("r");
        else
          printf("-");
        if ((fileMode & S_IWUSR) && (fileMode & S_IWRITE)) 
          printf("w");
        else
          printf("-");
        if ((fileMode & S_IXUSR) && (fileMode & S_IEXEC))
          printf("x");
        else
          printf("-");
        /* Check group permissions */
        if ((fileMode & S_IRGRP) && (fileMode & S_IREAD))
          printf("r");
        else
          printf("-");
        if ((fileMode & S_IWGRP) && (fileMode & S_IWRITE))
          printf("w");
        else
          printf("-");
        if ((fileMode & S_IXGRP) && (fileMode & S_IEXEC))
          printf("x");
        else
          printf("-");
        /* check other user permissions */
        if ((fileMode & S_IROTH) && (fileMode & S_IREAD))
          printf("r");
        else
          printf("-");
        if ((fileMode & S_IWOTH) && (fileMode & S_IWRITE))
          printf("w");
        else
          printf("-");
        if ((fileMode & S_IXOTH) && (fileMode & S_IEXEC))
          printf("x");
        else
        printf("-");
          printf("     ");
            if ((pwd = getpwuid(mystat.st_uid)) != NULL)
              printf("%s ", pwd->pw_name);
             if ((grp = getgrgid(mystat.st_gid)) != NULL)
        printf("%s ", grp->gr_name);
          
           printf("%lld ",(long long) mystat.st_size);
           printf("%lld ",(long long) mystat.st_blocks);
           if(myfile->d_type!=8)
          printf("\033[1;34m%s\033[0m",myfile->d_name);
           else
           printf("%s ",myfile->d_name);
           printf("%s", ctime(&mystat.st_ctime));
    }
 char   j1=getchar();
 char    j2=getchar();
 char j3=getchar();
 if(j3=='B')
 	{clear();
 		gotoxy(1,1);
 	continue;
    }
}
    closedir(mydir);
}

   