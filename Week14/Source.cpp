#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int to, length;
};
vector<node> table[100];
void dij(vector<node> tab[], int f, int t) {
	queue<int> field;
	int check[100] = {0};
	vector<int> stp;
	for (int i = 0; i < 100; i++) {
	stp.push_back(1e9);
	}
	stp[f] = 0;
	field.push(f);
	while (!field.empty()) {
		check[field.front()] = 1;
		for (int i = 0; i < tab[field.front()].size(); i++) {
			if (!check[tab[field.front()][i].to]) {
				if (stp[field.front()] + tab[field.front()][i].length < stp[tab[field.front()][i].to]) {
					stp[tab[field.front()][i].to] = stp[field.front()] + tab[field.front()][i].length;
				}
				field.push(tab[field.front()][i].to);
			}
		}
		field.pop();
	}
	cout << stp[t];
}
int main(){

	int from, target,n;
	cin >> n;
	cin >> from >> target;
	for (int i = 0; i < n; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		node temp;
		temp.length = l;
		temp.to = b;
		table[a].push_back(temp);
		temp.to = a;
		table[b].push_back(temp);
	}
	dij(table,from,target);
	return 0;
}
