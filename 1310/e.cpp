#include <bits/stdc++.h>

using namespace std ; 

#define pii pair<int,int>
#define maxN 100005 

template <class _T> bool maximize (_T &a , _T b) {return (a < b) ? a = b , 1 : 0 ; } 

int n , m 	; 
pii a[maxN] , b[maxN] ; 

void enter () {
	cin >> 	n >> m ;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i].first ; 
		a[i].second = i ; 
	}
	for (int i = 1 ; i <= m ; i ++) {
		cin >> b[i].first ; 
		b[i].second = i ; 
	}

	sort (a + 1 , a + 1 + n) ; 
	sort (b + 1 , b + 1 + m) ; 
}

long long maxSum[maxN] , sumOfLab[maxN] ; 
int lab[maxN] ; 
bool active [maxN] ; 

int getRoot(int u) {
	if (u == lab[u]) return lab[u] ;
	lab[u] = getRoot(lab[u]) ; 
	return lab[u] ;   
}

void unionElement (int Apos , int Bpos) {
	long long sum = sumOfLab[getRoot(Apos)] + sumOfLab[getRoot(Bpos)] ; 
	lab[getRoot(Apos)] = getRoot(Bpos) ; 
	sumOfLab[getRoot(Apos)] = sum ; 
}

void buildSumArr () {
	long long recentMaxSum = -1000000000000000000 ; 

	for (int i = 1 ; i <= n ; i ++) lab[i] = i , sumOfLab[a[i].second] = a[i].first ; 
	for (int i = n ; i >= 1 ; i --) {
		int position = a[i].second ; 
		if (position - 1 > 0 && active[position-1]) unionElement (position , position-1) ; 
		if (position + 1 <= n && active[position+1]) unionElement (position , position+1) ; 
		maximize(recentMaxSum , sumOfLab[getRoot(position)]) ; 
		maxSum[i] = recentMaxSum ; 
		active[position] = 1 ; 	
	}
}

long long res [maxN] ; 

void process () {
	buildSumArr() ; 

	int recentId = 1 ; 
	for (int i = 1 ; i <= m ; i ++) {
		while (recentId <= n && a[recentId].first < b[i].first) recentId ++ ; 
		if (recentId <= n) res[b[i].second] = maxSum[recentId] ; 
	}
	
	for (int i = 1 ; i <= m ; i ++) cout << res[i] << " " ; 
}

void code () {
	enter () ; 
	process () ; 
}

int main () {
	freopen("test.inp" , "r" , stdin) ; 
	freopen("test1.out" , "w" , stdout) ; 
	code () ; 
	return 0 ; 
}	