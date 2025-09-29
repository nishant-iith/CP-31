#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    vector<ll> pref(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    ll total_sum = pref[2 * n];
    int max_j = n;
    vector<ll> odd_pref(max_j + 1, 0);
    vector<ll> even_pref(max_j + 1, 0);
    for (int j = 1; j <= max_j; j++) {
        if (2 * j - 1 <= 2 * n) {
            odd_pref[j] = odd_pref[j - 1] + a[2 * j - 1];
        }
        if (2 * j <= 2 * n) {
            even_pref[j] = even_pref[j - 1] + a[2 * j];
        }
    }
    vector<ll> answers;
    for (int k = 1; k <= n; k++) {
        int m = n - k;
        int s = k + 1;
        ll osc_sum = 0;
        if (m > 0) {
            int j_start, j_end;
            j_end = 0; // to avoid warning
            if (s % 2 == 1) {
                j_start = (s + 1) / 2;
                j_end = j_start + m - 1;
                osc_sum = odd_pref[j_end] - odd_pref[j_start - 1];
            } else {
                j_start = s / 2;
                j_end = j_start + m - 1;
                osc_sum = even_pref[j_end] - even_pref[j_start - 1];
            }
        }
        ll last_sum = pref[2 * n] - pref[n + m];
        ll sum_exits = osc_sum + last_sum;
        ll stay = 2LL * sum_exits - total_sum;
        answers.push_back(stay);
    }
    for (size_t i = 0; i < answers.size(); i++) {
        cout << answers[i];
        if (i + 1 < answers.size()) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        solve();
    }
    return 0;
}