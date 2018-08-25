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
int main()
{
vector<string> v;
string x;
while(cin.peek()!='\n')
{cin>>x;
v.push_back(x);
}
int n=v.size();
int i;
for(i=0;i<n;i++)
rename((char*)v[i].c_str(),(char*)v[n-1].c_str());
}
//copy foo.txt bar.txt baz.mp4 ~/foobar

