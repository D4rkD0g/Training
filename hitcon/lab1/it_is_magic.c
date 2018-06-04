#include <stdio.h>
#include <unistd.h>

//"shixiongfeichangshuaia"

void get_flag(){
	int fd ;
	int password;
	int magic ;
	char flag[30];
	char key[] = "where_is_the_red_bao??";
	char cipher[] = {4, 127, 122, 119, 120, 107, 117, 5, 113, 6, 117, 119, 107, 4, 105, 110, 92, 105, 90, 123, 66, 73};
	fd = open("/dev/urandom",0);
	read(fd,&password,4);
	printf("Happy 6.1:");
	scanf("%d",&magic);
	if(password == magic){
		scanf("%s",flag);
		for(int i = 0 ; i < sizeof(cipher) ; i++){
			//putchar((flag[i] + cipher[i] + i) % 128);
			if ( (flag[i] + cipher[i] + i) % 128 != key[i]){
				
				printf("Wrong!!!");
				return;
			}
		}
		printf("Bling~Bling~~~Yeah~~");
	}
}

int main(){
	setvbuf(stdout,0,2,0);
	get_flag();
	return 0 ;
}
