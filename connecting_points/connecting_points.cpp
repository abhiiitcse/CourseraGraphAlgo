#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#define pb push_back
#define mp make_pair

using namespace std;
typedef pair<int,int> pii;

struct subset{
  int parent;
  int rank;
};

struct vertex{
  int parent;
  int rank;
  int x,y;
  vertex(int a,int b,int p,int r){
    x=a;y=b;parent=p;rank=r;
  }
};

struct edge{
  int x,y;
  double weight;
  edge(int a,int b,int w){
    x=a;y=b;weight=w;
  }
};

double findDistance(vertex a,vertex b){
  int x1 = a.x; int y1 = a.y;
  int x2 = b.x; int y2 = b.y;
  double dist = sqrt((double)((((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)))));
  cout<<"dist="<<dist<<endl;
  return dist;
}

double getDist(int x1,int x2,int y1,int y2){
  double retVal = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
  return retVal;
}

int find(struct subset sub[],int x){
  while(sub[x].parent!=x){
    sub[x].parent = find(sub,sub[x].parent);
  }
  return sub[x].parent;
}

void union1(struct subset sub[], int x, int y){
  int xroot = find(sub,x);
  int yroot = find(sub,y);
  if(sub[xroot].rank < sub[yroot].rank){
    sub[xroot].parent = yroot;
  }else if(sub[x].rank > sub[yroot].rank){
    sub[yroot].parent = xroot;
  }else{
    sub[yroot].parent = xroot;
    sub[xroot].rank ++;
  }
}

double kruskal(vector<int> x,vector<int> y){
  vector<pair<double,pii> > edges;
  for(int i=0;i<x.size();i++){
    for(int j=i+1;j<x.size();j++){
      double dist = getDist(x[i],x[j],y[i],y[j]);
      edges.pb(mp(dist,mp(i,j)));
      //edges.pb(mp(dist,mp(j,i)));
    }
  }
  sort(edges.begin(),edges.end());
  struct subset sub[x.size()];
  for(int i=0;i<x.size();i++){
    sub[i].parent = i;
    sub[i].rank = 0;
  }
  int e = 0 ;
  double result = 0.0;
  while(true){
    bool found = false;
    for(int i=0;i<edges.size();i++){
      int xi = edges[i].second.first;
      int yi = edges[i].second.second;
      int xiroot = find(sub,xi);
       cout<<"h"<<endl;
      int yiroot = find(sub,yi);
      if(xiroot!=yiroot){
	result += edges[i].first;
	found = true;
	union1(sub,xiroot,yiroot);
      }
    }
    if(!found){
      break;
    }
  }
  return result;
}

int find(int v,vector<vertex> &vertices){
  if(v!=vertices[v].parent){
    vertices[v].parent = find(vertices[v].parent,vertices);
  }
  return vertices[v].parent;
}

void union1(int u,int v, vector<vertex> &vertices){
  int uroot = find(u,vertices);
  int vroot = find(v,vertices);
  if(uroot!=vroot){
    if(vertices[uroot].rank > vertices[vroot].rank){
      vertices[v].parent = u;
    }else{
      vertices[u].parent= v;
      if(vertices[u].rank == vertices[v].rank){
	vertices[v].rank ++;
      }
    }
  }
}

bool cmp(edge a, edge b){
  return a.weight < b.weight;
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  vector<vertex> vertices;
  vector<edge> edges;
  for(int i=0;i<x.size();i++){
    vertices.push_back(vertex(x[i],y[i],i,0));
  }
  for(int i=0;i<vertices.size()-1;i++){
    for(int j=i+1;j<vertices.size();j++){
      double wt = findDistance(vertices[i],vertices[j]);
      edges.push_back(edge(i,j,wt));
    }
  }
  sort(edges.begin(),edges.end(),cmp);
  cout<<"h"<<endl;
  for(int i=0;i<edges.size();i++){
    int x = edges[i].x;
    int y = edges[i].y;
    if(find(x,vertices)!=find(y,vertices)){
      result += edges[i].weight;
      union1(x,y,vertices);
    }
  }

  
  //result = kruskal(x,y);
  //write your code here
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
