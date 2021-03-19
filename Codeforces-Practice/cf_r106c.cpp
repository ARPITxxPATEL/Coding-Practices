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

void solvetestcases()
{
    int n;
    cin >> n;
    ll c[n];
    loop(i,0,n)cin >> c[i];

    ll min1 = INT_MAX;
    ll min2 = INT_MAX;
    ll ans = 1e18;

    ll now=0;
    ll n1=n,n2=n;

    loop(i,0,n){
        if(i%2==0){
            min1 = min(min1,c[i]);
            now += c[i];
            n1--;
        }
        else{
            min2 = min(min2,c[i]);
            now += c[i];
            n2--;
        }
        ans = min(ans,now+min1*n1+min2*n2);
    }
    
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