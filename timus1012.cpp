#include<bits/stdc++.h>
using namespace std;
#define maxN 2000


int n,k;

struct bigInt {
    vector<int> arr;
    bigInt() {
        arr.resize(0);
        arr.push_back(0);
    }
    bigInt(int x) {
        arr.resize(0);
        do {
            arr.push_back(x % 1000000);
            x /= 1000000;
        } 
        while (x); 
    }
    int size() {
        return arr.size();
    }
    bigInt operator + (bigInt other) {
        bigInt tmp;
        int sa = arr.size();
        int sb = other.arr.size();
        tmp.arr.resize(max(sa,sb));
        int c = 0;
        for (int i = 0; i < max(sa,sb); ++i) {
            tmp.arr[i] = c;
            if (i < sa) tmp.arr[i] += arr[i];
            if (i < sb) tmp.arr[i] += other.arr[i]; 
            c = tmp.arr[i] / 1000000;
            tmp.arr[i] %= 1000000;
        }
        if (c) tmp.arr.push_back(c);
        return tmp;
        
    }
    
    bigInt operator * (int other) {
        bigInt tmp;
        for (int i = 0; i < other; ++i) {
            tmp = tmp + (*this);  
        }
        // ((*this).print());
        // cout << other << endl;
        // tmp.print();
        return tmp;
    }
    void print() {
        printf("%d",arr[arr.size()-1]);
        for (int i = arr.size()-2; i >= 0; --i) printf("%06d", arr[i]);
        printf("\n");
    }
};

bigInt f[maxN][2];

int main() {
    scanf("%d%d", &n, &k);
    // f[0][1].print();
    bigInt one(1);
    f[0][1] = one;
    for (int i = 1; i <= n; ++i) {
        f[i][0] = f[i-1][1];
        f[i][1] = (f[i-1][0] + f[i-1][1]) * (k-1);
    }
    f[n][1].print();
}