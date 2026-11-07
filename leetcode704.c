/*int search(int* nums, int numsSize, int target) {
    int a=-1;
	for(int i=0;i<numsSize;i++){
    	if(nums[i]==target){
    		a=i;
    		break;
		}
	}
	return 0;
}*/
int search(int* nums, int numsSize, int target) {
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
