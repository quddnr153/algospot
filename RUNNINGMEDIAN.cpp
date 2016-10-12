#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct RNG {
    int seed, a, b;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next() {
        int ret = seed;
        seed = ((seed * (long long)a) + b) % 20090711;
        return ret;
    }
};

int runningMedian(int n, RNG rng) {
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int ret = 0;
    for(int cnt = 1; cnt <= n; cnt++) {
        if(maxHeap.size() == minHeap.size()) maxHeap.push(rng.next());
        else minHeap.push(rng.next());
        if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int a = maxHeap.top(), b = minHeap.top();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
        ret = (ret + maxHeap.top()) % 20090711;
    }
    return ret;
}

void test()
{
    int N, a, b;
    scanf("%d %d %d", &N, &a, &b);
    RNG rng(a, b);
    printf("%d\n", runningMedian(N, rng));
}

int main()
{
    int C;
    scanf("%d", &C);
    while(C--) test();
    return 0;
}
