#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define mp make_pair
#define INF 100000

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::greater;
using std::cout;
using std::endl;
using std::cin;
using std::make_pair;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
  int dist[adj.size()];
  //memset(dist,INF,sizeof(dist));
  for(int i=0;i<adj.size();i++){
    dist[i] = INF;
  }
  dist[s] = 0;
  pq.push(mp(0,s));
  while(!pq.empty()){
    int v = pq.top().second;
    int d = pq.top().first;
    //std::cout<<"d="<<d<<" and v = "<<v<<std::endl;
    if(v==t){
      return d;
    }
    pq.pop();
    int temp;
    for(int i=0;i<adj[v].size();i++){
      //cout<<adj[v][i]<<" and dist = "<<dist[adj[v][i]]<<endl;
      //cin>>temp;
      if(dist[adj[v][i]] > (dist[v] + cost[v][i])){
	dist[adj[v][i]] = dist[v] + cost[v][i];
	pq.push(mp(dist[adj[v][i]],adj[v][i]));
      }
    }
  }
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
  std::cout<<std::endl;
}
