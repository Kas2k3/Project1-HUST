#include <stdio.h>
#include <string.h>
typedef struct node{
	int problem[11];
	int err;
	int tong;
}node;
int giophutgiay[25][61][61];
int gio[25];
int giophut[25][61];
node user[10001];
int fphut1[25][60];
int fgio[25][25];
int fphut2[25][60];
void tinhgio(){
	for(int i=0;i<23;i++){
		int sum=0;
		for(int j=i+1;j<24;j++){
			sum+=gio[j];
			fgio[i][j+1]=sum;
		}
	}
}
void tinhphut1(){
	for(int i=0;i<24;i++){
		int sum=0;
		for(int j=59;j>=1;j--){
		sum+=giophut[i][j];
		fphut1[i][j-1]=sum;
		}
	}
}
void tinhphut2(){
	for(int i=0;i<24;i++){
		int sum=0;
		for(int j=0;j<59;j++){
		sum+=giophut[i][j];
		fphut2[i][j+1]=sum;
		}
	}
}
void printdgio(int gio1,int phut1,int giay1,int gio2,int phut2,int giay2){
	int tong=0;
	if(gio1==gio2){
	if(phut1!=phut2){
	
for(int i=phut1+1;i<phut2;i++){
	tong+=giophut[gio1][i];
}
for(int i=giay1;i<=59;i++){
	tong+=giophutgiay[gio1][phut1][i];
}
for(int i=giay2;i>=0;i--){
	tong+=giophutgiay[gio1][phut2][i];
}}else{
	for(int i=giay1;i<=giay2;i++){
		tong+=giophutgiay[gio1][phut1][i];
	}
}

printf("%d\n",tong);
return;
	}
	
	tong=fgio[gio1][gio2];
	tong+=fphut1[gio1][phut1];
	tong+=fphut2[gio2][phut2];
	
	for(int i=giay1;i<60;i++){
		tong+=giophutgiay[gio1][phut1][i];
	}
	for(int i=giay2;i>=0;i--){
		tong+=giophutgiay[gio2][phut2][i];
	}

	printf("%d\n",tong);
}
int main(){
	char a[100];
	int count=0;
	int errcount=0;
	char charerr;
	int user1;
	int problem1;
	
	int point;
	int gio1,phut1,giay1;
	while(1){
		fgets(a,sizeof(a),stdin);
	if(a[0]=='#')break;
    int len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }
    sscanf(a+1,"%d %*c%d %d:%d:%d %c%*s %d",&user1,&problem1,&gio1,&phut1,&giay1,&charerr,&point);
   	if(user[user1].problem[problem1]<point){
   		user[user1].tong-=user[user1].problem[problem1];
   		user[user1].tong+=point;
   		user[user1].problem[problem1]=point;
	   }
	if(charerr=='E'){
		errcount++;
		user[user1].err++;
	}
	gio[gio1]++;
    giophut[gio1][phut1]++;
    giophutgiay[gio1][phut1][giay1]++;
	count++;
	}
	tinhgio();
tinhphut1();
tinhphut2();

	while(1){
	fgets(a,sizeof(a),stdin);
	if(a[0]=='#')break;
    int len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }
	if(a[7]=='n'){
		printf("%d\n",count);
	}else if(a[8]=='e'&&len<25){
		printf("%d\n",errcount);
	}else if(a[8]=='e'&&len>25){
		sscanf(a,"%*s %*c%d",&user1);
		printf("%d\n",user[user1].err);
	}else if(a[7]=='p'){
		sscanf(a,"%*s %*c%d",&user1);
		printf("%d\n",user[user1].tong);
	}else{
		int gio2,phut2,giay2;
		sscanf(a,"%*s %d:%d:%d %d:%d:%d",&gio1,&phut1,&giay1,&gio2,&phut2,&giay2);
		printdgio(gio1,phut1,giay1,gio2,phut2,giay2);
	}
}
