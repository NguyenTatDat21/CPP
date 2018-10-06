#include<bits/stdc++.h>
using namespace std;
#define INF 10000


int n, m;
vector<pair<int, int>> adj[200];
int d[200], trace[200];
vector<int> res;
int minCycle;
bool dd[200];


void dij(int s, int t, int w) {
    // cerr << s << " " << t << endl;
    for (int i = 1; i <= n; ++i) dd[i] = false; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; ++i) d[i] = INF;
    d[s] = 0;
    pq.push({0,s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (dd[u]) continue;
        dd[u] = true;
        for (auto x : adj[u]) {
            int v = x.first;
            int c = x.second;
            if ((u != s || v != t) && (u != t || v != s)) {
                if (d[v] > d[u] + c) {
                    trace[v] = u;
                    d[v] = d[u] + c;
                    pq.push({d[v],v});
                }
            }
        }
    }
    // for (int i = 1; i <= n; ++i) cerr << d[i] << " "; cerr << endl;
    if (d[t] < INF) {
        if (minCycle > d[t] + w) {
            minCycle = d[t] + w;
            res.resize(0);
            res.push_back(t);
            while(t != s) {
                t = trace[t];
                res.push_back(t);
            }
        }
    }
}

bool test() {
    
    map<pair<int, int>, int> a;
    scanf("%d", &n);
    minCycle = INF;
    if (n == -1) return false;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        if (v < u) {
            int tmp = u;
            u = v;
            v = tmp;
        }
        if (a.find({u,v})!=a.end()) 
            a[{u,v}] = min(a[{u,v}], c);
        else a[{u,v}] = c;

    }
    for (int i = 1; i <= n; ++i) adj[i].resize(0);
    for (auto x : a) {
        adj[x.first.first].push_back({x.first.second,x.second});
        adj[x.first.second].push_back({x.first.first,x.second});
        // cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
    for (auto x : a) {
        dij(x.first.first, x.first.second, x.second);
    }
    if (minCycle < INF) {
        for (auto x : res) {
            printf("%d ", x);
        }
        printf("\n");
    }
    else printf("No solution.\n");
    return true;
}

int main() {
    while (test()) ;
}