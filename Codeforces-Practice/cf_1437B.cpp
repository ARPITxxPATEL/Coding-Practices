#include <bits/stdc++.h>
using namespace std;

#define int  long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pb push_back
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0=0,cnt1=0;
    for(int i=0;i<n;i++){
        int k = i+1;
        while(k<n and s[k]==s[i]){
            if(s[k]=='1')cnt1++;
            else cnt0++;
            k++;
        }
        i = k-1;
    }
    cout << max(cnt0,cnt1);
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