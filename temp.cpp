#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a + b > n) {
            cout << "NO" << endl;
        } else if (a + b == 0) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else if (a + b == 1) {
            cout << "NO" << endl;
        } else if (a == 0 || b == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            int z = n - a - b;
            for (int i = 1; i <= z; i++) {
                cout << i << " ";
            }
            for (int i = z + 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
            for (int i = 1; i <= z; i++) {
                cout << i << " ";
            }
            for (int i = z + 1 + a; i <= n; i++) {
                cout << i << " ";
            }
            for (int i = z + 1; i < z + 1 + a; i++) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}