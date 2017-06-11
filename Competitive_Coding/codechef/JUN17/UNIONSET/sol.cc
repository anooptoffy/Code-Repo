#include <bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define ll long long
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vll>		vvl;

const ll mod = 2e18;
const int N = 3e5;

int main(int argc, char const *argv[])
{
	// For handling large inputs.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll T, N, K, count;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	while(T-- > 0) {
	    cin >> N >> K;
	    count = 0;
	    ll int Nlen[1000], NN[1000][1000];
	    for (ll int i = 0; i < N; ++i)
	    {
	    	cin >> Nlen[i];
	    	for (ll int j = 0; j < Nlen[i]; ++j)
	    	{
	    		cin >> NN[i][j];
	    	}
	    }

	    for (ll int i = 0; i < N; ++i)
	    {
	    	set<ll int> mset1;

	    	for (ll int j = 0; j < Nlen[i]; ++j)
	    	{
	    		mset1.insert(NN[i][j]);
	    	}

	    	for (ll int j = 0; j < N; ++j)
	    	{
	    		set<ll int> mset2;
	    		if(i == j)
	    			continue;

	    		for (ll int k = 0; k < Nlen[j]; ++k)
	    		{
	    			mset2.insert(NN[j][k]);
	    		}

	    		mset2.insert(mset1.begin(), mset1.end());
	    		if(mset2.size() == K)
	    			count++;
	    	}
	    }

	    cout << count/2 << endl;
	}
	
	return 0;
}