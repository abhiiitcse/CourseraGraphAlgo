#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool isCycleUtils(vector<vector<int> > &adj, bool *visited, bool *recStack, int x){
  if(!visited[x]){
    visited[x] = true;
    recStack[x] = true;
    for(int i=0;i<adj[x].size();i++){
      if(!visited[adj[x][i]] && isCycleUtils(adj,visited, recStack, adj[x][i])){
	return true;
      }else if(recStack[adj[x][i]]){
	return true;
      }
    }
  }
  recStack[x] = false;
  return false;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  bool visited[adj.size()];
  bool recStack[adj.size()];
  memset(visited, false, sizeof(visited));
  memset(recStack,false,sizeof(recStack));
  for(int i=0;i<adj.size();i++){
    if(isCycleUtils(adj, visited, recStack,i)){
      return 1;
    }	
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj)<<std::endl;
}
