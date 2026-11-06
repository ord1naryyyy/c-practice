#include <stdio.h>
#define maxN 10000
#include <math.h>

int isprime(int n){
    if(n < 2) return 0;
    double temp = (double)n;
    for(int i = 2; i <= sqrt(temp); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int getprimes(int N, int arr[]){
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        if(isprime(i) == 1){
            arr[cnt] = i;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int N, count = 0;
    scanf("%d", &N);
    int p[maxN];
    int arr_num = getprimes(N, p);
    for(int i = 0; i < arr_num - 1; i++){
        if(p[i+1] - p[i] == 2){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
