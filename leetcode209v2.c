int minSubArrayLen(int target, int* nums, int numsSize) {
    int return_val=0;
    for(int i=0;i<numsSize;i++){
    	int left=0;
    	int right=left+i;
    	int all=0;
    	for(int j=0;j<numsSize;j++){
    	 for(int t=left;t<=right;t++){
    		all+=nums[t];
		 } 
		 if(all>=target){
			return_val=i+1;
			break;
		 }else{all=0;}
		 if(right==numsSize-1)break;
		 left++;
		 right++;
	   }
	        if(right==numsSize-1);   
	  		if(all>=target){
			break;
		    } 
	 }
    
    return return_val;
}// leetcode第209题时间复杂度为O(n^3)版本
