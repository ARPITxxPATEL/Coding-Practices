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
    ll A,B,n;
    cin >> A >> B >> n;
    vector<pair<int,int>> inp;
    ll a[n],b[n];
    loop(i,0,n) cin >> a[i];
    loop(i,0,n) cin >> b[i];
    // loop(i,0,n){
    //     ll temp = b[i]/A;
    //     if(b[i]%A!=0) temp++;
    //     inp.pb({temp*a[i],i});
    // }
    // sort(inp.begin(),inp.end(), comparison);

    // bool check = false;
    // int it;
    // for(it = 0;it<n;it++){
    //     B -= inp[it].first;
    //     if(B<=0){
    //         check = true;
    //         break;
    //     }
    // }
    // if(check and it!=n-1) cout  << "NO";
    // else cout << "YES";
    loop(i,0,n){
        inp.pb({b[i],a[i]});
    }
    bool check = false;
    sort(inp.begin(),inp.end(), comparison);
    loop(i,0,n){
        if(ceil(inp[i].fs/float(A))>ceil(float(B)/inp[i].sc)){
            check = true;
            break;
        }
        B -= inp[i].sc*ceil(inp[i].fs/float(A));
    }
    if(check)cout << "NO";
    else cout << "YES";
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