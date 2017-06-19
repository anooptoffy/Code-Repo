#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define E 2.7182818284



const ll mod = 2e18;
const int N = 3e5;

int main(int argc, char const *argv[])
{
	// For handling large inputs.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned ll int N, sum = 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N;
	for(unsigned ll int i = 1; i <= N; i++){
	    sum += floor(i * E);
	}

	cout << sum << endl;	
	
	return 0;
}