#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pb push_back
#define fs first
#define sc second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define MOD1 4294967296 //2^32

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

bool comparison(const pair<int,int> &a,const pair<int,int> &b){ 
    return a.second<b.second; 
} 

void solve()
{
    ll x,y;
    cin >> x >> y;
    string s;

    cin >> s;
    ll cntu=0,cntd=0,cntl=0,cntr=0;
    for(auto i:s){
        if(i=='U'){
            cntu++;
        }
        else if(i=='D'){
            cntd++;
        }
        else if(i=='R'){
            cntr++;
        }
        else{
            cntl++;
        }
    }
    bool ans = true;
    if((x<0 and cntl<abs(x)) or (x>0 and cntr<abs(x)) or (y<0 and cntd<abs(y)) or (y>0 and cntu<abs(y))){
        ans = false;
    }
    if(ans)cout << "YES";
    else cout << "NO";
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