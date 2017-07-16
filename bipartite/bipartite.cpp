#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  queue<int> q;
  int color[adj.size()];
  memset(color,-1,sizeof color);
  q.push(0);
  color[0] = 0;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int i=0;i<adj[v].size();i++){
      if(adj[v][i] == v){
	return 0;
      }
      if(color[adj[v][i]]==-1){
	color[adj[v][i]] = 1 - color[v];
	q.push(adj[v][i]);
      }else if(color[v] == color[adj[v][i]]){
	return 0;
      }
    }
		   
  }
  return 1;
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
  std::cout << bipartite(adj);
  std::cout<<std::endl;
}
