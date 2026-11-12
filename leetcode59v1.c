/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 static int fillRing(int **a,int k,int len,int num) {
    int top=k, left=k, bottom=k+len-1, right=k+len-1;
    if (len == 1) {a[top][left] = num; return num + 1; }   /* 中心一格 */
    for (int j=left;j<=right;j++) a[top][j]=num++;
    for (int i=top+1;i<=bottom;i++) a[i][right]=num++;
    for (int j=right-1;j>=left;j--) a[bottom][j]=num++;
    for (int i=bottom-1;i>top;i--) a[i][left]=num++;
    return num;                                              /* 交给下一圈 */
}
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) (*returnColumnSizes)[i] = n;
    int **ans = malloc(sizeof(int*) * n);          //装指针，不是 sizeof(int)
    for (int i = 0; i < n; i++)
        ans[i] = malloc(sizeof(int) * n);
    int num=1;
    for(int k=0,len=n;len>0;k++,len-=2)
    num=fillRing(ans,k,len,num);
    //螺旋填数写进 ans[i][j]
    return ans;
}

