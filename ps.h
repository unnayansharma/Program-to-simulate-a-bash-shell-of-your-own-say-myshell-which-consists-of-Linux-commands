int ps(char *input)
{
	int argc=0;
	char *token,*argv[20];
	char timestore[100];
	token=strtok(input," ");
	while(token!=NULL)
	{
		argv[argc]=token;
		argc++;
		token=strtok(NULL," ");
	}
	if(argc==1)
	{
		DIR *dir;
		dir=opendir("/proc");
		int fd1;
		fd1 = open("/proc/self/fd/0", O_RDONLY);
		printf("PID	TTY	TIME	CMD\n");
		char tty[300],cmd[300],path[300],time[300];
		sprintf(tty, "%s", ttyname(fd1));
		struct dirent *dirreader;
		char *tty1;
		unsigned long time1, stime;
		int i;
		FILE *fd3;
		while ((dirreader = readdir(dir)) != NULL)
		{
			char flag=1;
			for (int i = 0; dirreader->d_name[i]; i++)
			{
				if (!isdigit(dirreader->d_name[i]))
  				{ 
   					flag = 0;
   					break;
  				}
  					
			}
			if(flag==1)
  			{
  				int fd2;
  				
  				sprintf(path, "/proc/%s/fd/0", dirreader->d_name);
  				fd2 = open(path, O_RDONLY);
  				tty1 = ttyname(fd2);
  				if (tty1 && strcmp(tty1, tty) == 0)
  				{
  					sprintf(path, "/proc/%s/stat", dirreader->d_name);
   					fd3 = fopen(path, "r");
   					fscanf(fd3, "%d%s%c%c%c", &i, cmd, &flag, &flag, &flag);
   					cmd[strlen(cmd) - 1] = '\0';
  					fscanf(fd3, "%lu", &time1);
  					fscanf(fd3, "%lu", &stime);
  					time1 = (int)((double)(time1 + stime) / sysconf(_SC_CLK_TCK));
  					sprintf(time, "%02lu:%02lu:%02lu",(time1 / 3600) % 3600, (time1 / 60) % 60, time1 % 60);
 					printf("%5s %s\t%8s %s\n", dirreader->d_name, tty + 5, time, cmd + 1);
  					fclose(fd3);
  				}
  				close(fd2);
  			}
  			
  			

		}
		close(fd1);
		
		
	}
}
