/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int l = 0, r = numsSize - 1, k = numsSize - 1;
    while (l <= r) {                    // "<="保证最后一个元素也被填
        int a = nums[l] * nums[l], b = nums[r] * nums[r];
        if (a > b)    { ans[k--] = a; l++; }
        else          { ans[k--] = b; r--; }
    }
    return ans;
}//时间复杂度为O(n) 

