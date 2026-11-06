#include <stdio.h>

int gcd(int a, int b){
    while(b){ int t = a % b; a = b; b = t; }
    return a;
}

int main(){
    int N, M, a[100];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);

    M %= N;                       /* M 可以远大于 N */
    if(M){
        int g = gcd(N, M);        /* g 个互不相交的置换环 */
        for(int i = 0; i < g; i++){
            int j = i, tmp = a[i];
            while(1){
                int k = (j - M + N) % N;   /* a[j] 的新值来自旧 a[k] */
                if(k == i) break;
                a[j] = a[k];
                j = k;
            }
            a[j] = tmp;           /* 链尾回填 */
        }
    }

    for(int i = 0; i < N; i++){
        if(i) putchar(' ');       /* 结尾不留空格 */
        printf("%d", a[i]);
    }
    putchar('\n');
    return 0;
}

