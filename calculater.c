
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define stod(X) (X==0? 0: X-'0')

char input[10000] = {0,};
char va[100][100] = {0,}, fir[100][100] = {0,}, sec[100] = {0,}, an[100][100] = {0,}, bn[100][100];
int u[100] = {0,};//소수자리

void reverse(char *arr, int len); // 계산하기 전 배열에 있는 수 뒤집는 함수
char Pick(char fir[100][100], int j); // 정수 50자리 소수 9자리 판별하는 함수
void Clear(); 
void End();
void Error();
void Plus(int n); //덧셈 함수
void mult(); // 곱셈 함수
void minus(int n); // 뺄셈 함수

	
int main()
{
	FILE *Far;
	Far = fopen("variation", "w");
	char n;
	int i, j, k, m;
    int s = 0, a, c, d;	
	while(1){
		printf("수를 입력하세요: ");
		gets(input);	
	
	if((input[0] <= 'z' && input[0] >= 'a') || (input[0] <= 'Z' && input[0] >= 'A')){	// 대문자 소문자 알파벳이 입력될 때 변수 입력
		if(input[1] == ' ' && input[2] == '=' && input[3] == ' '){						// 알파벳 = 숫자 형식
			for(int b = 4; input[b] != '\0'; b++){
				if((input[b] >= '0')&&(input[b] <= '9')||(input[b] == '.')){
				va[c][d] = input[b];
				d++;
      	  		if((input[b+1] != '.') && (input[b+1] < '0')||(input[b+1] > '9')){			
				va[c][d] = '\0';
			    c++;
		        d = 0;
				}
				}
			}
		}
		if(input[1] == ' ' && input[2] == '='){			// 알파벳 =숫자형식
			for(int b = 3; input[b] != '\0'; b++){
				if((input[b] >= '0')&&(input[b] <= '9')||(input[b] == '.')){
				va[c][d] = input[b];
				d++;
      	  		if((input[b+1] != '.') && (input[b+1] < '0')||(input[b+1] > '9')){	
				va[c][d] = '\0';
			    c++;
		        d = 0;
				}
				}
			}
		}
		if(input[1] == '=' && input[2] == ' '){    // 알파벳= 숫자 형식
			for(int b = 3; input[b] != '\0'; b++){
				if((input[b] >= '0')&&(input[b] <= '9')||(input[b] == '.')){
				va[c][d] = input[b];
				d++;
      	  		if((input[b+1] != '.') && (input[b+1] < '0')||(input[b+1] > '9')){						
				va[c][d] = '\0';
			    c++;
		        d = 0;
				}
				}
			}
		}
		if(input[1] == '='){   //알파벳=숫자 형식
			for(int b = 2; input[b] != '\0'; b++){
				if((input[b] >= '0')&&(input[b] <= '9')||(input[b] == '.')){
				va[c][d] = input[b];
				d++;
      	  		if((input[b+1] != '.') && (input[b+1] < '0')||(input[b+1] > '9')){					
				va[c][d] = '\0';
			    c++;
		        d = 0;
				}
				}
			}
		}
		fprintf(Far, "%s\n", va);
		fclose(Far);
	
	}
	for(i=0, j=0, k=0, m=0; input[i] != '\0'; i++){

		if((input[i] >= '0')&&(input[i] <= '9')||(input[i] == '.')){
			fir[j][k] = input[i];
			k++;
      	  if((input[i+1] != '.') && (input[i+1] < '0')||(input[i+1] > '9')){										// 띄어쓰기 있을 떄 널 문자
				fir[j][k] = '\0';
			    j++;
		        k = 0;
				if (Pick(fir, j-1) == 'p'){																//Pick 함수
					Error();
					return 0;
	            } 
		  }	   
	    }
		else if(input[0] == 'c' && input[1] == 'l' && input[2] == 'e' && input[3] == 'a' && input[4] == 'r')		// clear 명령
			Clear();
		else if(input[0] == 'e' && input[1] == 'n' && input[2] == 'd')												// end 명령
			End();	
		

		else if(input[i] != ' ' && input[i] != '.' && (input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != '%') && (input[i] <= 'z' && input[i] >= 'a') || (input[i] <= 'Z' && input[i] >= 'A')){																	// error 조건
			Error();
			return 0;
		}
		else if(input[i] != ' ' && input[i] != '.' && (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '%')){																												 // 기호 넣는 조건
			    sec[m] = input[i];
				m++;
          		}
		}
		sec[m] = '\0';
	  
		

		
		if (sec[s] == '+')
			Plus(s);
	
		if (sec[s]=='*')
			mult();
		if (sec[s]=='-')
			minus(s);
	}	
			
	return 0;
	}


