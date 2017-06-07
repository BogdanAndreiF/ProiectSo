#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
void printdir(char *dir, int depth)
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
        
            if(strcmp(".",entry->d_name) == 0 ||
                strcmp("..",entry->d_name) == 0)
                continue;
            printf("%*s%s/\n",depth,"",entry->d_name);
    
            printdir(entry->d_name,depth+4);
            
            
        }
        else {
            printf("%*s%s\n",depth,"",entry->d_name);
            /* printf("\n\nInformatii despre %s", entry->d_name);
                printf("\n---------------------------------------------------------------------------------\n");
                printf("Dimensiune: %ld\n",statbuf.st_size);
                printf("Numarul de legaturi : %d\n",statbuf.st_nlink);
                printf("Numarul de inoduri : %d\n",statbuf.st_ino);
                printf("Permisiuni :");
                printf((statbuf.st_mode&S_IRUSR)?"r":"-");
                printf((statbuf.st_mode&S_IWUSR)?"w":"-");
                printf((statbuf.st_mode&S_IXUSR)?"x":"-");
                printf((statbuf.st_mode&S_IRGRP)?"r":"-");
                printf((statbuf.st_mode&S_IWGRP)?"w":"-");
                printf((statbuf.st_mode&S_IXGRP)?"x":"-");
                printf((statbuf.st_mode&S_IROTH)?"r":"-");
                printf((statbuf.st_mode&S_IWOTH)?"w":"-");
                printf((statbuf.st_mode&S_IXOTH)?"x":"-");
                printf("\n");
                printf((statbuf.st_mode&S_IFLNK)?"Este link simbolic":"Nu este link simbolic");
                printf("\n\n");*/
        }

    }
    chdir("..");
    closedir(dp);
}

int main(int argc,char **argv) {
    
    char cwd[1024];
    chdir("/path/to/change/directory/to");
    getcwd(cwd, sizeof(cwd));
    printdir(cwd,0);
    return 0;
}


