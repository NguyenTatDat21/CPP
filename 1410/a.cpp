#include<bits/stdc++.h>
using namespace std;
#define maxN 1123456

int x[maxN], mx[maxN], mn[maxN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
	int res = 0;
	mx[1] = x[1] - 1;
	mn[1] = x[1] + 1;
 	for (int i = 2; i <= n; ++i) {
		mx[i] = max(mx[i-1], x[i] - i);
		mn[i] = min(mn[i-1], x[i] + i);
		res = max(res, max(x[i] + i - mn[i], mx[i] - x[i] + i));
	}
	printf("%d", res);
}