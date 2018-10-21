#include <bits/stdc++.h> 

using namespace std ; 

#define maxN 100005

int n , d , cntRow[1005] , cntCol[1005]; 

void enter () {
	scanf("%d%d" , &d , &n) ; 
	for (int i = 0 ; i < d ; i ++) cntCol[i] = 0 , cntRow[i] = 0 ; 
	for (int i = 1 ; i <= n ; i ++) {
		int x , y ; 
		scanf("%d%d" , &x , &y) ;
		x += 1000000000 ; 
		y += 1000000000 ; 
		cntRow[x % d] ++ ; 
		cntCol[y % d] ++ ; 
		if (x % d == y % d) cntCol[y%d] -- ; 
	}

	int minRow = 1000000000 , minCol = 1000000000 , res = 1000000000 ; 

	for (int modun = 0 ; modun < d ; modun ++) {
		minRow = min(minRow , cntRow[modun]) , minCol = min(minCol , cntCol[modun]) ; 
		res = min(res , minRow + minCol) ; 
	}

	printf("%d\n" , res) ;
}

int main () {
	int T = 0 ; 
	scanf("%d" , &T) ; 
	while (T--) enter () ; 
	return 0 ; 
}