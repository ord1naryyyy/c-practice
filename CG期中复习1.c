#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
double x,n;
double sinx=0;
scanf("%lf  %lf",&x,&n);
for(int i=1;i<=n;i++){
	double s=1;
	for(int j=1;j<=2*i-1;j++){
		s*=j;
	}
    sinx+=pow(-1,i-1)*pow(x,2*i-1)/s;
}
printf("%.8lf",sinx);
	return 0;
}
/*void itoo(int n, char s[]) {
    char tmp[16];
    int k = 0, i = 0, u;

    if (n < 0) { s[i++] = '-'; u = -n; }   //直接取正 
    else        u = n;

    do {
        tmp[k++] = '0' + u % 4;
        u /= 4;
    } while (u != 0);

    while (k > 0) s[i++] = tmp[--k];
    s[i] = '\0';
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char s[16];
    itoo(n, s);
    printf("%s", s);
    return 0;
}*/
/*int count(int*a,int b,int numsSize){
	int cnt=0;
	for(int i=0;i<numsSize;i++){
		if(a[i]==b)cnt++;
	}
	return cnt;
}*/
/*int n;
scanf("%d",&n);
 int* a=malloc(sizeof(int)*n);
 for(int i=0;i<n;i++){
 	scanf("%d",&a[i]);
 }
 int index=0;
 int cnt1=count(a,a[index],n);
 for(int i=0;i<n;i++){
 	int cnt2=0;
 	cnt2=count(a,a[i],n);
    if(cnt2>cnt1){
    	index=i;
    	cnt1=cnt2;
	}
    if(cnt1==cnt2){
    	if(a[i]>a[index])index=i;
	}
 }
 printf("%d",a[index]);*/
/*	double x,n;
	double cosx=0;
	scanf("%lf  %lf",&x,&n);
	for(int i=0;i<=n;i++){
		double s=1;
		for(int t=1;t<=2*i;t++){
			s*=t;
		}
		cosx+=pow(-1,i)*pow(x,2*i)/s;
	}
	printf("%.8lf",cosx);*/
