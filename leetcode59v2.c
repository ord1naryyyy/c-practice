int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    int *cols = malloc(sizeof(int) * n);
    *returnColumnSizes = cols;
    for (int i = 0; i < n; i++) cols[i] = n;
    int **ans = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) ans[i] = malloc(sizeof(int) * n);

    int top=0, bottom=n-1, left=0, right=n-1, num=1;
    while (top <= bottom) {
        for (int j=left;    j<=right;   j++) ans[top][j]    = num++;
        for (int i=top+1;   i<=bottom;  i++) ans[i][right]  = num++;
        if (top < bottom)
            for (int j=right-1; j>=left; j--) ans[bottom][j] = num++;
        if (left < right)
            for (int i=bottom-1; i>top;  i--) ans[i][left]   = num++;
        top++; bottom--; left++; right--;         /* 收缩到下一圈 */
    }
    return ans;
}

