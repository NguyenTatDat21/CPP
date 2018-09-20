#include<bits/stdc++.h> 
using namespace std;

long long n, k , m;

long long mul(long long a, long long b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    long long tmp = mul(a,b/2);
    tmp = (tmp * 2) % m;
    if (b%2) tmp = (tmp + a) % m;
    return tmp;
}


struct matrix {
    long long arr[2][2];
    matrix();
    matrix(long long a, long long b, long long c, long long d) {
        arr[0][0] = a % m ; arr[0][1] = b % m;
        arr[1][0] = c % m ; arr[1][1] = d & m;
    }
    
    matrix operator * (matrix other) {
        matrix tmp(0,0,0,0);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) 
                    tmp.arr[i][j] = (tmp.arr[i][j] + mul(arr[i][k], other.arr[k][j])) % m;
            }
        }
        return tmp;
    }
    matrix pow(long long x) {
        if (x == 1) return (*this);
        matrix tmp = (*this).pow(x/2);
        tmp = tmp * tmp;
        if (x%2) tmp = tmp * (*this);
        return tmp;
    }

    void debug() {
        cerr << arr[0][0] << " " << arr[0][1] << endl << arr[1][0] << " " << arr[1][1] << endl;
    }
};





int main() {
    scanf("%I64d%I64d%I64d", &n, &k, &m);
    matrix a(k-1,k-1,1,0);
    matrix b(k-1,0,1,0);
    matrix c = a.pow(n-1) * b;
    printf("%I64d", c.arr[0][0]);
}