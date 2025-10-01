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

    ll N, A, B;
    cin >> N >> A >> B;

    if ((B - A) % 2 == 0)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Borys" << endl;
    }

    return 0;
}
