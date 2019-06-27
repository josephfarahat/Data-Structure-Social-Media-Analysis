#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <list>
#include <utility> 
using namespace std;

int main()
{
	// Un d i r e c t e d Weighted
	//freopen("datafile.txt", "r", stdin);
	int n, m;
	//entering the nodes and edges numbers
	cin >> n >> m;
	//vector<vector<int> > adjmatrix(n, vector<int>(n, 0));
	vector<list<pair<int, int>>> adj_list(n);
	int a, b, c;
	//entering source ,destination and weight
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		pair <int, int> p1, p2;
		p1.first = b;
		p1.second = c;
		p2.first = a;
		p2.second = c;
		adj_list[a].push_back(p1);
		adj_list[b].push_back(p2);
		//adjmatrix[a][b] = c;
		//adjmatrix[b][a] = c;
	}

	//printing degree centraility
	for (int j = 0; j < n; j++)
	{
		cout << adj_list[j].size() << "\n";
	}

	system("pause");
	return 0;
}


