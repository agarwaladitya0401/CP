// https://www.codechef.com/problems/BEAUSUB

if we are on ith ind the we calculate the nearest nxt ind that has same val as a[i]. 
  then applied dp
  dp[i][j] what is the maximum length subseq if we count a[i] in our seq when we can take at most j diff adj. elemnets.
  
  while updating ans for ith index we have ans of all previous index for all values of j, therfore we have 2 choices
  1. if we go to next same no. a[i] at index nxt[i]
  2. or we add this no. next to the seq which has max length with at most j-1 diff indexes allowed.
    take max of both choices.
    
  #include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define f(i,n) for(int i=0;i<n;i++) 
#define F first 
#define S second 
#define pb push_back 

using namespace std;

ll cache[1001][1001];

ll n;

ll a[1001];
ll p[1001]; // for each i stores index of next equal 

// dp[i][k] = max(dp[p[i]][k]) , max(i+1..n , k-1) + 1;


ll dp[1001][1001]; 

void test(){
	ll k;
	cin>>n>>k;
	
	
	ll a[n];
	f(i,n)cin>>a[i];
	
	memset(dp,0,sizeof(dp));
	
	f(i,n){
		p[i] = n;
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				p[i] = min(p[i] ,(ll)j);
			}
		}		
	}
	
	ll pq[k+1];
	f(i,k+1)pq[i] = 0;
	
	for(int i=n-1;i>=0;i--){
		ll temp[k+1];
		for(int j=0;j<=k;j++)
			temp[j] = pq[j];
		for(int j=0;j<=k;j++) {
			dp[i][j] = dp[p[i]][j];
			if(j>0){
				dp[i][j] = max(dp[i][j],temp[j-1]);
			}
			dp[i][j]++;
			pq[j] = max(pq[j],dp[i][j]);
			// cout<<dp[i][j]<<" ";
		}
		// cout<<"\n";
	}
	
	ll res = 1;
	f(i,k+1)res = max(res, pq[i]);
	
	cout<<res<<"\n";
	
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests=1;
	cin>>tests;
	while(tests--){
		test();
	}
}
