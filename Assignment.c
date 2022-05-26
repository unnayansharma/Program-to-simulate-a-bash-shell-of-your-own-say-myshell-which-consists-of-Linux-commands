#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include<dirent.h>
#include<sys/stat.h>
#include "ls.h"
#include "man.h"
#include "cp.h"
#include "ps.h"
#include "mv.h"
#include "grep.h"
char *cuserid(char *s);
int man(char *input);

void help()
{
	printf("Commands supported by myshell : \n");
	printf("1.ls \n");
	printf("2.ps \n");
	printf("3.cp \n");
	printf("4.mv \n");
	printf("5.grep \n");
	printf("6.Any other command of linux \n\n");
	printf("Type exit to exit the shell\n");
	
}
char *readinput(char *input)
{
	if(input)
	{
		free(input);
		input = (char*) NULL;
	}
	input = readline("");
	if(input && *input)
	{
		add_history(input);
	}
	return (input);
}

int main()
{
	char user[50];
	char host[50];
	char directory[100];
	char *input = (char*) NULL;
	cuserid(user);
	gethostname(host,50);
	getcwd(directory,100);
	while(1)
	{
		printf("%s@%s:~%s$ ", user,host,directory);
		input = readinput(input);
		//scanf("%[^\n]%*c",input);
		if(strcmp(input,"exit")==0)
		{
			exit(0);
		}
		else if(strcmp(input,"help")==0)
		{
			help();
			printf("\n");
			continue;
		}
		else if(input[0]=='l' && input[1]=='s')
		{
			ls(input);
			printf("\n");
			continue;
		}
		else if(input[0]=='c' && input[1]=='p')
		{
			cp(input);
			printf("\n");
			continue;
		}
		else if(input[0]=='m' && input[1]=='v')
		{
			mv(input);
			printf("\n");
			continue;
		}
		else if(input[0]=='p' && input[1]=='s')
		{
			ps(input);
			printf("\n");
			continue;
		}
		else if(input[0]=='g' && input[1]=='r' && input[2]=='e' && input[3]=='p')
		{
			grep(input);
			printf("\n");
			continue;
		}
		else if(input[0]=='m' && input[1]=='a' && input[2]=='n')
		{
			man(input);
			printf("\n");
			continue;
		}
		else
		{
			system(input);
		}
		printf("\n");
	}
  	
}
