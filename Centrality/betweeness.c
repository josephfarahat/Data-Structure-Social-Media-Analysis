#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <functional>
#define INF 1e9
using namespace std;

void printpath(vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		cout << path[i] << " ";
	cout << "\n";
}

int calculate_weight(vector<int>& path, vector<vector<pair<int, int>> >&g)
{
	int weight = 0;
	for (int i = 0; i<path.size() - 1; i++)
	{
		int j = 0;
		while (j<g[path[i]].size())
		{
			if (g[path[i]][j].first == path[i + 1])
				weight += g[path[i]][j].second;
			j++;
		}

	}
	return weight;
}

int isNotVisited(int x, vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		if (path[i] == x)
			return 0;
	return 1;
}

vector<vector <int>> findpaths(vector<vector<pair<int, int>> >&g, int src,
	int dst, int v, vector<int> &weights)
{

	queue<vector<int> > q;
	vector<int> path;

	vector<vector <int>> all_paths;
	path.push_back(src);
	q.push(path);
	while (!q.empty()) {
		path = q.front();
		q.pop();
		int last = path[path.size() - 1];

		if (last == dst)
		{
			int path_weight = calculate_weight(path, g);
			weights.push_back(path_weight);
			all_paths.push_back(path);
		}

		for (int i = 0; i < g[last].size(); i++) 
		{
			if (isNotVisited(g[last][i].first, path)) 
			{
				vector<int> newpath(path);
				newpath.push_back(g[last][i].first);
				q.push(newpath);
			}
		}

	}
	return all_paths;
}
vector<vector <int>> filtered(vector<vector <int>> all_paths, vector<int> weights)
{
	int shortest_path_weight = *min_element(weights.begin(), weights.end());
	vector<vector<int>>filtered_paths;
	for (int i = 0; i<weights.size(); i++)
	{
		if (weights[i] == shortest_path_weight)
			filtered_paths.push_back(all_paths[i]);
	}

	return filtered_paths;

}
int no_of_immediate(vector<vector <int>> all_paths, int node)
{
	int count = 0;
	for (int i = 0; i<all_paths.size(); i++)
		for (int j = 1; j<all_paths[i].size() - 1; j++)
		{
			if (all_paths[i][j] == node)
			{
				count++;
				break;
			}
		}
	return count;
}

int main()
{
	//freopen("datafile2.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
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



	vector<double> betweenness_centrality(n, 0);
	for (int k = 0; k<n; k++)
	{
		for (int i = 0; i<n; i++)
		{
			for (int j = i + 1; j<n; j++)
			{
				vector<int> path_weights;
				vector<vector <int>> all_paths;
				vector<vector <int>> filtered_paths;
				all_paths = findpaths(adj_list, i, j, n, path_weights);
				filtered_paths = filtered(all_paths, path_weights);
				betweenness_centrality[k] += double(no_of_immediate(filtered_paths, k)) / filtered_paths.size();
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout.precision(12);
		cout <<fixed << betweenness_centrality[i];
		cout << "\n";
	}
	
	//system("pause");
	return 0;
}