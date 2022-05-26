int grep(char *input)
{
	int argc=0;
	char *token,*argv[20];
	
	
	token=strtok(input," ");
	while(token!=NULL)
	{
		argv[argc]=token;
		argc++;
		token=strtok(NULL," ");
	}
	//for(int i=0;i<argc;i++)
	//{
	//	printf("%d : %s\n",i,argv[i]);
	//}
	if(strcmp(argv[1],"-i")==0)
	{
		for(int i=3;i<argc;i++)
		{
			char x[100];
			FILE *fp;
			fp=fopen(argv[i],"r");
			while(!feof(fp))
			{
				fgets(x,1024,fp);
				if(strstr(x,argv[2]))
  				{
  					printf("%s\n",argv[i]);
  					break;
  				}
			}
			fclose(fp);
		}
		
	}
	else if(strcmp(argv[1],"-c")==0)
	{
		for(int i=3;i<argc;i++)
		{
			int count=0;
			char x[100];
			FILE *fp;
			fp=fopen(argv[i],"r");
			while(!feof(fp))
			{
				fgets(x,1024,fp);
				if(strstr(x,argv[2]))
  				count++;
			}
			printf("%d\n",count);
			fclose(fp);
		}
		
	}
	else if(strcmp(argv[1],"-o")==0)
	{
		for(int i=3;i<argc;i++)
		{
			
			char x[100];
			FILE *fp;
			fp=fopen(argv[i],"r");
			while(!feof(fp))
			{
				fgets(x,1024,fp);
				if(strstr(x,argv[2]))
  				{
  					printf("%s\n",x);
  					break;
  				}
			}
			
			fclose(fp);
		}
		
	}
	else if(strcmp(argv[1],"-f")==0)
	{
		char input[100];
		FILE *fpinput;
		fpinput=fopen(argv[2],"r");
		int c;
		int z=0;
		while(feof(fpinput))
		{
			input[z++]=fgetc(fpinput);
		}
		input[z]='\0';
		printf("%s",input);
		fclose(fpinput);
		for(int i=3;i<argc;i++)
		{
			
			char x[100];
			
			FILE *fp;
			
			fp=fopen(argv[i],"r");
			while(!feof(fp))
			{
				
				fgets(x,1024,fp);
				
				if(strstr(x,input))
				{
					printf("%s\n",argv[i]);
					break;
				}
  				
			}
			
			fclose(fp);
		}
		
	}
	return 0;
}
