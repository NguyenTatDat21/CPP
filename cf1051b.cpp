#include<bits/stdc++.h>
using namespace std;

int main() {
    long long l, r;
    scanf("%I64d%I64d", &l, &r);
    printf("YES\n");  
    for (int i = 0; i < (r-l+1) / 2; ++i) {
        printf("%I64d %I64d\n", l+2*i, l+2*i+1);
    } 

}