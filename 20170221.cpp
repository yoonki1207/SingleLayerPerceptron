
//http://untitledtblog.tistory.com/27
/*
 뭐가 문제인지 자꾸 가중치가 발산한다...
*/
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
 
int f(float n,float t) {
	if(n>=t)return 1;
	if(n< t)return 0;
}

void gotoxy(int x, int y) {
	COORD CursorPosition = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}

int main() {
	int vector[4][4]= {-1 , 0 , 0 , 0
	                   -1 , 0 , 1 , 0
	                   -1 , 1 , 0 , 0
	                   -1 , 1 , 1 , 1
	                  };
	float w[3]= {0.3 , 0.4 , 0.1};
	float net = 0 ;		//시그마
	const float threshole = 0;//임계치
	int flag[4]= {0};
	int ffff=0;
	int i=0,j=0,l=0,plpl=0;
	float nn=0.05;
	int a=0;
	printf("w0,1,2 = %f %f %f\n",w[0],w[1],w[2]);
	
	
	while(1) {
		plpl++;
			gotoxy(0,2);
			printf("%d",plpl);
			gotoxy(0,3);
			printf("%f \n%f \n%f",w[0],w[1],w[2]);
			//	Sleep(500);
		for ( i = 0 ; i < 4 ; i ++ ) {

			for ( j = 0 ; j < 3 ; j ++ ) {

				net = net + vector[i][j] * w[j];/**//**/gotoxy(0,9);printf("%f",net);getch();
			}
			gotoxy(0,10);printf("%f %d %d ",net, vector[i][4],f(net,threshole));
			if(vector[i][4]!=f(net,threshole)) {
				flag[i]=1;
				for ( l = 0 ; l < 3 ; l ++ ) {
					w[l]=w[l]+nn*vector[i][l]*(vector[i][4]-f(net,threshole));
					
				}
			}else{}

			net = 0;
		}
		
		
		
		
		
		for( i = 0 ; i < 4 ; i ++ ) {
			if(flag[i]==1) {
				for ( j = 0 ; j < 3 ; j ++ ) {

				net = net + vector[i][j] * w[j];
			}
				for ( l = 0 ; l < 3 ; l ++ ) {
					w[l] = w[l] + nn*vector[i][l]*(vector[i][4] - f(net,threshole));
				}
				
			} else {
				continue;
			}
			net = 0;
		}
		net = 0;
		for(i=0;i<4;i++){
			gotoxy(0,1);printf("%d",flag[i]);
			a=a+flag[i];
			flag[i]=0;
			
		}
		gotoxy(10,1);printf("%d",a);
		if(a==0)break;
		a=0;
		Sleep(100);
	}
	printf("\nw0,1,2 = %f %f %f\n",w[0],w[1],w[2]);

}
