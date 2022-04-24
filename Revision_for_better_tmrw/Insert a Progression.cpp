//  https://codeforces.com/contest/1671/problem/D

// if we want to draw the given array as graph it will be like:

// \           /
//  .        .
//   \      /
//    .    . 
//      \ /
  
//   placeing 1 at min(a) inc score by +2*(min(a)-1)
//   https://pasteboard.co/XAE6iM4swqBV.png
 

// corner case to place one at border.
//  https://pasteboard.co/12EP35nZPgcx.png

// https://www.youtube.com/watch?v=NM48iKlZxZI&t=1178s

bool solve()
{
    ll n,x;
    cin >> n >> x;
    vector<ll> v(n);
 
    for(ll i=0 ; i<n ; ++i) cin >> v[i];
 
    ll minm = *min_element(v.begin(),v.end());
    ll maxm = *max_element(v.begin(),v.end());
 
    ll ans = 0; 
 
    for(ll i=1 ; i<n ; ++i){
        ans += abs(v[i]-v[i-1]);
    }
    
    ll minm_add = 0, maxm_add = 0;
    if(1<minm){
        minm_add = min({2*(minm-1),v[0]-1,v[n-1]-1});
    }
 
    if(x>maxm){
        maxm_add = min({2*(x-maxm),x-v[0],x-v[n-1]});
    }
 
    cout << ans+minm_add+maxm_add << endl;
    return true;    
}
