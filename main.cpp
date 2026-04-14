#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<long long>a(n+2,1);
    for(int i=1;i<=n;i++){ long long x; cin>>x; a[i]=x; }
    // dp[l][r]: max value for interval [l,r]
    int N=n+2;
    // Flattened 2D array to improve locality
    vector<long long> dp(N*N, 0);
    auto at = [&](int l,int r)->long long&{ return dp[l*N + r]; };
    for(int len=1; len<=n; ++len){
        for(int l=1; l+len-1<=n; ++l){
            int r=l+len-1;
            long long best=0;
            // try bursting k last in [l,r]
            // gain = a[l-1]*a[k]*a[r+1]
            long long left_mul = a[l-1];
            long long right_mul = a[r+1];
            for(int k=l; k<=r; ++k){
                long long cand = at(l,k-1) + at(k+1,r) + left_mul * a[k] * right_mul;
                if(cand>best) best=cand;
            }
            at(l,r)=best;
        }
    }
    cout<<at(1,n)<<"\n";
    return 0;
}
