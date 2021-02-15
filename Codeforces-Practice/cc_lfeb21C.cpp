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
    int n;
    cin >> n;
    string s[n],temp;
    map<string,vector<char>> m;
    unordered_set<string> funny;
    loop(i,0,n){
        cin >> s[i];
        temp = s[i].substr(1);
        m[temp].push_back(s[i][0]);
        funny.insert(temp);
    }

    int cnt = 0;

    for(auto i:funny){
        for(auto j:funny){
            unordered_set<char> possible;
            for(auto k:m[j]) possible.insert(k);
            for(auto k:m[i]) possible.insert(k);
            cnt += (possible.size()-m[i].size())*(possible.size()-m[j].size());
        }
    }
    cout << cnt;
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