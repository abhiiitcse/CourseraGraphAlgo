#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  int dist[adj.size()];
  int parent[adj.size()];
  memset(dist,-1,sizeof dist);
  memset(parent,-1,sizeof parent);
  queue<int> q;
  q.push(s);
  dist[s] = 0;
  while(!q.empty()){
    int v = q.front();
    if(v==t){
      return dist[v];
    }
    q.pop();
    for(int i=0;i<adj[v].size();i++){
      if(dist[adj[v][i]]==-1){
	dist[adj[v][i]] = dist[v] + 1;
	parent[adj[v][i]] = v;
	q.push(adj[v][i]);
      }
    }
  }
  
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
  std::cout<<std::endl;
}
