#include <iostream>
#include <vector>

using namespace std;
bool dfs(vector<vector<int> > &adj,int x,int y,bool visited[]){
  if(x==y)
    return true;
  visited[x] = true;
  for(int i=0;i<adj[x].size();i++){
    if(!visited[adj[x][i]]){
      if(dfs(adj,adj[x][i],y,visited)){
	return true;
      }
    }
  }
  return false;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  bool visited[adj.size()];
  memset(visited,false,sizeof(visited));
  if(dfs(adj,x,y,visited)){
    return 1;
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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1)<<endl;
}
