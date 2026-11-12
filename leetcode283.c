void moveZeroes(int* nums, int numsSize) {
    for(int i=0;i<numsSize-1;i++){
    	int flag=0;
    	for(int j=0;j<numsSize-1-i;j++){
    		if(nums[j]==0){
    			int temp=nums[j+1];
    			nums[j+1]=nums[j];
    			nums[j]=temp;
    			flag=1;
			}
		}
		if(flag==0)break;
	}
}
