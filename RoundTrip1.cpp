#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> graph;
vector<int> color;
vector<int> par;
bool cycle=false;
vector<int> path;

void dfs(int node, int parent){
    par[node]=parent;
    color[node]=2;
    for(auto child:graph[node]){
        if(color[child]==1){
            dfs(child, node);
        }
        else if(color[child]==2 && child!=par[node]){
            if(cycle==false){
                int temp=node;
                path.push_back(child);
                while(temp!=child){
                    path.push_back(temp);
                    temp = par[temp];
                }
                path.push_back(temp);
            }
            cycle=true;
        }
    }
    color[node]=3;
}

int main(){
    
    cin>>n>>m;
    graph.resize(n+1);
    color.assign(n+1, 1);
    par.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<n+1; i++){
        if(cycle==false && color[i]==1){
            dfs(i, 0);
        }
    }

    if(cycle==false) cout<<"IMPOSSIBLE";
    else{
        cout<<path.size()<<"\n";
        for(int i=0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }
    }
}