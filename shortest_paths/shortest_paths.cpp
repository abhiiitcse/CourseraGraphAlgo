#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  int n = adj.size();
  vector<int> cycle_path;
  distance[s] = 0;
  reachable[s] = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int u = j;
      if(distance[u] != std::numeric_limits<long long>::max()){
	for(int k=0;k<adj[u].size();k++){
	  int v = adj[u][k];
	  int weight = cost[u][k];
	  if((distance[u]+weight)<distance[v]){
	    distance[v] = distance[u] + weight;
	    if(reachable[u]){
	      reachable[v] = 1;
	    }
	    if(i==n-1){
	      cycle_path.push_back(v);
	    }
	  }
	}
      }
    }
  }
  for(int i=0;i<cycle_path.size();i++){
    int s = cycle_path[i];
    if(shortest[s]){
      queue<int> q;
      q.push(s);
      ///shortest[s] = 0;
      while(!q.empty()){
	int v = q.front();
	q.pop();
	shortest[v] = 0;
	for(int j=0;j<adj[v].size();j++){
	  if(shortest[adj[v][j]]){
	    q.push(adj[v][j]);
	  }
	}
      }
    }
  }      
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
