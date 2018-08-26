#include <unistd.h>
#include <stdio.h>
//#include<type.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libgen.h>
//#include <errno.h>
#include <termios.h>
#include <stdio.h>                   
#include <string>
#include <errno.h>
#include <typeinfo>
#include <sys/stat.h> 
#include <sys/types.h> 
#include<dirent.h>
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

int copyfile1(char* infilename, char* outfileDir)
 {
    FILE* infile; //File handles for source and destination.
    FILE* outfile;
    char outfilename[PATH_MAX];
    const char* folderr;
    //folderr = "C:\\Users\\SaMaN\\Desktop\\Ppln";
    folderr = outfileDir;
    struct stat sb;

    if (stat(folderr, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        infile = fopen(infilename, "r"); // Open the input and output files.

    sprintf(outfilename, "%s/%s", outfileDir, basename(infilename));

    outfile = fopen(outfilename, "w");
    return 1;
    }
    else
    {
        return 0;
    }
   
}

//copy rename.cpp terminal.cpp /home/Desktop

