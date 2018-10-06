#include <bits/stdc++.h>

using namespace std ; 

#define maxN 10004

int n , a[maxN] ; 

int main () {
	cin >> n ; 
	for (int i = 1 ; i <= n ; i ++) cin >> a[i] ; 
	sort (a + 1 , a + 1 + n) ; 
	for (int i = n ; i - 4 + 1 > 0 ; i --) if (a[i] < a[i-1] + a[i-2] + a[i-3]) {
		if (a[i] == a[i-1] && a[i-1] == a[i-2] && a[i-2] == a[i-3]) continue ; 
		cout << a[i] + a[i-1] + a[i-2] + a[i-3] ; 
		return 0 ; 
	}
	cout << -1 << endl ; 
	return 0 ; 
}