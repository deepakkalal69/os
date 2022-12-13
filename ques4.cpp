#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char *argv[]){
    if (argc < 2){
        cout << "Please enter a valid file" << endl;
        return 0;
    }
    struct stat s;

    if (stat(argv[1], &s) < 0) cout << "Error in getting file information" << endl;

    else{
        cout << "Owner UID \t\t\t\t : " << s.st_uid << endl;
        cout << "Group ID \t\t\t\t : " << s.st_gid << endl;
        cout << "Access Info \t\t\t : " << s.st_mode << endl;
        cout << "Access Time \t\t\t : " << s.st_atime << endl;
        cout << "File Size (in bytes) \t : " << s.st_size << endl;
    }
    
    return 0;
}


