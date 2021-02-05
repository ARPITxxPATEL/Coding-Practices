#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pb push_back
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
    ll n,k;
    cin >> n >> k;
    ll a[n];
    loop(i,0,n){
        cin >> a[i];
    }
    if(n==1){
        cout << -1;
        return;
    }
    ll total = 0;
    ll mx = a[n-1];
    for(int i=n-2;i>=0;i--){
        if(mx>a[i]){
            total += mx-a[i];
        }
        else{
            mx = a[i];
        }
    }
    if(total<k){
        cout << -1;
        return;
    }
    int pos = 0;
    while(k>0){
        int i=0;
        while(i<n-1 and a[i]>=a[i+1]){
            i++;
        }
        a[i]++;
        pos = i;
        k--;
    }
    cout << pos+1;
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