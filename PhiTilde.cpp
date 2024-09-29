#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

const int MAXN = 1000;

int n;
int cnt;
int ans[MAXN + 5];
vector<int> e, tmp;
vector< vector<int> > ve;
map< vector<int>, int> mp;

bool cmp(vector<int> a, vector<int> b)
{
    for (int i = 0; i < n; ++ i)
    {
        if (a[i] != b[i]) return (a[i] < b[i]);
    }
    return true;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++ i)
    {
        int x;
        cin >> x;
        e.push_back(x);
    }
    ve.push_back(e);
    mp[e] = ++ cnt;

    while (true)
    {
        tmp = e;
        for (int i = 0; i < n - 1; ++ i)
        {
            tmp[i] = e[0] * e[i + 1];
        }
        if (tmp == ve[0]) break;
        e = tmp;
        ve.push_back(e);
        mp[e] = ++ cnt;
    }

    /*for (auto v : ve)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }/

    sort(ve.begin(), ve.end(), cmp);

    for (int i = 0; i < ve.size(); ++ i)
    {
        ans[mp[ve[i]]] = i + 1;
    }

    for (int i = 1; i <= ve.size(); ++ i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
