#include <bits/stdc++.h>

using namespace std ; 

#define maxN 100005

int n , a[maxN] ; 

void enter () {
	cin >> n ; 
	for (int i = 1 ; i <= n ; i ++) cin >> a[i] ; 
	sort (a + 1 , a + 1 + n) ; 
	cout << (a[n] + a[n-1]) / 2 << endl ; 
}

int main () {
	enter () ; 
	return 0 ; 
}