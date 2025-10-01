#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

void init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main()
{
    init();

    ll X, K, D;
    cin >> X >> K >> D;

    X = abs(X);

    if (X / D > K)
    {
        cout << X - D * K << endl;

        return 0;
    }

    ll count = X / D;
    ll rest_count = K - count;
    ll distance = X - D * count;

    if (rest_count % 2 == 0)
    {
        cout << distance << endl;
    }
    else
    {
        cout << abs(distance - D) << endl;
    }

    return 0;
}
