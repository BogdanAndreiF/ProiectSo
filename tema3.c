#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
void printdir(char *dir, int depth,int mic,int mare)
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
            printf("%*s%s/\n",depth,"",entry->d_name);
            /* Recurse at a new indent level */
            printdir(entry->d_name,depth+4,mic,mare);
            
            
        }
        else {
            
            if((statbuf.st_size>=mic)&&(statbuf.st_size<=mare))
            {

                printf("Fiesierul este : \n");
                printf("%*s%s\n",depth,"",entry->d_name);
               
            }
            
        }

    }
    chdir("..");
    closedir(dp);
}




int main(int argc,char **argv) {
    
    char cwd[1024];
    chdir("/path/to/change/directory/to");
    getcwd(cwd, sizeof(cwd));
    char aux[10];
    strcpy(aux,argv[1]);
    if(strcmp(aux,"--dim")==0)
    {
        int mic=atoi(argv[2]);
        int mare=atoi(argv[3]);
        printdir(cwd,0,mic,mare);
        

    }

    return 0;
}

