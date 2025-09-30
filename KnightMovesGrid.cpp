#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> dis;

vector<pair<int,int>> children(int i, int j){
    vector<pair<int,int>> ans;
    vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2}, dy = {-1,1,-2,2,-2,2,-1,1};
    for(int d=0; d<8; d++){
        if(i+dx[d]>-1 && i+dx[d]<n && j+dy[d]>-1 && j+dy[d]<n){
            ans.push_back({i+dx[d], j+dy[d]});
        }
    }
    return ans;
}

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    dis[si][sj]=0;

    while(!q.empty()){
        auto node = q.front();
        q.pop();
        for(auto child: children(node.first, node.second)){
            if(dis[child.first][child.second]==-1){
                q.push(child);
                dis[child.first][child.second]=dis[node.first][node.second]+1;
            }
        }
    }
}

int main(){
   cin>>n;
   dis.assign(n, vector<int>(n, -1));
   //src node = (0,0)
//    if(n==1){
//     cout<<0;
//     return 0;
//    } 
//    else if(n==2){
//     for(int i=0; i<2; i++){
//         for(int j=0; j<2; j++){
//             cout<<0<<" ";
//         }
//         cout<<"\n";
//     }
//     return 0;
//    }
   bfs(0,0);
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) cout<<dis[i][j]<<" ";
    cout<<"\n";
   }
}