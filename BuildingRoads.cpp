#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> graph;
vector<int> vis;
vector<int> road;
int ct=0;

void dfs(int node){
    vis[node]=1;
    for(auto child:graph[node]){
        if(!vis[child]) dfs(child);
    }
}

int main(){
   cin>>n>>m;
   graph.resize(n+1);
   vis.assign(n+1, 0);
   for(int i=0; i<m; i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
   }

   for(int i=1; i<n+1; i++){
    if(!vis[i]){
        dfs(i);
        ct++;
        road.push_back(i);
    }
   }

   if(ct-1==0) cout<<0;
   else{
    cout<<ct-1<<"\n";
    for(int i=0; i<road.size()-1; i++){
        cout<<road[i]<<" "<<road[i+1]<<"\n";
    }
   }
}