char *cuserid(char *s);
struct tm* fileaccesstime();
struct fileproperties
{
	char name[100];
	time_t mtime;
	off_t size;
	nlink_t link;
	mode_t permission;
	uid_t uid;
	gid_t gid;
};
struct tm* fileaccesstime(unsigned long long milliseconds)
{     
	time_t mseconds=(time_t)(milliseconds);
	return localtime(&mseconds);
}
int printperm(int a)
{
	switch(a)
	{
		case(1):
			printf("--x");
			break;
		case(2):
			printf("-w-");
			break;
		case(3):
			printf("-wx");
			break;
		case(4):
			printf("r--");
			break;
		case(5):
			printf("r-x");
			break;
		case(6):
			printf("rw-");
			break;
		case(7):
			printf("rwx");
			break;
	}
}
int ls(char *input)
{
	struct stat my_stat;
	struct fileproperties array[100];
	struct fileproperties hidden[100];
	struct fileproperties temp;
	struct dirent *de;
	DIR *dr=opendir(".");
	int i=0;
	int ih=0;
	if(dr==NULL)
		{
			printf("Could not open current directory\n");
			return 0;
		}
		while((de=readdir(dr))!=NULL)
		{
			if(de->d_name[0]=='.')
			{
				strcpy(hidden[ih].name,de->d_name);
				ih++;
				continue;
			}
			
			//printf("%s ",de->d_name);
			strcpy(array[i].name,de->d_name);
			stat(de->d_name,&my_stat);
			array[i].mtime=my_stat.st_mtime;
			array[i].size=my_stat.st_size;
			array[i].link=my_stat.st_nlink;
			array[i].permission=my_stat.st_mode;
			array[i].uid=my_stat.st_uid;
			array[i].gid=my_stat.st_gid;
			
			i++;
		}
			closedir(dr);	
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
	
	
	int opt=0;
	optind=1;
	char user[50];
	char host[50];
	int u=0,g=0,o=0;
	long long int lmt=0;
	struct tm* t;
	cuserid(user);
	gethostname(host,50);
	if(argc==1)
	{
		for(int j=0;j<i;j++)
		printf("%s ",array[j].name);			
	}
	else
	{
	
	while((opt = getopt(argc, argv, ":ltan")) != -1)
	{
		switch(opt)
		{
			case 'l':
				for(int j=0;j<i;j++)
				{
					t=fileaccesstime(array[j].mtime);
					strftime(timestore, sizeof(timestore)-1, "%b %d %H:%M", t);
					o=array[j].permission % 8;
					array[j].permission = array[j].permission / 8;
					g=array[j].permission % 8;
					array[j].permission = array[j].permission / 8;
					u=array[j].permission % 8;
					array[j].permission = array[j].permission / 8;
					printf("-");
					printperm(u);
					printperm(g);
					printperm(o);
					printf(" %ld %s %s %ld %s %s",array[j].link,user,host,array[j].size,timestore,array[j].name);
					printf("\n");
				}
				break;
			case 't' :
				for(int k=0;k<i-1;k++)
				{
					for(int j=0;j<(i-1-k);j++)
					{
						if(array[j].mtime < array[j+1].mtime)
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
				}
				for(int j=0;j<i;j++)
				{
					printf("%s ",array[j].name);
				}
				break;
			case 'a' :
				for(int j=0;j<i;j++)
				{
					printf("%s ",array[j].name);
					printf("%s ",hidden[j].name);
					
				}
				break;	
			case 'n' :
					for(int j=0;j<i;j++)
					{
					t=fileaccesstime(array[j].mtime);
					strftime(timestore, sizeof(timestore)-1, "%b %d %H:%M", t);
					o=array[j].permission % 8;
					array[j].permission = array[j].permission / 8;
					g=array[j].permission % 8;
					array[j].permission = array[j].permission / 8;
					u=array[j].permission % 8;
					array[j].permission = array[j].permission / 8;
					printf("-");
					printperm(u);
					printperm(g);
					printperm(o);
					printf(" %ld %d %d %ld %s %s",array[j].link,array[j].uid,array[j].gid,array[j].size,timestore,array[j].name);
					printf("\n");
					}
				break;
			case ':':
				printf("option needs a value\n");
				break;
			case '?':
				printf("unknown option: %c\n", optopt);
				break;
				
		}
			
	}
	}
	return 0;
}
