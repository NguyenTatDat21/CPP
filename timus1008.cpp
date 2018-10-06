#include<bits/stdc++.h>
using namespace std;

bool d[100][100], dd[100][100];

int xx[4] = {1,0,-1,0}, 
    yy[4] = {0,1,0,-1};

char dir[4] = {'R', 'T', 'L', 'B'};

queue<pair<int, int>> q;

void visit(int x, int y) {
    // cout << x << " "  << y << endl;
    dd[x][y] = true;
    q.push(make_pair(x,y));
    while (!q.empty()) {
        for (int i = 0; i < 4; ++i) {
            int u = q.front().first + xx[i];
            int v = q.front().second + yy[i];
            // cout << u << " " << v << endl;
            if (u > 0 && v > 0 && d[u][v] && !dd[u][v]) {
                dd[u][v] = true;
                cout << dir[i];
                q.push(make_pair(u,v));
            }
        }
        q.pop();
        if (q.empty()) cout << '.';
        else cout << ",\n";
    }
}

int get(char ch) {
    if (ch == 'R') return 0;
    if (ch == 'T') return 1;
    if (ch == 'L') return 2;
    return 3;
}

set<pair<int, int>> ss;

int main() {
    int n, x, y, xMin, yMin;
    string st;
    getline(cin, st);
    if (st.find(" ") == string::npos) {
        n = stoi(st);
        for (int i = 0; i < n; ++i) {
            cin >> x >> y; 
            d[x][y] = true;
            if (i == 0) {xMin = x; yMin = y;}
        }
        cout << xMin << " " << yMin << endl;
        visit(xMin, yMin);
    // printf(".");
    }
    else {
        xMin = stoi(st.substr(0,st.size() - st.find(" ")));
        yMin = stoi(st.substr(st.find(" ")));
        q.push(make_pair(xMin, yMin));
        while (!q.empty()) {
            ss.insert(q.front());
            x = q.front().first;
            y = q.front().second;
            dd[x][y] = true;
            q.pop();
            cin >> st;
            if (st == ".") break;
            for (int i = 0; i < st.size()-1; ++i) {
                int dir = get(st[i]);
                int u = x + xx[dir];
                int v = y + yy[dir];
                q.push({u,v});
            }
        }
        cout << ss.size() << endl;
        for (auto x : ss) {
            cout << x.first << " " << x.second << endl;
        }   
    }
}