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

ll int Arr[100005];


bool isPrime(ll int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (ll int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

ll int  F(ll int L,ll int  R,ll int  X,ll int  Y) {

     ll int result = 0;
     for( ll int i = X ; i <= Y; i++ )  {
         if( isPrime(i) ) {
             for(ll int j = L ; j <= R ; j++ ) {
                  ll int number = Arr[j];
                  ll int exponent = 0;
                  while( number % i == 0 ) {
                     exponent = exponent + 1 ;
                     number = number/i;
                  }
                  result = result + exponent;
              }
         }
     }
     return result;
}

int main(int argc, char const *argv[])
{
	// For handling large inputs.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, Q, L, R, X, Y;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N;
	for (ll int i = 1; i <= N; ++i)
	{
		cin >> Arr[i];
	}

	cin >> Q;
	while(Q-- > 0) {
		//cout << "Hai" << endl;
	    cin >> L >> R >> X >> Y;
	    cout << F(L, R, X, Y) << endl;
	}
	return 0;
}