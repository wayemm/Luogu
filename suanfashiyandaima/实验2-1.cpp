#include<stdio.h>
#define n 10
int data[n][n]={0};
int full(int number,int begin,int size);
void outprint(int size);
int main(){
	int a;
	printf("ÇëÊäÈë½×Êın(3<=n<=9):");
	scanf("%d",&a);
	full(1,0,a);
	outprint(a);
	return 0; 
}
int full(int number,int begin,int size){
	int i,j,k;
	if(size==0)
		return 0;
	if(size==1)
	{
		data[begin][begin]=number;
		return 0;
	}
	i=begin;
	j=begin;
	for(k=0;k<size-1;k++){
		data[i][j]=number;
		number++;
		j++;
	}
	for(k=0;k<size-1;k++){
		data[i][j]=number;
		number++;
		i++;
	}
	for(k=0;k<size-1;k++){
		data[i][j]=number;
		number++;
		j--;
	}
	for(k=0;k<size-1;k++){
		data[i][j]=number;
		number++;
		i--;
	}
	full(number,begin+1,size-2); 
	return 0;
}
void outprint(int size){
	int i,j;
	for(i=0;i<size;i++){
	
		for(j=0;j<size;j++){
			printf("%4d",data[i][j]);
		}printf("\n");
 	}
 	return ;
}