void Clear(){
	system("clear");
}	

void End(){
	exit(-1);
}

void Error(){
	printf("error");
}

char Pick(char fir[100][100], int m){   
int i , count[100];  
char y = 'o', n = 'p';
  for(int j = 0; j-1 <= m; j++){
	i = 0;	  
	while((fir[j][i] >= '0')&&(fir[j][i]<='9')){
    	 i++;
        }
	count[j] = i;
	if(i > 50){
  		return n;
       	  }
	while(fir[j][i] != '\0'){
     	i++;
     	}
	if((i-count[j])>10){
  		return n;
    }
}
}


void reverse(char *arr, int len){
	char temp;
	int i;
	for(i=0; i<len/2; i++){
		temp=arr[i];
		arr[i]=arr[len-1-i];
		arr[len-1-i]=temp;
	}
}

void Plus(int n)
{	
	int on = 0, up, k = 0, ok = 0, ou = 0;
	int i = 0;
	int len, len_1, len_2;
	char in[100][100];
	char fl[100][100];
	int sublen = 0;
				


for( i = 0; input[i] != '\0'; i++){
	if(input[i] == '.'){
		on = 1;
	}
}
i = 0;

if( on == 1 ){ // 소수부분이 존재할 때
				int q;
				for(q=0; fir[n][q] != '\0'; q++){   // 두 수중 하나만 소수부분이 존재하면 다른 수 하나도 소수점을 만들어준다
					if(fir[n][q] == '.')
						ok = 1;
				}
				if( ok == 0){
					fir[n][q] = '.';
					fir[n][q+1] = '0';
					fir[n][q+2] = '\0';
				}
				int w;
				for(w=0; fir[n+1][w] != '\0'; w++){
					if(fir[n+1][w] == '.')
						ou = 1;
				}
				if( ou == 0){
					fir[n+1][w] = '.';
					fir[n+1][w+1] = '0';
					fir[n+1][w+2] = '\0';
				}


				for(k; fir[n][k] != '.'; k++){
					in[n][k] = fir[n][k];
				}	
				in[n][k] = '\0';
				for(i;fir[n][i] != '\0'; i++){
					fl[n][i] = fir[n][k+1];
					k++;
				}
				fl[n][i] = '\0';
				k=0; i=0;
				for(k; fir[n+1][k] != '.'; k++){
					in[n+1][k] = fir[n+1][k];
				}
				in[n+1][k] = '\0';
				for(i;fir[n+1][i] != '\0'; i++){
					fl[n+1][i] = fir[n+1][k+1];
					k++;;
				}
				fl[n+1][i] = '\0';



				if( strlen(in[n]) > strlen(in[n+1]) ) 
					len_1 = strlen(in[n]);
				else len_1 = strlen(in[n+1]);

				reverse(in[n], strlen(in[n]));	
				reverse(in[n+1], strlen(in[n+1]));

				for(i=0; i<=len_1; i++){
					an[n][i] = (stod(in[n][i]) + stod(in[n+1][i]) + up ) % 10 + '0'; 
					if((stod(in[n][i]) + stod(in[n+1][i]) + up) > 9)
						up=1;		
					else
						up=0;
				}
				if(strlen(fl[n]) > strlen(fl[n+1])){
					len_2 = strlen(fl[n]);
					sublen = strlen(fl[n]) - strlen(fl[n+1]);
					for(; sublen != 0; sublen--){
						fl[n+1][len_2 - sublen] = '0';	
							}		
					
				}
				else if(strlen(fl[n]) <= strlen(fl[n+1])){
						len_2 = strlen(fl[n+1]);
						sublen = strlen(fl[n+1]) - strlen(fl[n]);
						for(; sublen != 0; sublen--){
							fl[n][len_2-sublen] = '0';
						}
				}

				reverse(fl[n], strlen(fl[n]));
				reverse(fl[n+1], strlen(fl[n]));

				for(i=0; i<=len_2; i++){
					bn[n][i] = (stod(fl[n][i]) + stod(fl[n+1][i]) + up ) % 10 + '0';
					if((stod(fl[n][i]) + stod(fl[n+1][i]) + up) > 9)
						up = 1;
					else
						up = 0;
				}

					
					if(an[n][len_1] == '0') 
						an[n][len_1] = 0;
					if(bn[n][len_2] == '0')
						bn[n][len_2] = 0;

						reverse(an[n], strlen(an[n]));
						reverse(bn[n], strlen(bn[n]));
						printf("%s.%s\n", an[n],bn[n]);
}
else if(on == 0){ // 정수부분만 존재할 때
				if( strlen(fir[n]) > strlen(fir[n+1]) )
					len = strlen(fir[n]);
				else len = strlen(fir[n+1]);
					reverse(fir[n], strlen(fir[n]));
					reverse(fir[n+1], strlen(fir[n+1]));
				for(i=0; i<=len; i++){
					an[n][i] = (stod(fir[n][i]) + stod(fir[n+1][i]) + up ) % 10 + '0';
					if((stod(fir[n][i]) + stod(fir[n+1][i]) + up) > 9)
						up=1;
					else
						up=0;
					an[n][len+1] = '\0';
					}
					
					if(an[0][len] == '0') 
						an[0][len] = 0;
						reverse(an[0], strlen(an[0]));

					printf("%s\n", an[n]);	
}
}

