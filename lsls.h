#include <unistd.h>
#include <stdio.h>
//#include<type.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>                   
#include <string>
#include <errno.h>
#include <typeinfo>
#include <sys/stat.h> 
#include <sys/types.h> 
#include<dirent.h>
#include<sys/ioctl.h>
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
void lsls(string s,int x)
{
//cout<<" *********************************************"<<endl;
   /*struct termios initial_settings, new_settings;
tcgetattr(0,&initial_settings);
new_settings = initial_settings;
new_settings.c_lflag &= ~ICANON;
new_settings.c_lflag &= ~ECHO;
if(tcsetattr(0, TCSANOW, &new_settings) != 0) 
fprintf(stderr,"could not set attributes\n");
*/

    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    int ret;
    struct passwd  *pwd;
    struct group   *grp;
struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
 struct dirent **namelist;
    	int n;
     //cout<<s.c_str()<<endl;
    n=scandir(s.c_str(),&namelist,NULL,alphasort);
  int i;
     //cout<<n<<endl;
        //ret=stat(s.c_str(), &mystat);
  gotoxy(3,1);
    i=x;
    int j=3,k=1;
  for(;i<min(w.ws_row-10+x,n);i++)
{
  k=1;
//cout<<"hello"<<endl;
  string d=s+"/"+namelist[i]->d_name;
    stat(d.c_str(),&mystat);
   int fileMode = mystat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
   //cout<<"hello"<<endl;
        if (S_ISDIR(mystat.st_mode))
          printf("d");
        else
          printf("-");
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
          /* because this is the last permission, leave 3 blank spaces after print */
          printf("x");
        else
        printf("-");
         // printf("   ");
          k=k+11;
          gotoxy(j,k);
            if ((pwd = getpwuid(mystat.st_uid)) != NULL)
              printf("%s", pwd->pw_name);
            k=k+10;
            gotoxy(j,k);
             if ((grp = getgrgid(mystat.st_gid)) != NULL)
        printf("%s", grp->gr_name);
             k=k+10;
             gotoxy(j,k);
         printf("%lld",(long long) mystat.st_size);
           //printf("%lld ",(long long) mystat.st_blocks);
//Last status change:
             k=k+6;
             gotoxy(j,k);
           if(namelist[i]->d_type!=8)
          printf("\033[1;34m%s\033[0m",namelist[i]->d_name);
           else
           printf("%s",namelist[i]->d_name);

         gotoxy(j,k+30);
          printf("%s",ctime(&mystat.st_mtime));
          j++;
    }
     gotoxy(3,1);
   // closedir(mydir);
}
