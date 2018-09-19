#include<bits/stdc++.h> 
using namespace std;

long long n, k , m;


struct matrix {
    long long arr[2][2];
    matrix(long long a, long long b, long long c, long long d) {
        arr[0][0] = a % m ; arr[0][1] = b % m;
        arr[1][0] = c % m ; arr[1][1] = d & m;
    }
    
    matrix operator * (matrix other) {
        matrix tmp(0,0,0,0);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) 
                    tmp.arr[i][j] = tmp.arr[i][j] + arr[i][k] * other.arr[k][j] % m)
            }
        }
    }
};



int main() {
    scanf("%I64d%I64d%I64d", &n, &k, &m);
}