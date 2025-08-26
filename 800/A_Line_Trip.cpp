#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        long long maxDis = 0;
        long long prev = 0, curr = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> curr;
            maxDis = max(maxDis, abs(curr - prev));
            prev = curr;
        }
        maxDis = max(maxDis, (2 * abs(x - prev)));

        cout << maxDis << endl;
    }
}