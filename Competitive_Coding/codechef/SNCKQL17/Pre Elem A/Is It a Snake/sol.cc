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
	int T, N, Arr[3][1000], visited[3][1000], count, x, y, cc;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	while(T-- > 0) {
		count = 0;
		cin >> N;
		for (int i = 1; i <= 2; ++i)	
		{
			for (int j = 1; j <= N; ++j)
			{
				cin >> Arr[i][j];
				visited[i][j] = 0;
				if (Arr[i][j] == '#')
				{
					count++;
				}
			}
		}

		visited[1][1] = 1;
		
	}

	return 0;
}