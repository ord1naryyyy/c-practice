/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
   int* square_nums=malloc(sizeof(int)*numsSize);
   *returnSize=numsSize;
   for(int i=0;i<numsSize;i++){
   	square_nums[i]=nums[i]*nums[i];
   } 
   for(int i=0;i<numsSize-1;i++){
   	int flag=0;
   	for(int t=0;t<numsSize-1-i;t++){
   		if(square_nums[t]>square_nums[t+1]){
   			int temp=square_nums[t+1];
   			square_nums[t+1]=square_nums[t];
   			square_nums[t]=temp;
   			flag=1;
		   }
	   }
	   if(flag==0)break;
   }
   return square_nums;
}//时间复杂度为O(n^2) 
