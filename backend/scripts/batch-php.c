#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define and &&
#define or ||
#define not !

#define BUFF_SIZE 150

int main(int argc, char *argv[]){
	unsigned converted_file_count=0;
	if(argc < 2){
		puts("error: too few arguments");
		return 1;
	}
	for(int i=1; i<argc; i++){
		printf("proecssing: %s\n", argv[i]);
		unsigned len = strlen(argv[i]);
		if(len>100){
			puts("file name too long, skipping file");
			continue;
		}
		if(not (argv[i][len-1]=='p' and argv[i][len-2]=='h' and argv[i][len-3]=='p' and argv[i][len-4]=='.')){
			puts("error: wrong file extention, skipping file");
			continue;
		}
		argv[i][len-3]='\0';
		char command[BUFF_SIZE]={'\0'};
		strcat(strcat(strcat(strcat(strcat(command,"php "),argv[i]),"php > "),argv[i]),"html");
		puts(command);
		system(command);
		converted_file_count++;
	}
	printf("converted %u files\n", converted_file_count);

	return 0;
}