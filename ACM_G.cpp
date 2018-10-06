#include <bits/stdc++.h> 

using namespace std ; 

#define maxN 10

int n , a[maxN] ; 

void enter () {
	cin >> n ; 
	for (int i = 1 ; i <= n ; i ++) cin >> a[i] ; 
}

int res = 0 ; 

void backTrack (int recentId , int sum) { 
	//cout << sum << endl ; 
	if (recentId > n) {
		res = max(res , sum) ; 
		return ; 
	}

	int recentSum = sum + a[recentId + 1] , temp = recentSum; 

	vector <int> digit ; digit.clear() ; 
	while (temp > 0) digit.push_back(temp % 10) , temp /= 10 ; 
	//for (auto c : digit) cout << c << " " ; 

	sort (digit.begin () , digit.end()) ; 
	do  {
		//for (auto c : digit) cout << c << " " ; cout << endl ; 
		int power = 1 , nextSum = 0 ; 
		for (int i = 0 ; i < digit.size() ; i ++) {
			nextSum += digit[i] * power ; 
			power *= 10 ; 
		}
		backTrack (recentId + 1 , nextSum) ; 
	} while (next_permutation(digit.begin() , digit.end())) ; 
}

void process () {
	backTrack (0,0) ; 
	cout << res << endl ;
}

void code () {
	enter () ; 
	process () ; 
}

int main () {
	code () ; 
	return 0 ; 
}