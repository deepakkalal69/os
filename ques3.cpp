#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char *argv[]){
    system("cat /proc/meminfo | awk 'NR==1'");
    system("cat /proc/meminfo | awk 'NR==2'");
    system("cat /proc/meminfo | awk '{ if (NR==1) a=$2; if(NR==2) b=$2 }END {print a-b} '");
    return 0;
}

