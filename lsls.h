#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
void lsls(string s)
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    struct passwd  *pwd;
    struct group   *grp;

    char buf[512];
    mydir = opendir(s.c_str());
    while((myfile = readdir(mydir)) != NULL)
   {
    // buf=s.c_str();
        //lsls(s)
        ///YAHA STACK USE KARNA HAI AUR USME MYFILE_DNAME PUSH KARNA HAI
        sprintf(buf, "%s/%s", s.c_str(), myfile->d_name);
        stat(buf, &mystat);
        //printf("I-node number:            %ld\n", (long) mystat.st_ino);

          // printf("Mode:                     %lo (octal)\n",
                   //(unsigned long) mystat.st_mode);

   int fileMode = mystat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
     //printf("chmod: %o\n", fileMode);
          // int fileMode;       
 
        /* print a leading dash as start of file/directory permissions */
        //printf("-");
       // fileMode = fileattrib.st_mode;
        /* Check owner permissions */
//printf("\n");
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
          printf("     ");
           //printf("Link count:               %ld\n", (long) mystat.st_nlink);
          /* printf("UID=%ld   GID=%ld ",
                   (long) mystat.st_uid, (long) mystat.st_gid);*/
            if ((pwd = getpwuid(mystat.st_uid)) != NULL)
              printf("%s ", pwd->pw_name);
             if ((grp = getgrgid(mystat.st_gid)) != NULL)
        printf("%s ", grp->gr_name);
          // printf("Preferred I/O block size: %ld bytes\n",
            //       (long) mystat.st_blksize);
           printf("%lld ",(long long) mystat.st_size);
           printf("%lld ",(long long) mystat.st_blocks);
//Last status change:
           if(myfile->d_type!=8)
          printf("\033[1;34m%s\033[0m",myfile->d_name);
           else
           printf("%s ",myfile->d_name);
           printf("%s", ctime(&mystat.st_ctime));
//Last file access: 
          // printf("%s ", ctime(&mystat.st_atime));
//Last file modification:
         //  printf("%s ", ctime(&mystat.st_mtime));
        //printf("%zu",mystat.st_size);

       // printf("%s ", myfile->d_name);
        //printf("%
    }
    closedir(mydir);
}
