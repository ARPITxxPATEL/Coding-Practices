#include <bits/stdc++.h>
using namespace std;

#define int long long int
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
    int arr[n]={0};
    int pos = -1;

    bool clock = false;
    bool anti = false;
    for(int i=0;i<n;i++){
        if(s[i]=='>'){
            clock = true;
        }else if(s[i]=='<'){
            anti = true;
            if (pos==-1)
                pos = i;
        }
    }
    if (clock==false or anti==false){
        cout << n;
    }
    else{
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[(pos+i+1)%n]=='-'){
                cnt++;
            }
            else {
                if(cnt!=0)
                    ans += cnt+1;
                cnt = 0;
            }
        }
        cout << ans;
    }
}
int T;
int32_t main()
{
    FIO;
    //T=1;
    cin >> T;
    while(T--){
        solve();
        cout << "\n";
    }
    return 0;
}