int removeElement(int* nums, int numsSize, int val) {
int k=numsSize;
for(int i=0;i<numsSize;i++){
	if(nums[i]==val){
		nums[i]=-1;
		k--;
	}
}
for(int i=0;i<numsSize-1;i++){
	if(nums[i]==-1){
		for(int t=i+1;t<numsSize;t++){
			if(nums[t]!=-1){
				int temp=nums[t];
		        nums[t]=nums[i];
		        nums[i]=temp;
			}
		}
	}
} 
return k;
}