void mult(){
	
	int c,d,e,f,g[100],h[100],l[100]={0,},j,k;		
	
	c=strlen(fir[0]);
	
	for(e=0;e-c;e++)
		g[c-e]=fir[0][e]-'0'; //fir[0] 배열을 strlen을 이용, 길이를 c에 저장
								// g배열에 fir 배열을 뒤집어 입력
	
		d=strlen(fir[1]);
	
	for(e=0;e<d;e++) //위와 같은 과정
		h[d-e]=fir[1][e]-'0';
	
	for(e=1;e<=c;e++)
	{
		for(f=1;f<=d;f++)
		{
			l[e+f-1]+=g[e]*h[f];
			if(l[e+f-1]>=10)
			{
				l[e+f]+=l[e+f-1]/10; //자리수 정리
				l[e+f-1]%=10;
			}		
		}
	}
	for(e=99;e>=1;e--)
		if(l[e]!=0) break;
	for(e=e;e>=1;e--)
	{		printf("%d",l[e]);
	if(e%3 == 1){  // 세자리 마다 ,를 붙여준다
		if(e/3 != 0)
			printf(",");
	}
	}
	printf("\n");

	return ;
}

void minus(int n){
	int i=0, down;
	int len;
	if( strlen(fir[n]) > strlen(fir[n+1]))
		len = strlen(fir[n]);
	else len = strlen(fir[n+1]);

	reverse(fir[n], strlen(fir[n]));
	reverse(fir[n+1], strlen(fir[n+1]));
	
	for(i; i<=len; i++){
		if(stod(fir[n][i]) >= stod(fir[n+1][i])){
			an[n][i] = stod(fir[n][i]) - stod(fir[n+1][i]);
			down = 0;
		}
		else{
			down = 1;
			an[n][i] = ( (10 - down) + stod(fir[n][i]) - stod(fir[n+1][i]));
		}
	}
}
