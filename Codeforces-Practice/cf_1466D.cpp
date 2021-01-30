#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pb push_back
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD1 1000000007
#define MOD 4294967296 //2^32

bool isprime(int n){
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
vi SieveOfEratosthenes(int n){
    bool prime[n+1];
    vi v;
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            for(int i=p*p;i<=n;i+=p) prime[i] = false;
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) v.pb(i);
    }
    return v;
}


void solve()
{
    int n,a,b;
    cin >> n;
    ll weight[n+1];
    ll  total = 0;
    loop(i,1,n+1){
        cin >> weight[i];
        total += weight[i];
    }
    priority_queue<int> q;
    bool visited[n+1]={false};
    loop(i,0,n-1){
        cin >> a >> b;
        if(visited[a]){
            q.push(weight[a]);
        }
        visited[a] = true;
        if(visited[b]){
            q.push(weight[b]);
        }
        visited[b] = true;
    }
    cout << total;
    while(!q.empty()){
        total += q.top();
        cout << " " << total ;
        q.pop();
    }
    
}
int T;
int32_t main()
{
    FIO;
    //T=1;
    cin >> T;
    //int total=T;
    while(T--){
        //cout << "Case #" << total-T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}