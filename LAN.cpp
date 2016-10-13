#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <string.h>
#include <math.h>

const int MAX_V = 500;
const int INF = 987654321.0;

using namespace std;

int N;
vector<pair<int,double> > adj[MAX_V];

bool doubleEqual(double a, double b) {
    double diff = fabs(a - b);
    if(diff < 1e-10) return true;
    return diff <= 1e-8 * max(fabs(a), fabs(b));
}

double minDelta = 0.0000001;

double prim(vector<pair<int,int> >& selected) {
    selected.clear();
    vector<bool> added(N, false);
    vector<double> minWeight(N, INF);
    vector<int> parent(N, -1);
    double ret = 0.0;
    minWeight[0] = 0.0;
    parent[0] = 0;
    for (int iter = 0; iter < N; ++iter) {
        int u = -1;
        for (int v = 0; v < N; v++) {
            if (!added[v] && (u == -1 || ((minWeight[u] - minWeight[v]) > minDelta)))
                u = v;
        }
        if(parent[u] != u)
            selected.push_back(make_pair(parent[u], u));
        ret += minWeight[u];
        added[u] = true;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            double weight = adj[u][i].second;
            if(!added[v] && ((minWeight[v] - weight) > minDelta)) {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }
    return ret;
}

double dis(int x1, int y1, int x2, int y2) {
    return sqrt((double)(x1 - x2) * (double)(x1 - x2) + (double)(y1 - y2) * (double)(y1 - y2));
}

void test()
{
    for(int i = 0; i < MAX_V; i++) adj[i].clear();
    int M, x[500], y[500];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", &x[i]);
    for(int i = 0; i < N; i++) scanf("%d", &y[i]);
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(i == j) continue;
            double tmp = dis(x[i], y[i], x[j], y[j]);
            adj[i].push_back(make_pair(j, tmp));
            adj[j].push_back(make_pair(i, tmp));
        }
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        for(int j = 0; j < adj[a].size(); j++){
            if(adj[a][j].first == b)
                adj[a][j].second = 0.0;
        }
        for(int j = 0; j < adj[b].size(); j++){
            if(adj[b][j].first == a)
                adj[b][j].second = 0.0;
        }
    }
    vector<pair<int,int> > selected;
    printf("%.10lf\n", prim(selected));
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) test();
    return 0;
}

