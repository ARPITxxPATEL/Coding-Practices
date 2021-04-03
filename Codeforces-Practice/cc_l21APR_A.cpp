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

ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a<b)return gcd(b,a);
    return gcd(b,a%b);
}

bool comparison(const pair<int,int> &a,const pair<int,int> &b){ 
    return a.second<b.second; 
} 


void solvetestcases()
{
    ll n;
    cin >> n;
    ll ans = 0;

    if(n==1){
        cout << 20;
        return;
    }
    else if(n==2){
        cout << 36;
        return;
    }
    else if(n==3){
        cout << 51;
        return;
    }

    ans += (1LL*11*4*(n/4));
    
    if(n%4==0) ans += 16;
    else if(n%4==1) ans += 20+12;
    else if(n%4==2) ans += 18+18+8;
    else ans += 18+18+15+4;

    cout << ans;
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