/*Given N integers . we have to find a subsequence of k integers such that the "hustle" is minimum.
Here hustle is sum of pairwise diff divided by num of pairs. true*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
int main()
{
    int n, k; cin>> n >> k;
    vll a(n+1);
    for(int i =1; i <= n; i++) cin>> a[i];
    int l = 1, r = 2;
    int st, en;
    // to get the minimum sum of pair-wise diff we are sorting the vector
    sort(a.begin(), a.end()); // reducing the problem from subsequence to contiguous subarray
    int cum[n+1];
    cum[0] = 0;
    for(int i = 1; i <= n; i++){
        cum[i] = cum[i-1] + a[i];
    }
    ll sum = 0;
    while(r <= k){
        sum += (a[r] * (r-l)) - (cum[r-1]- cum[l-1]);
        r++;
    }
    ll ans = sum;
    st = l, en = r -1;
    while(r <= n){
//      sum -= (a[l]*(r - 1- l)) - (cum[r-1] - cum[l]);
        sum -= (cum[r-1] - cum[l] - a[l]*(r-1-l));
        l++;
        sum += (a[r]* (r-l)) - (cum[r-1] - cum[l-1]);
        if(sum < ans){
            ans = sum;
            st = l;
            en = r;
        }
        r++;
    }

}
