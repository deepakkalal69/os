#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
    // Kernel version
    system("cat /proc/sys/kernel/osrelease");

    // CPU type and model
    system("cat /proc/cpuinfo | awk 'NR==3,NR==4 {print}\n'");
    
    return 0;
}

