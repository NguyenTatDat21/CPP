#include <bits/stdc++.h>

using namespace std ; 

string st ; 
int n , inf = 10000 ; 

template <class _T> bool maximize (_T &a , _T b) {return (a < b) ? a = b , 1 : 0 ; }
template <class _T> bool minimize (_T &a , _T b) {return (a > b) ? a = b , 1 : 0 ; }

void enter () {
	cin >> st ; 
	n = st.length() ; 
}

int cnt[300] ;  

string ans ;

void process () {
	int optiMaximal = 0 , minleng = inf , recentSize = 0 ; 

	for (int i = 0 ; i < n ; i ++) {
		for (char c = 'A' ; c <= 'Z' ; c ++) cnt[c] = 0 ; 
		int recentMaximal = 0 ;	
		string recentS = "" ; 

		for (int j = i ; j < n ; j ++) {
			cnt[st[j]] ++ ; recentS += st[j] ;

			if (cnt[st[j]] == 1) recentMaximal ++ ;  else if (cnt[st[j]] == 2) recentMaximal -- ;  
			//for (char c = 'A' ; c <= 'Z' ; c++) cout << cnt[c] << " " ; cout << endl ; 

			if (maximize(optiMaximal , recentMaximal)) {
				minleng = j-i+1 ; 
				ans= recentS ;                                                                 
			} else if (optiMaximal == recentMaximal && ans > recentS) ans = recentS ; 
		}
	}
                                                                
	cout << ans << endl ; 
}

int main () {
	enter () ; 
	process () ; 
	return 0 ; 
}