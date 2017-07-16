#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

vector<vector<int> > transposeGraph(vector<vector<int> > adj){
  vector<vector<int> > gr(adj.size(),vector<int>());
  for(int i=0;i<adj.size();i++){
    for(int j=0;j<adj[i].size();j++){
      gr[adj[i][j]].push_back(i);
    }
  }
  return gr;
      
}

void dfs(vector<vector<int> > adj, bool *visited, int x, stack<int> &st){
  visited[x] = true;
  for(int i=0;i<adj[x].size();i++){
    if(!visited[adj[x][i]]){
      dfs(adj,visited,adj[x][i],st);
    }
  }
  st.push(x);
}

void dfs_scc_gr(vector<vector<int> > adj, bool *visited, int v){
  visited[v] = true;
  for(int i=0;i<adj[v].size();i++){
    if(!visited[adj[v][i]])
      dfs_scc_gr(adj, visited, adj[v][i]);
  }
  
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  stack<int> st;
  bool visited[adj.size()];
  memset(visited, false, sizeof visited);
  for(int i=0;i<adj.size();i++){
    if(!visited[i]){
      dfs(adj, visited, i, st);
    }
  }
  vector<vector<int> > gr = transposeGraph(adj);
  memset(visited,false, sizeof visited);
  while(!st.empty()){
    int v = st.top();
    st.pop();
    if(!visited[v]){
      result++;
      dfs_scc_gr(gr, visited, v);
    }
    
    
  }
  
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
  std::cout<<std::endl;
}
