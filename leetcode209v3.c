int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, sum = 0, ans = numsSize + 1;
    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];//从一个开始把nums[0]装进sum，直到达标 
        while (sum >= target) {              // 达标了就尽量缩左边界
            int len = right - left + 1;//算出达标时长度 
            if (len < ans) ans = len;//if len合法 
            sum -= nums[left++];/*去掉左边的值。(为什么不去掉右边的值？
			因为不含右边的值的情况已经在上一轮for循环中验证过不达标了*/ 
        }
    }
    return ans == numsSize + 1 ? 0 : ans;/*
	== 
	if (ans == numsSize + 1)   // 问：ans 还是那个哨兵吗？
    return 0;
else
    return ans;
 */ 
}

