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

ll n,m,k;

void solvetestcases()
{
    cin >> n >> m >> k;
    ll a[n][m],pre[n][m];
    loop(i,0,n){
        loop(j,0,m){
            cin >> a[i][j];
            pre[i][j] = a[i][j];
        }
    }

    loop(i,0,n){
        loop(j,1,m){
            pre[i][j] += pre[i][j-1];
        }
    }
    loop(i,1,n){
        loop(j,0,m){
            pre[i][j] += pre[i-1][j];
        }
    }

    ll ans = 0;
    //vpii test;

    loop(i,0,n){
        loop(j,0,m){
            int tempi=i,tempj=j;
            while(tempi>=0 && tempj>=0){
                double sum = pre[i][j];
                if(tempi>0)sum -= pre[tempi-1][j];
                if(tempj>0)sum -= pre[i][tempj-1];
                if(tempi>0 && tempj>0)sum += pre[tempi-1][tempj-1];
                double  avg = sum/((i-tempi+1)*(i-tempi+1));
                if(avg>=k){
                    //test.push_back({i,j});
                    ans++;
                }
                else{
                    break;
                }
                tempi--;tempj--;
            }
        }
    }

    // for(auto i:test){
    //     cout << i.fs << " " << i.sc << "\n";
    // }
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