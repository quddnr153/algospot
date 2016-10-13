#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>

using namespace std;

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}
    int sum(int pos) {
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }
    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int N;

long long countMoves(const vector<int>& a) {
    FenwickTree tree(1000000);
    long long ret = 0;
    for(int i = 0; i < a.size(); i++) {
        ret += tree.sum(999999) - tree.sum(a[i]);
        tree.add(a[i], 1);
    }
    return ret;
}

void test()
{
    cin >> N;
    vector<int> A;
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        A.push_back(tmp);
    }
    printf("%llu\n", countMoves(A));
}

int main()
{
    int C;
    cin >> C;
    while(C--) test();
    return 0;
}
