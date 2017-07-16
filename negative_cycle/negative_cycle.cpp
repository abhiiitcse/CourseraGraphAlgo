#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  int n = adj.size();
  int dist[n];
  for(int i=0;i<n;i++){
    dist[i] = INT_MAX;
  }
  dist[0] = 0;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<adj[j].size();k++){
	int u = j;
	int v = adj[u][k];
	int weight = cost[u][k];
	if((dist[u]!=INT_MAX)&&((dist[u]+weight)<dist[v])){
	  dist[v] = dist[u] + weight;
	}
      }
    }
  }
  for(int j=0;j<n;j++){
    for(int k=0;k<adj[j].size();k++){
      int u = j;
      int v = adj[u][k];
      int weight = cost[u][k];
      if((dist[u]!=INT_MAX)&&((dist[u]+weight)<dist[v])){
	return 1;
      }
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
  std::cout<<std::endl;
}
