#include<stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc,char **argv)
	{
		struct stat s;
		int i;
		
		for(i=1;i<argc;i++)
		{
		if((stat(argv[i],&s))>=0)
		{
			
			printf("\n\nInformatii despre %s", argv[i]);
			printf("\n---------------------------------------------------------------------------------\n");
			printf("Dimensiune: %ld\n",s.st_size);
			printf("Numarul de legaturi : %d\n",s.st_nlink);
			printf("Numarul de inoduri : %d\n",s.st_ino);
			printf("Permisiuni :");
			printf((s.st_mode&S_IRUSR)?"r":"-");
			printf((s.st_mode&S_IWUSR)?"w":"-");
			printf((s.st_mode&S_IXUSR)?"x":"-");
                        printf((s.st_mode&S_IRGRP)?"r":"-");
                        printf((s.st_mode&S_IWGRP)?"w":"-");
                        printf((s.st_mode&S_IXGRP)?"x":"-");
                        printf((s.st_mode&S_IROTH)?"r":"-");
                        printf((s.st_mode&S_IWOTH)?"w":"-");
                        printf((s.st_mode&S_IXOTH)?"x":"-");
			printf("\n");
			printf((s.st_mode&S_IFLNK)?"Este link simbolic":"Nu este link simbolic");
			printf("\n\n");
                             			
		}
		else{
			printf("Eroare \n ");
		}
		
		}
		
	return 0;
}
