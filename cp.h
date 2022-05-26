int cp(char *input)
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
	if(argc<3)
	{
		printf("Insufficient Arguments");
		return 0;
	}
	if(argc==3)
	{
		FILE *file1;
		FILE *file2;
		int c;
		file1=fopen(argv[1],"r");
		file2=fopen(argv[2],"w");
	
		while((c=getc(file1))!=EOF)
		{
			putc(c,file2);
		}
		fclose(file1);
		fclose(file2);
	}
	else if(strcmp(argv[1],"-i")==0)
	{
		FILE *file1;
		FILE *file2;
		int c;
		
		
		file1=fopen(argv[2],"r");
		file2=fopen(argv[3],"w");
		char response;
		if(file2)
		{
			printf("Do you want to overwrite?(Y/N)\n");
			scanf("%c",&response);
		}
		if(response=='Y')
		{
			while((c=getc(file1))!=EOF)
			{
				putc(c,file2);
			}
			fclose(file1);
			fclose(file2);
		}
		
		
	}
	else if(strcmp(argv[1],"-b")==0)
	{
		FILE *file1;
		FILE *file2;
		FILE *file3;
		FILE *file4;
		int c,g;
		
		
		
		file3=fopen(argv[3],"r");
		char dest[]="backup";
		strcat(dest,argv[3]);
		file4=fopen(dest,"w");
	
		while((g=getc(file3))!=EOF)
		{
			putc(g,file4);
		}
		fclose(file3);
		fclose(file4);
		file1=fopen(argv[2],"r");
		file2=fopen(argv[3],"w");
		while((c=getc(file1))!=EOF)
		{
			putc(c,file2);
		}
		fclose(file1);
		fclose(file2);
		
		
	}
	else if(argc > 3)
	{
		for(int i=1;i<argc-1;i++)
		{
			FILE *fp1,*fp2;
			char path[8192];
			char cwd[PATH_MAX];
			int c;
   			getcwd(cwd, sizeof(cwd));
       		fp1=fopen(argv[i],"r");
       		sprintf(path,"%s/%s/%s",cwd,argv[argc-1],argv[i]);
       		//printf("%s",path);
       		fp2=fopen(path,"w");
       		while((c=getc(fp1))!=EOF)
			{
				putc(c,fp2);
			}
			fclose(fp1);
			fclose(fp2);
		}
	}
	
	return 0;
}
