#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class graph{
    int v;
    vector<int> *arr;
    bool *visited;
    
public:
    graph(int v){
        this->v = v;
        arr = new vector<int>[v+1];
    }
    void addedge(int a,int b){
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    void print(){
        for(int i=0; i<=v ; i++){
            cout << i << "->";
            for(auto j:arr[i]){
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    void bfs(int s){
        visited = new bool[v+1];
        for (int i=0; i<=v ; i++){
            visited[i] = false;
        }
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(auto j:arr[u]){
                if(!visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        delete visited;
    }
    void dfs(int s){
        visited = new bool[v+1];
        for(int i=0; i<=v ; i++){
            visited[i] = false;
        }
        dfsrec(s);
    }
    void dfsrec(int s){
        visited[s] = true;
        cout << s << " ";
        for(auto i:arr[s]){
            if (!visited[i])
                dfsrec(i);
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    graph g(n);
    int e;
    cin >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        g.addedge(a,b);
    }
    g.print();
    g.bfs(4);
    cout << "\n";
    g.dfs(0);
}

int main() 
{
    FIO;
    solve();
    return 0;
}