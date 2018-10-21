#include <bits/stdc++.h>

using namespace std ; 

#define maxN 1005

int n , m , a[maxN] , b[maxN] ; 

bool test (int l , int r , int id) {
	for (int i = l ; i <= r ; i ++) if (a[i] < b[id]) return false ; 
	return true ; 
}

int sum (int l , int r) {
	int res = 0 ; 
	for (int i = l ; i <= r ; i ++) res += a[i] ; 
	return res ; 
}

int main () {
	freopen("test.inp" , "r" , stdin) ; 
	freopen("test.out" , "w" , stdout) ; 
	int n , m ; 
	cin >> n >> m ; 
	for (int i = 1 ; i <= n ; i ++) cin >> a[i] ; 
	for (int i = 1 ; i <= m ; i ++) cin >> b[i] ; 

	for (int i = 1 ; i <= m ; i ++) {
		int maxRes = -1000000000 ; 
		for (int j = 1 ; j <= n ; j ++) 
			for (int k = j ; k <= n ; k ++) if (test(j,k,i)) maxRes = max(maxRes , sum(j,k)) ; 
		cout << maxRes << " " ; 
	}

	return 0 ; 
}