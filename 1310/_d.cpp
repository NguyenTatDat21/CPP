#include <bits/stdc++.h>

using namespace std ; 

#define maxN 10005

int a[maxN] , n , k ; 

int fast_max(int n) { 
    int ans = 0;
    int offset = 0;
    for (int i = 0; i < n; ++i)
        if (ans < a[i]) {
            ans = a[i];
            offset = 0;
        } else {
            offset = offset + 1;
            if (offset == k)
                return ans;
        }
    return ans;
}

int main () {
	int cnt = 0 , cnt1 = 0 ;
	cin >> n >> k ;
	for (int i = 0 ; i < n ; i ++ ) a[i] = i + 1 ; 
	do {
		cnt1 ++ ; 
		if (fast_max(n) != n) {
			//for (int i = 0 ; i < n ; i ++) cout << a[i] << " " ; cout << endl ; 
			cnt ++ ;  
		};  
		//for (int i = 0 ; i < n ; i ++) cout << a[i] << " " ; cout << endl ; 
	} while (next_permutation(a , a + n)) ; 

	// cout << cnt1 << endl ; 
	cout << cnt << endl ; 
}