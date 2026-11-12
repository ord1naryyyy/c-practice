int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int w = 1;                              /* 写入位置：下一个该放的位置 */
    for (int r = 1; r < numsSize; r++)      /* 读取位置：只往前走 */
        if (nums[r] != nums[w-1])           /* 和已保留的最后一个比 */
            nums[w++] = nums[r];
    return w;                               /* w 本身就是长度，不用另外减 */
}

