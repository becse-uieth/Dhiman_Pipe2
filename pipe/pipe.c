#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main(){
	pid_t i;
	int fd[2],n;
	char buffer[20];
	char string[]="Hello guyz..\n";
	pipe(fd);
	i=fork();
	if(i==-1){
		perror("fork");
	}
	else if(i==0){
		sleep(1);
		close(fd[0]);
		int sl=strlen(string);
		write(fd[1],string,sl-3);
	}
	else{
		close(fd[1]);
		n=read(fd[0],buffer,sizeof(buffer));
		printf("Received string: %s\n",buffer );
	}
	return 0;
}