#include <stdio.h>
int main(){
char a[20],b[20];
int cnt1=0,cnt2=0;
for(int i=0;i<20;i++){
    a[i]=getchar();
    if(a[i]=='\n'){a[i]='\0';break;}
    cnt1++;
}
a[19]='\0';
printf("交换前：\n");
printf("a：");
for(int i=0;a[i]!='\0';i++){
    putchar(a[i]);
}
printf("\n");
for(int i=0;i<20;i++){
    b[i]=getchar();
    if(b[i]=='\n'){b[i]='\0';break;}
    cnt2++;
}
b[19]='\0';
printf("b：");
for(int i=0;b[i]!='\0';i++){
    putchar(b[i]);
}
printf("\n");
printf("交换后：\n");
if(cnt1>cnt2){
    char t[20];
    for(int i=0;i<=cnt2;i++) t[i]=b[i];
    for(int i=0;i<=cnt1;i++) b[i]=a[i];
    for(int i=0;i<=cnt2;i++) a[i]=t[i];
}
printf("a：");
for(int i=0;a[i]!='\0';i++) putchar(a[i]);
printf("\n");
printf("b：");
for(int i=0;b[i]!='\0';i++) putchar(b[i]);
printf("\n");
	return 0;
}
/*int row_size=4,colum_size=6;
double score[row_size][colum_size];
double score_avg[colum_size-1];
for(int i=0;i<row_size-1;i++){
	for(int j=0;j<colum_size-1;j++){
		scanf("%lf",&score[i][j]);
	}
}
for(int i=0;i<row_size-1;i++){
	double sum=0;
	for(int j=0;j<colum_size-1;j++){
		sum+=score[i][j];
	}
	score[i][5]=sum/5.0;
}
for(int j=0;j<colum_size-1;j++){
	double sum=0;
	for(int i=0;i<row_size-1;i++){
		sum+=score[i][j];
	}
	score[3][j]=sum;
	score_avg[j]=sum/3.0;
}
printf("Output(输出结果)：\n");
for(int i=0;i<row_size-1;i++){
    for(int j=0;j<colum_size-1;j++) printf("%.0lf ",score[i][j]);
    printf("%.1lf\n",score[i][colum_size-1]);
}
for(int j=0;j<colum_size-1;j++){
    printf("%.1lf%s",score[row_size-1][j], j==colum_size-2 ? "\n" : " ");
}
printf("Average:\n");
for(int i=0;i<colum_size-1;i++){
    printf("%.1lf%s",score_avg[i], i==colum_size-2 ? "\n" : " ");
}*/
/*	int arr[5][6];
	int max_rowidx,max_columidx,min_rowidx,min_columidx;
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int max=arr[0][0],min=arr[0][0];
	double ave[5];
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			if(arr[i][j]>max){
			max=arr[i][j];
			max_rowidx=i;
			max_columidx=j;
			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			if(arr[i][j]<min){
			min=arr[i][j];
			min_rowidx=i;
			min_columidx=j;
			}
		}
	}
	for(int i=0;i<5;i++){
		int all=0;
		for(int j=0;j<6;j++){
			all+=arr[i][j];
		
		}
	ave[i]=all/6.0;
	}
	printf("Maximum：a[%d][%d]=%d\n",max_rowidx,max_columidx,max);
	printf("Minimum：a[%d][%d]=%d\n",min_rowidx,min_columidx,min);
	printf("Average：\n");
	for(int i=0;i<5;i++){
		printf("Ave[%d]=%.2lf\n",i,ave[i]);
	}*/
/*int search(int* nums, int numsSize, int target) {
 int left=0;
 int right=numsSize-1;
 int mid=(left+right)/2;
 if(nums[left]<=target&&nums[right]>=target){//判断target在不在[left,right]里 
 if(nums[mid]==target)return mid;
 else{
 while(left!=right){	
    if(nums[mid]==target)return mid;//判断是否查找到，若查找到，离开循环 
	if(nums[mid]>target){
		right=mid-1;
		mid=(left+right)/2;
	}//target在mid左边 
	else{
		left=mid+1;
		mid=(left+right)/2;
	}//target在mid右边 
	if(nums[mid]==target)return mid;//判断是否查找到，若查找到，离开循环 
 }
 }
}
 return -1;
}
int main(){
int arr[20];
int n=20;
for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
int target;
scanf("%d",&target);
for(int i=0;i<n-1;i++){
	int flag=0;
	for(int t=0;t<n-1-i;t++){
		if(arr[t]>arr[t+1]){
		int temp=arr[t+1];
   		arr[t+1]=arr[t];
   		arr[t]=temp;
   		flag=1;
		}
	}
	if(flag==0)break;
}
for(int i=0;i<n;i++){
	printf("%d ",arr[i]);
}
printf("\n");
int search_nums;
search_nums=search(arr,n,target);
if(search_nums==-1)printf("无此数");
else{printf("%d",search_nums);
}
	return 0;
}*/
/*int arr[20];
int n=20;
for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
for(int i=0;i<n-1;i++){
	int flag=0;
	for(int t=0;t<n-1-i;t++){
		if(arr[t]>arr[t+1]){
		int temp=arr[t+1];
   		arr[t+1]=arr[t];
   		arr[t]=temp;
   		flag=1;
		}
	}
	if(flag==0)break;
}
for(int i=0;i<n;i++){
	printf("%d ",arr[i]);
}*/
/*char str1[80],str2[80];
for(int i=0;i<80;i++){
	str1[i]=getchar();
	str2[i]=str1[i];
	if(str1[i]=='\n'){
		str1[i]='\0';
		break;
	}
}
for(int i=0;i<80;i++){
	putchar(str2[i]);
}*/
/*int arr[10],all;
double ave;
for(int i=0;i<10;i++){
	scanf("%d",&arr[i]);
}
int min=arr[0],max=arr[0];
for(int i=1;i<10;i++){
if(arr[i]>max)max=arr[i];
}
for(int i=1;i<10;i++){
if(arr[i]<min)min=arr[i];
}
for(int i=0;i<10;i++){
	all+=arr[i];
if(i==9)ave=all/10.0;
}
printf("max=%d\n",max);
printf("min=%d\n",min);
printf("ave=%.2lf",ave);
*/
	/*int a[4]={5,2,7,4};
	printf("逆序前的数组元素：\n");
    for(int i=0;i<4;i++){
    	printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=0;i<2;i++){
		int temp=a[3-i];
		a[3-i]=a[i];
		a[i]=temp;
	}
	printf("逆序后的数组元素：\n");
    for(int i=0;i<4;i++){
    	printf("%d ",a[i]);
	}*/
