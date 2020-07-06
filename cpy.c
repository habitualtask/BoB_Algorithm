#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fd, *dest;
	char buf[1024];
	int len;
	char *str=malloc(sizeof(char)*50);
	for(int j=1; j<argc-1; j++){
		fd = fopen(argv[j],"r");
		char *str=malloc(sizeof(char)*200);
		strcpy(str, argv[argc-1]);	
		char* s = "/";
		strcat(str, s);
		strcat(str, argv[j]);
		printf("%s\n",str);
		dest = fopen(str, "w");
	
	while(len = fread(buf,1,1023, fd) ) {
		buf[len]='\0';
		fwrite(buf,1,len,dest);
		printf("%s\n", buf);
		}		
	remove(argv[j]);
	free(str);
	}
	printf("\n");
	fclose(dest);
	fclose(fd);		
	return 0;
	}
