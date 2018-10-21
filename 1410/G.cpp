#include <bits/stdc++.h> 

using namespace std ;

long long n , a , b , B ; 

long long gcdExtended(long long a, long long b, long long *x, long long *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    long long x1, y1; 
    long long gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

long long modInverse(long long a, long long m) { 
    long long  x, y; 
    long long g = gcdExtended(a, m, &x, &y); 
    long long res = (x%m + m) % m; 
    return res; 
}


long long power(long long a, long long b , long long MODULO) {
    if (b == 1) return a;
    long long tmp = power(a,b/2,MODULO);
    tmp = (tmp * tmp) % MODULO;
    if (b % 2) tmp = (tmp * a) % MODULO;
    return tmp;
}

void enter () {
	cin >> n >> a >> b >> B ; 
	long long above = ( (a % B) * power(B,n,B)) % B , under = b % B ; 
	cout << modInverse(above,under) << endl ; 
}

void code () {
	int T ; 
	cin >> T ; 
	for (int i = 1 ; i <= T ; i ++) enter () ; 
}

int main () {
	code () ; 
	return 0 ; 
}