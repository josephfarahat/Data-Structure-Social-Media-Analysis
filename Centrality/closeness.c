#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <list>
#include <utility>
#define INF 1e9
using namespace std;


vector<int> shortest_distance(int src,
	vector<vector<pair<int, int> > > adj_list){

	int n = adj_list.size();
	vector<int>	dis(n, INF);
	vector<int> p(n, -1);

	dis[src] = 0;
	for (int it = 0; it<n - 1; it++){
		// Loop over all edges
		// Loop over all edges
		for (int u = 0; u<n; u++)
		{
			for (int e = 0; e<adj_list[u].size(); e++)
			{
				int v = adj_list[u][e].first;
				int w = adj_list[u][e].second;

				if (dis[u] + w < dis[v])
				{
					dis[v] = dis[u] + w;
					p[v] = u;
				}
			}
		}
	}

	return dis;
}


int main()
{
	//freopen("datafile.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjmatrix(n, vector<int>(n, 0));
	vector<vector<pair<int, int>>> adj_list(n);
	int a, b, c;
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
		
	}


	//summing the shortest distances for each source node 
	vector<double> sum_shortest_path(n, 0);
	for (int i = 0; i<n; i++)
	{
		vector<int> distance = shortest_distance(i, adj_list);
		for (int node = 0; node <n; node++){
			//	cout<<distance[node]<<endl;
			sum_shortest_path[i] += distance[node];
		}
	}
	//calcultaing closeness 
	for (int i = 0; i<n; i++)
	{
		sum_shortest_path[i] = double(n - 1) / sum_shortest_path[i];
	}
	//printing closeness
	for (int i = 0; i<n; i++)
	{
		//to print 12 decimals places
		cout.precision(12);
		cout << fixed<<sum_shortest_path[i] << "\n";
	}

	//system("pause");
	return 0;
}
