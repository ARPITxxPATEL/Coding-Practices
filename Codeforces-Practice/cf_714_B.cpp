#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,e,s) for(int i=e;i>=s;i--)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define fs first
#define sc second
#define pb push_back
#define all(vect) (vect.begin(),vect.end())
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007

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

ll fact(int n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans = (ans*i)%MOD;
    }
    return ans;
}


void solvetestcases()
{
    ll n;
    cin >> n;
    ll a[n];
    ll all = INT_MAX;
    //ll cnt0=0;
    loop(i,0,n){
        cin >> a[i];
        all &= a[i];
        //if(a[i]==0)cnt0++;
    }
    ll cnt = 0;
    loop(i,0,n){
        if(all==a[i])cnt++;
    }
    if(cnt<=1){
        cout << 0;
    }
    else if(cnt>=2){
        ll ans = 1;
        ans = 1LL*(fact(n-2))%MOD;
        ans = (ans * cnt)%MOD;
        ans = (ans * (cnt-1))%MOD;
        cout << ans;
    }
}

int TESTCASES=1;
int32_t main()
{
    FIO;

    cin >> TESTCASES;
    //int total=TESTCASES;
    while(TESTCASES--){
        //cout << "Case #" << total-TESTCASES << ": ";
        solvetestcases();
        cout << "\n";
    }
    return 0;
}