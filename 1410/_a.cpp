#include <bits/stdc++.h> 

using namespace std ; 

#define maxN 1000005

template <class _T> bool maximize (_T &a , _T b) {return (a < b) ? a = b , 1 : 0 ; }
template <class _T> bool minimize (_T &a , _T b) {return (a > b) ? a = b , 1 : 0 ; }

int n , a[maxN] , m ; 

 int inf = 2000000000 ; 

int fastRead () {
	int res = 0 ; 
	char c ; 
	for ( ; (c < '0' || c > '9') && (c != '-') ; c = getchar () ) ; 
	bool negative = false ; 
	if (c == '-') {negative = true ; c = getchar() ; }
	for ( ; c >= '0' && c <= '9' ; c = getchar()) res = res * 10 + (int) c - (int) '0' ; 
	return (negative) ? -res : res ; 
}

void enter () {
	//scanf("%d", &n) ;n 
	//for (int i = 1 ; i <= n ; i ++) scanf("%d", &a[i]) ; 
	n = fastRead () ; 
	for (int i = 1 ; i <= n ; ++i ) a[i] = fastRead() ; 
}

int arrPLus[maxN] , arrSub[maxN] ; 

void prepare () {
	map<int,int> value ; 
	for (int i = 1 ; i <= n ; i ++) {
		value[a[i]] = 0 ; 
		arrPLus[i] = a[i] + i ;
		arrSub[i] = a[i] - i ; 
	}

	for (auto &temp : value) temp.second = ++m ; 
	for (int i = 1 ; i <= n ; i ++) a[i] = value[a[i]] ; 
}

int BITPlus[maxN] , BITSub[maxN] ; 

void updateBitPlus (int id , int x) {
	for ( ; id <= m ; id += id & (-id)) minimize(BITPlus[id] , x) ; 
}

int getBitPlus (int id) {
	int res = inf ;
	for ( ; id > 0 ; id -= id & (-id)) minimize(res , BITPlus[id]) ; 
	return res ; 
}

void updateBitSub (int id , int x) {
	for ( ; id > 0 ; id -= id & (-id)) maximize (BITSub[id] , x ) ; 
}

int getBitSub (int id) {
	int res = -inf ; 
	for ( ; id <= m ; id += id & -id) maximize (res , BITSub[id]) ;
	return res ;  
} 		

void initBIT () {
	for (int i = 1 ; i <= m ; i ++) BITPlus[i] = inf , BITSub[i] = -inf ; 
}

void process () {
	prepare () ; 
	initBIT () ; 

	int res = 0 ;
	for (int i = 1 ; i <= n ; i ++) {
		int gPLus = getBitPlus(a[i]) , gSub = getBitSub(a[i]) ; 
		int tempPlus = arrPLus[i] - gPLus , tempSub = gSub - arrSub[i] ;
		if (gPLus < inf) maximize(res , tempPlus) ; 
		if (gSub > -inf) maximize(res , tempSub) ; 
		updateBitPlus(a[i] , arrPLus[i]) ; 
		updateBitSub(a[i] , arrSub[i]) ; 
	}

	printf("%d\n", res); 
}

int main () {
	enter () ; 
	process () ; 
	return 0 ; 
}