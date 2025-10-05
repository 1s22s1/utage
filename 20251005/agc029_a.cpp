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

    string S;
    cin >> S;

    ll white_count = count_if(S.begin(), S.end(), [](char c)
                              { return c == 'W'; });
    vector<ll> black_positons, white_positions;

    rep(i, white_count)
    {
        if (S.at(i) == 'B')
        {
            black_positons.emplace_back(i);
        }
    }

    for (ll i = white_count; i < S.size(); i++)
    {
        if (S.at(i) == 'W')
        {
            white_positions.emplace_back(i);
        }
    }

    ll answer = 0;
    rep(i, white_positions.size())
    {
        answer += (white_positions.at(i) - black_positons.at(i));
    }

    cout << answer << endl;

    return 0;
}
