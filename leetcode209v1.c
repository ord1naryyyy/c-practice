void getmaxnums(int* arr,int* max,int x,int numsSize){
	int*old_val=malloc(sizeof(int)*x);//创建回溯数组 
	for(int i=0;i<x;i++){
		for(int t=0;t<numsSize-1;t++){
		if(arr[t+1]>arr[t]){//遍历数组找最大值 
			max[i]=arr[t+1];//存最大值 
			old_val[i]=arr[t+1];//为了回溯 
			arr[t+1]=-1;//去掉最大值，方便求第二大的值 
		}	
		}	
	}
	for(int i=0;i<x;i++){
		for(int t=0;t<numsSize;t++){
			if(arr[t]==-1)arr[t]=old_val[i];//回溯最大值，以便下一轮求i+1个最大值的和 
		}
	}
}
int minSubArrayLen(int target, int* nums, int numsSize) {
    int return_val=0;
    for(int i=1;i<=numsSize;i++){
	int* max_arr=malloc(sizeof(int)*i);//建立一个存i个最大数的数组 
	for(int j=0;j<i;j++){
		max_arr[j]=0;
	}
	getmaxnums(nums,max_arr,i,numsSize);
	int all=0;
	   for(int t=0;t<i;t++){
		all+=max_arr[t];
	}
	if(all>=target){
		return_val=i;
		free(max_arr);
		break;
	}
free(max_arr);
 }
 return return_val;
}
