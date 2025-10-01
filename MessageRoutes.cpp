#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> graph;
vector<int> dis, par;

void bfs(int sc_node){
    dis[sc_node]=1;
    queue<int> q;
    q.push(sc_node);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child:graph[node]){
            if(dis[child]==-1){
                par[child]=node;
                dis[child]=dis[node]+1;
                q.push(child);
            }
        }
    }
}

int main(){
   cin>>n>>m;
   graph.resize(n+1);
   dis.assign(n+1, -1);
   par.resize(n+1);
   for(int i=0; i<m; i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
   }
   bfs(1);
   vector<int> ans;
   if(dis[n]==-1){
    cout<<"IMPOSSIBLE";
   }else{
    cout<<dis[n]<<"\n";
    int temp=n;
    while(temp!=1){
        ans.push_back(temp);
        temp = par[temp];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(int i:ans) cout<<i<<" ";
   }
}