int removeDuplicates(int* nums, int numsSize) {
  int k=numsSize;
  for(int i=0;i<numsSize-1;i++){
  	for(int j=i+1;j<numsSize;j++){
  		if(nums[i]==nums[j]&&(nums[i]!=1000)){
  			nums[j]=1000;//不在nums[i]范围内的任意一个数
			k--; 
		  }
	  }
  }
  for(int i=1;i<numsSize-1;i++){
  	int flag=0;
  	for(int t=i+1;t<numsSize;t++){
  		if(nums[i]==1000&&(nums[t]!=1000)){
  		int temp=nums[i];
		nums[i]=nums[t];
		nums[t]=temp;
		flag=1;
        break;	
		  }
	  }
	if(flag==0)break;
  }
  return k;  
}
