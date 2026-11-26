#include <stdio.h>
#include <string.h>

int main(void) {
    char str[128];

    while (fgets(str, sizeof str, stdin) != NULL) {
        size_t len = strlen(str);
        while (len > 0 && (str[len-1] == '\n' || str[len-1] == '\r'))
            str[--len] = '\0';              /* 去掉 fgets 带进来的换行 */
        if (len == 0) continue;             /* 空行跳过 */
        if (strcmp(str, "quit") == 0) break;

        int left = 0, right = (int)len - 1, jg = 1;
        while (left < right) {
            if (str[left] != str[right]) { jg = 0; break; }
            left++;
            right--;
        }
        if (jg) printf("%s\n", str);
    }
    return 0;
}
/* ****处理不了空格版****
char quit[]="quit";
for(;;){
	char str[21];
	scanf("%s",str);
	if(strcmp(str,quit)==0)break;//判断是否quit 
	int size=strlen(str);
	int left=0,right=size-1;//左右指针分别指向字符串首尾 
	int jg=1;//jg判断是否回文 
	while(left<=right){
		if(str[left++]!=str[right--]){//左右指针向中间靠拢依次判断
			jg=0;//出现不相等情况，jg为假，跳出循环 
			break;
	}
}
    if(jg){
		printf("%s",str);//判断循环结束后，jg仍为真则输出字符串 
		printf("\n");
	}


}*/ 
/*typedef struct Employer{
	char name[20];
	double salary;
}Employer;
int n;
scanf("%d",&n);
 Employer *employers=malloc(sizeof(Employer)*n);
 for(int i=0;i<n;i++){
 	scanf("%s",employers[i].name);
 	scanf("%lf",&employers[i].salary);
 }
 char found[20];
 scanf("%s",found);
 for(int i=0;i<n;i++){
 	if(strcmp(employers[i].name,found)==0){
 	  printf("%s",employers[i].name);
 	  printf(" ");
 	  printf("%.2lf",employers[i].salary);
 	  break;
	 }
 }*/
/*char s[20],t[20];
scanf("%s",s);
scanf("%s",t);
int i=0,q=0;
char c[20];
while(s[i]!='\0'){
	int j=0,found=0;
	while(t[j]!='\0'){
		if(s[i]==t[j]||s[i]==t[j]+32||s[i]==t[j]-32){			
	    found=1;
	    break;
		}
	j++;
	}
	if(found==0)c[q++]=s[i];
	i++;
}
for(int m=0;m<q-1;m++){
	for(int n=0;n<q-1-m;n++){
		if(c[n]>c[n+1]){
			char temp=c[n+1];
			c[n+1]=c[n];
			c[n]=temp;
		}
	}
}
for(int m=0;m<q;m++){
	putchar(c[m]);
}*/
/*int s;
scanf("%d",&s);
int day,hour,second,minute;
day=s/86400;
hour=(s%86400)/3600;
minute=s%3600/60;
second=s%60;
if(day==0){
	printf("%02d:%02d:%02d",hour,minute,second);
}
else{
	printf("%02d-%02d:%02d:%02d",day,hour,minute,second);
}*/
/*	int num1_1,num1_2,num2_1,num2_2;
	scanf("%d/%d,%d/%d",&num1_1,&num1_2,&num2_1,&num2_2);
	double a=(double)num1_1/num1_2,b=(double)num2_1/num2_2;
	int numsp1=num1_1*num2_2,numsp2=num2_1*num1_2;
	if(a==b)printf("%d/%d=%d/%d",num1_1,num1_2,num2_1,num2_2);
	else{
	if(a<0&&b>0)
	printf("%d/%d<%d/%d",num1_1,num1_2,num2_1,num2_2);
	if(a>0&&b<0)
	printf("%d/%d>%d/%d",num1_1,num1_2,num2_1,num2_2);
	if(a>0&&b>0){
		if(numsp1>numsp2)printf("%d/%d>%d/%d",num1_1,num1_2,num2_1,num2_2);
	    else printf("%d/%d<%d/%d",num1_1,num1_2,num2_1,num2_2);
	}
	if(a<0&&b<0){
	    if(numsp1>numsp2)printf("%d/%d<%d/%d",num1_1,num1_2,num2_1,num2_2);	
	    else printf("%d/%d>%d/%d",num1_1,num1_2,num2_1,num2_2);
	}
}*/
/*
void itoo(int n, char s[]) {
    char tmp[16];
    int k = 0, i = 0, u;

    if (n < 0) { s[i++] = '-'; u = -n; }   //直接取正 
    else        u = n;

    do {
        tmp[k++] = '0' + u % 8;
        u /= 8;
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

/*double kt;
scanf("%lf",&kt);
double g=kt*950.0;
printf("%.6e",g/(3e-23));*/
/*	int n;
	scanf("%d",&n);
	int** a=malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)a[i]=malloc(sizeof(int)*(i+1));
	for(int i=0;i<n;i++){
		a[i][0]=1;
		a[i][i]=1;
		for(int j=1;j<i;j++){
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}*/
/*int n;
	scanf("%d",&n);
	int** a=malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)a[i]=malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=i*n+j+1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%4d",a[j][i]);
		}
		printf("\n"); 
	}*/
