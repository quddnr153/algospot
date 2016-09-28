#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>

using namespace std;

int n, m; // n: 친구의 수, m: 할 줄 아는 음식의 수
vector<int> canEat[50], eaters[50];
string names[50];
int best;

void search(vector<int>& edible, int chosen)
{
	if (chosen >= best) return;
	int first = 0;
	while (first < n && edible[first] > 0) ++first;
	if (first == n) { best = chosen; return; }
	for (int i = 0; i < canEat[first].size(); ++i) {
		int food = canEat[first][i];
		for (int j = 0; j < eaters[food].size(); ++j)
			edible[eaters[food][j]]++;
		search(edible, chosen + 1);
		for (int j = 0; j < eaters[food].size(); ++j)
			edible[eaters[food][j]]--;
	}
}

void test()
{
	best = 50;
	cin >> n >> m;
	for (int i = 0; i < 50; i++) {
		canEat[i].clear();
		eaters[i].clear();
	}
	for (int i = 0; i < n; ++i)
		cin >> names[i];
	for (int food = 0; food < m; ++food) {
		int count;
		cin >> count;
		for (int j = 0; j < count; ++j) {
			string tmp;
			cin >> tmp;
			for (int k = 0; k < n; ++k) {
				if (tmp.compare(names[k]) == 0) {
					canEat[k].push_back(food);
					eaters[food].push_back(k);
				}
			}
		}
	}
	vector<int> edible;
	for (int i = 0; i < n; ++i) edible.push_back(0);
	search(edible, 0);
	cout << best << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
		test();
	cin >> T;
	return 0;
}