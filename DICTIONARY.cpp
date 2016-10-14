#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;



void test()
{
    int n;
    scanf("%d", &n);
    vector<string> words;
    for(int i = 0; i < n; i++) {
        string tmp;
        scanf("%s", &tmp);
        words.push_back(tmp);
    }

}

int main()
{
    int C;
    scanf("%d", &C);
    while(C--) test();
    return 0;
}
