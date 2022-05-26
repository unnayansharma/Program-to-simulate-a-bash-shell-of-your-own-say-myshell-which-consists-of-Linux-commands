
int man(char *input)
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
	
	if(strcmp(argv[1],"ls")==0)
	{
		printf("Name :\nls : list directory contents\n\nDescription :\nList information about the FILEs (the current direcctory by default).\n\n");
		printf("Arguments:\n-a : Show hidden files also along with normal files\n\n");
		printf("-l : Show detailes properties of all files present in the directory\n\n");
		printf("-t : show files in sorted order of last access\n\n");
		printf("-a : show hidden files also\n\n");
		printf("-n : Show detailes properties of all files present in the directory with uid and gid\n\n");
	}
	if(strcmp(argv[1],"cp")==0)
	{
		printf("Name :\ncp : copy\n\nDescription :\ncopy one file content to other or copy files to a directory.\n\n");
		printf("cp file1 file2 : copy contents of file1 to file2\n\n");
		printf("cp file1 file2 file3 ... destination : copy file1 file2 file3 ... to destination folder\n\n");
		printf("cp -i file1 file2 : if file2 is not empty , prompts user for permission to overwrite\n\n");
		printf("cp -b file1 file2 : copy contents of file1 to file2 keeping current contents of file2 as a backup in a new file backupfile2\n\n");
	}
	if(strcmp(argv[1],"mv")==0)
	{
		printf("Name :\nmv : move\n\nDescription :\nmove one file content to other or copy files to a directory.\n\n");
		printf("mv file1 file2 : move contents of file1 to file2\n\n");
		printf("mv file1 file2 file3 ... destination : move file1 file2 file3 ... to destination folder\n\n");
		printf("mv -i file1 file2 : if file2 is not empty , prompts user for permission to overwrite\n\n");
		printf("mv -b file1 file2 : move contents of file1 to file2 keeping current contents of file2 as a backup in a new file backupfile2\n\n");
	}
	if(strcmp(argv[1],"grep")==0)
	{
		printf("Name :\ngrep : Find pattern\n\nDescription :\nFind a given pattern in the files\n\n");
		printf("grep -i pattern filename1 filename2 ... : Find the given pattern in the files and display name of files containing it\n\n");
		printf("grep -c pattern filename1 filename2 ... : Find the given pattern in the files and display occurences of pattern in the files\n\n");
		printf("grep -o pattern filename1 filename2 ... : Find the given pattern in the files and display the pattern in the files\n\n");
		printf("grep -o patternfile filename1 filename2 ... : Match the pattern given in patternfile and find it in the files and display name of files containing it\n\n");
	}
	if(strcmp(argv[1],"ps")==0)
	{
		printf("Name :\nps : Process Status\n\nDescription :\nIt is used to list current running processes and their PIDs and some other information\n\n");
	}
	return 0;
	
}
