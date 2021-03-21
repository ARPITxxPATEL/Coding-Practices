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
    int r,c;
    cin >> r >> c;
    int a[r][c];
    loop(i,0,r){
        loop(j,0,c){
            cin >> a[i][j];
        }
    }

    pii row[r][c];
    pii col[r][c];

    loop(i,0,r){
        loop(j,0,c){
            row[i][j].fs = 0;
            row[i][j].sc = 0;
            col[i][j].fs = 0;
            col[i][j].sc = 0;
        }
    }


    loop(i,0,r){    // row 
        loop(j,0,c){
            if(j==0){
                row[i][j].first = a[i][j];
            }
            else if(a[i][j]==0){
                row[i][j].first = 0;
            }
            else{
                row[i][j].first = row[i][j-1].fs + 1;
            }
        }
        loopr(j,c-1,0){
            if(j==c-1){
                row[i][j].second  = a[i][j];
            }
            else if(a[i][j]==0){
                row[i][j].second = 0;
            }
            else{
                row[i][j].second = row[i][j+1].sc + 1;
            }
        }
    }
    loop(j,0,c){    // col
        loop(i,0,r){
            if(i==0){
                col[i][j].first = a[i][j];
            }
            else if(a[i][j]==0){
                col[i][j].first = 0;
            }
            else{
                col[i][j].first = col[i-1][j].fs + 1;
            }
        }
        loopr(i,r-1,0){
            if(i==r-1){
                col[i][j].second  = a[i][j];
            }
            else if(a[i][j]==0){
                col[i][j].second = 0;
            }
            else{
                col[i][j].second = col[i+1][j].sc + 1;
            }
        }
    }
    ll ans = 0;

    // loop(i,0,r){
    //     loop(j,0,c){
    //         cout << row[i][j].first << " " << row[i][j].second << "\t";
    //     }
    //     cout << "\n";
    // }

    loop(i,0,r){
        loop(j,0,c){
            if(a[i][j]==0)continue;

            int minrf = min(row[i][j].fs,col[i][j].fs);
            int maxrf = max(row[i][j].fs,col[i][j].fs);

            ans += max(0,min(maxrf/2,minrf)-1);
            ans += max(0,minrf/2-1);

            minrf = min(row[i][j].fs,col[i][j].sc);
            maxrf = max(row[i][j].fs,col[i][j].sc);

            ans += max(0,min(maxrf/2,minrf)-1);
            ans += max(0,minrf/2-1);

            minrf = min(row[i][j].sc,col[i][j].fs);
            maxrf = max(row[i][j].sc,col[i][j].fs);

            ans += max(0,min(maxrf/2,minrf)-1);
            ans += max(0,minrf/2-1);

            minrf = min(row[i][j].sc,col[i][j].sc);
            maxrf = max(row[i][j].sc,col[i][j].sc);

            ans += max(0,min(maxrf/2,minrf)-1);
            ans += max(0,minrf/2-1);
        }
    }
    cout << ans;
}

int TESTCASES=1;
int32_t main()
{
    FIO;

    cin >> TESTCASES;
    int total=TESTCASES;
    while(TESTCASES--){
        cout << "Case #" << total-TESTCASES << ": ";
        solvetestcases();
        cout << "\n";
    }
    return 0;
}