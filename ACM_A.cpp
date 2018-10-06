#include <bits/stdc++.h> 

using namespace std ; 

int a, b , maxScore , minScore , k ; 

void enter () {
	cin >> k >> a >> b ; 
	maxScore = max(a, b) ;
	minScore = min(a, b) ; 
	if (maxScore >= k) cout << 2 - (maxScore - minScore) << endl ;     
	else {
		int res = k - maxScore ;
		if (k - minScore < 2) res += 2 - (k - minScore) ; 
		cout << res << endl ;  
	}	    
}


int main () {
	int T ; 
	cin >> T ; 
	for (int i = 1 ; i <= T ; i ++) enter () ; 
	return 0 ; 
}