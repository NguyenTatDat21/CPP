#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a = 1;
    int b = 1;
    int c = n - 2;
    if (c % 3 ==0) {
        ++b;
        --c;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}