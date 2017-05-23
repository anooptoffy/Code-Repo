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
	long long int T, N , S, Arr[1000];
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	long long int i, c,cc;
	long long int flag = 1;
	while(T-- > 0) {
		memset(Arr, 0, sizeof(long long int)*1000);
	    cin >> N;
	    if(N%2 == 0){
	    	cout << "no" << endl;
	    	for (i = 0; i < N; ++i)
	    	{
	    		cin >> S;
	    	}
	    	continue;
	    }
	    flag = 1;
	    c = 1;
	    for (i = 0; i < N/2; ++i)
	    {
	    	cin >> S;
	    	Arr[i] = S;	    	
	    	if(c != Arr[i]){
	    		
	    		flag = 0;
	    		//break;
	    	}
	    	c++;
	    }
	    if (flag == 0)
	    {
	    	cout << "no" << endl;
	    	cin >> S;
	    	for (i = 0; i < N/2; ++i)
	    	{
	    		cin >> S;
	    	}
	    	continue;

	    }

	    cin >> S;
	    flag = 1;
	    cc = 0;
	    for (i = 0; i < N/2; ++i)
	    {
	    	cin >> S;
	    	if(Arr[((N/2) - 1) - cc] != S){
	    		//cout << "Number1 " << Arr[((N/2) - 1) - cc]  << "Number2" << S << endl;
	    		
	    		flag = 0;
	    		//break;
	    	}
	    	cc++;
	    }
	    if (flag == 1)
	    {
	    	cout << "yes" << endl;
	    }
	    else{
	    	cout << "no" << endl;
	    }
	}
	return 0;
}