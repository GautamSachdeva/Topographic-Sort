#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
using std::vector;
using std::pair;

void recur_sort(vector<vector<int> > &adj,vector<bool> &visited,vector<int> &ans,int vertex){
	visited[vertex] = true;
	for(int i = 0 ; i < adj[vertex].size() ; i++){
		if(!visited[adj[vertex][i]]){
			recur_sort(adj,visited,ans,adj[vertex][i]);	
		}
	}
	ans.push_back(vertex);
}






vector<int> toposort(vector<vector<int> > adj) {
  //write your code here
  vector<int> ans;
  vector<bool> visited(adj.size(),false);
  for(int i = 0 ; i < adj.size() ; i++){
  	if(!visited[i])
  		recur_sort(adj,visited,ans,i);
  }
  return ans;
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
  vector<int> order = toposort(adj);
  reverse(order.begin(),order.end());
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
