#include <cstdio>
char k[80][80];

void setImage(char k[][80],char* c,int head,int tail,bool Huase){
	if(head==tail){
		k[head][tail]=c[Huase];
		return;
	} 
	for(int i=head;i<=tail;i++){
		k[head][i]=c[Huase];
		k[tail][i]=c[Huase];
		k[i][head]=c[Huase];
		k[i][tail]=c[Huase];
	}
	head++;
	tail--;
	Huase=!Huase;
	setImage(k,c,head,tail,Huase);
}

int main(){
	int n;
	char c[2];
	while(scanf("%d %c %c",&n,&c[0],&c[1])!=EOF){
		setImage(k,c,0,n-1,1);
		k[0][0]=' ';
		k[0][n-1]=' ';
		k[n-1][0]=' ';
		k[n-1][n-1]=' ';
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c",k[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
