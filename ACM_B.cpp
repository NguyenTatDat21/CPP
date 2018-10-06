#include <bits/stdc++.h> 

using namespace std ; 

#define maxN 105

template <class _T> bool minimize (_T &a , _T b) {return (a > b) ? a = b , 1 : 0 ; }
template <class _T> bool maximize (_T &a , _T b) {return (a < b) ? a = b , 1 : 0 ; }

int n , m , k , a[maxN][maxN] ; 

void enter () {
	cin >> n >> m >> k ; 
	for (int i = 1 ; i <= n ; i ++) 
		for (int j = 1 ; j <= m ; j ++) cin >> a[i][j] ; 
}

bool checkImposs () {
	for (int i = 1 ; i <= n ; i ++) {
		int startPoint = 0 ; 
		for (int j = 1 ; j <= m ; j ++) if (!a[i][j]){
			if (j - startPoint - 1 > k) return false ; 
			startPoint = j ;   
		}
		if (m - startPoint > k) return false ;  
	}

	for (int i = 1 ; i <= m ; i ++) {
		int startPoint = 0 ; 
		for (int j = 1 ; j <= n ; j ++) if (!a[j][i]) {
			if (j - startPoint - 1 > k) return false ; 
			startPoint = j ; 
		}
		if (n - startPoint > k) return false ; 
	}

	return true ; 
}

bool visit[maxN][maxN] ; 
int wallPainted[maxN][maxN] ; 

#define pii pair<int , int> 

int goX[4] = {-1 , 0 , +1 , 0} ;  
int goY[4] = { 0 ,-1 ,  0 ,+1} ; 

int cntNumber = 0 ,  number [maxN][maxN] ;

void findEdge (int row , int col , int &maxX , int &minX , int &maxY , int &minY) {
	cntNumber ++ ; 
	queue<pii> myCell ; 
	myCell.push({row,col}) ; visit[row][col] = true ;  
	number[row][col] = cntNumber ; 

	while (myCell.size() > 0) {
		pii temp = myCell.front() ; 
		myCell.pop() ; 
		number[temp.first][temp.second] = cntNumber ; 

		maxX = max(maxX , temp.first) ; 
		minX = min(minX , temp.first) ; 
		maxY = max(maxY , temp.second) ; 
		minY = min(minY , temp.second) ; 

		for (int i = 0 ; i < 4 ; i ++) {
			int nxtX = temp.first + goX[i] , nxtY = temp.second + goY[i] ;
			if (nxtX > 0 && nxtY > 0 && nxtX <= n && nxtY <= m && !visit[nxtX][nxtY] && a[nxtX][nxtY]) {
				myCell.push ({nxtX , nxtY}) ; 
				visit[nxtX][nxtY] = true ; 
			}
		}
	}

}

int virtualTable [maxN][maxN] ; 

void makeVirtualTable (int nRow , int nCol) {
	deque <int> myRow ; 
	for (int i = 1 ; i <= nCol ; i ++) myRow.push_back(i) ;
	for (int i = 1 ; i <= nRow ; i ++) {
		for (int j = 1 ; j <= nCol ; j ++) virtualTable[i][j] = myRow[j-1] ; 
		myRow.push_back(myRow.front()) ; 
		myRow.pop_front() ; 
	}
}

void painting (int row , int col) {

	int maxX = 0 , maxY = 0 , minX = 1000000000 , minY = 1000000000 ; 
	findEdge (row , col , maxX , minX , maxY , minY) ;

	int lengX = maxX - minX  + 1 , lengY = maxY - minY + 1 ; 
	makeVirtualTable (min(lengX,lengY) , max(lengX , lengY)) ; 

	if (lengX < lengY) {
		for (int i = minX ; i <= maxX ; i ++) {
			for (int j = minY ; j <= maxY ; j ++) if (number[i][j] == number[row][col]) {
				wallPainted[i][j] = virtualTable[i-minX+1][j-minY+1] ; 
			}
		}
	} else {
		for (int i = minX ; i <= maxX ; i ++){
			for (int j = minY ; j <= maxY ; j ++) if (number[i][j] == number[row][col]) {
				wallPainted[i][j] = virtualTable[j-minY+1][i-minX+1] ; 
			}
		}
	}
}

void process () {	
	if (!checkImposs()) {
		cout << "NO" << endl ; 
		return ; 
	}

	cout << "YES" << endl ; 

	for (int i = 1 ; i <= n ; i ++) 
		for (int j = 1 ; j <= m ; j ++) if (!visit[i][j] && a[i][j]) painting (i,j) ; 

	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= m ; j ++) cout << wallPainted[i][j] << " " ; 
		cout << endl ; 
	}
}

void code () {
	int T ; 
	cin >> T ; 
	for (int i = 1 ; i <= T ; i ++ ) {
		enter () ; 
		process () ; 
	}
}

int main () {
	freopen("test.inp" , "r" , stdin) ; 
	code () ; 
	return 0 ; 
}