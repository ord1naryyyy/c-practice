#include <stdio.h>
#define NS 3
#define NC 4

void studentAve(int a[][NC], double ave[]) {
    for (int i = 0; i < NS; i++) {
        int sum = 0;
        for (int j = 0; j < NC; j++) sum += a[i][j];
        ave[i] = sum / (double)NC;
    }
}
void courseAve(int a[][NC], double ave[]) {
    for (int j = 0; j < NC; j++) {
        int sum = 0;
        for (int i = 0; i < NS; i++) sum += a[i][j];
        ave[j] = sum / (double)NS;
    }
}
void highest(int a[][NC], int *r, int *c, int *v) {
    *v = a[0][0];  *r = *c = 0;
    for (int i = 0; i < NS; i++)
        for (int j = 0; j < NC; j++)
            if (a[i][j] > *v) { *v = a[i][j]; *r = i; *c = j; }
}
double variance(double ave[], int n) {
    double sum = 0, sumSq = 0;
    for (int i = 0; i < n; i++) { sum += ave[i]; sumSq += ave[i]*ave[i]; }
    double m = sum / n;
    return sumSq / n - m * m;
}
int main(void) {
    int a[NS][NC], r, c, v;
    double sa[NS], ca[NC];
    for (int i = 0; i < NS; i++)
        for (int j = 0; j < NC; j++) scanf("%d", &a[i][j]);

    studentAve(a, sa);
    courseAve(a, ca);
    highest(a, &r, &c, &v);

    printf("student ave：\n");
    for (int i = 0; i < NS; i++) printf("%.2f%c", sa[i], i == NS-1 ? '\n' : ' ');
    printf("course ave：\n");
    for (int j = 0; j < NC; j++) printf("%.2f%c", ca[j], j == NC-1 ? '\n' : ' ');
    printf("highest is student %d and course %d：%d\n", r+1, c+1, v);
    printf("var is：%.2f\n", variance(sa, NS));
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
int fact(int n){
	if(n!=0){
	n=n*fact(n-1);
	return n;
}
else return 1;
}
int main(){
	int num;
	scanf("%d",&num);
	printf("%d!=%d",num,fact(num));
	return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
int mystrlen(char s[]){
	int cnt=0;
	for(int i=0;s[i]!='\0';i++){
		cnt++;
	}
	return cnt;
}
int main(){
	char s[100];
	scanf("%99[^\n]", s);
	printf("%d",mystrlen(s));
	return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
void dealwithString (char s[], char t[]){
	int j=0;
for(int i=0;s[i]!='\0';i++){
	if(s[i]%2==0)t[j++]=s[i];
}
t[j]='\0';	
}
int main(){
    char s[100];
	char t[100];
	scanf("%99[^\n]%s",s);
	dealwithString(s,t);
	printf("%s",t);	
	return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPirme(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0)return 0;
	}
	return 1;
}
int calculateArr_size(int lim){
	int cnt=0;
	for(int i=2;i<=lim;i++){
		if(isPirme(i))cnt++;
	}
	return cnt;
}
void calculatePrime(int lim, int* aa){
	for(int i=2,t=0;i<=lim;i++){
		if(isPirme(i))aa[t++]=i;
	}
} 
int main(){
	int max_nums;
	scanf("%d",&max_nums);
	int arr_size=calculateArr_size(max_nums);
	int* aa=malloc(sizeof(int)*arr_size);
	calculatePrime(max_nums,aa);
	for(int i=0;i<arr_size;i++){
		if(aa[i]!=0)printf("%d ",aa[i]);
	}
	free(aa);
}*/
/*#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void invertedOrder(int* nums,int numsSize){
    for(int left=0,right=numsSize-1;left<=right;left++,right--){       
		swap(&nums[left],&nums[right]);	
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int* arr=malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	invertedOrder(arr,n);
	printf("逆序后的数组元素：\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	free(arr);
	return 0;
}*/
/*#include <stdio.h>
#include <math.h>
#include <complex.h>
void print_complex(double complex z){
	double re = creal(z);
	double im = cimag(z);
	if(im>0)printf("%.0f+%.0fi",re,im);
	else printf("%.0f-%.0fi",re,-im);
}
void deltaZero(double a, double b, double c){
	double x=-b/(2*a);
	printf("X1=X2=%.0lf",x);
}
void deltaLargerZero(double a, double b, double c){
  double x1=(-b+sqrt(b*b-4*a*c))/2*a;
  double x2=(-b-sqrt(b*b-4*a*c))/2*a;
  printf("X1=%.0lf  X2=%.0lf",x1,x2);	
}
void deltaLessZero(double a, double b, double c){
  double complex check2=b*b-4*a*c;
  double complex check=csqrt(check2);
  double complex x1=(-b+check)/2*a;
  double complex x2=(-b-check)/2*a;
  printf("X1=");
  print_complex(x1);
  printf("  X2=");
  print_complex(x2);
  
  	
}
int main(){
double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a==0){
		for(double i=-10;;i++){
			if(b*i+c==0){
				printf("X=%.0lf",i);
				break;
			}
		}
	}
	if(b*b-4*a*c==0&&a!=0)deltaZero(a,b,c);
	if(b*b-4*a*c>0&&a!=0)deltaLargerZero(a,b,c);
	if(b*b-4*a*c<0&&a!=0)deltaLessZero(a,b,c);
	return 0;
}*/
/*#include <stdio.h>
int gcd(int a, int b){
    while(b){ 
	int t = a % b; 
	a = b; 
	b = t;}
    return a;
}
int lcd(int a,int b){
	return a/gcd(a,b)*b;
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("最大公约数为：%d\n",gcd(a,b));
	printf("最小公倍数为：%d\n",lcd(a,b));
	return 0;
}*/
/*#include <stdio.h>
int isPerfectNum(int n){
	int cnt=0;
	for(int i=1;i<n;i++){
		if(n%i==0)cnt+=i;
	}
	if(cnt==n)return 1;
	return 0;
}
int main(){
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	printf("上述范围内的完数为：\n");
	for(int i=num1;i<=num2;i++){
		if(isPerfectNum(i))printf("%d ",i);
	}
	return 0;
}*/
/*
********交换后仍为素数******** 
#include <stdio.h>
#include <math.h>
int isPrime(int a){
	for(int t=2;t<=sqrt(a);t++){
		int b=a%t;
		if(b==0.0){
			return 0;
		}
	}
	return 1;
}

int main(){
	for(int i=11;i<98;i++){
		if(isPrime(i)){
			int num1=i/10;
			int num2=i%10;
			int num=num2*10+num1;
			if(isPrime(num))printf("%d ",i);
		}
	}
	return 0; 
}*/
