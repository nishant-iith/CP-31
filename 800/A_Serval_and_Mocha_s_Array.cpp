#include<bits/stdc++.h>
using namespace std;

//type names
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

// macros
#define pb push_back
#define all(x) (x).begin(),(x).end()

#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=a-1; i>=b; i--)

class Helper {
    protected:
        vi arrayInput(){
            int n;
            cin>>n;
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }
        
        vi arrayInput(int n){
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }

        string stringInput(){
            string s;
            cin>>s;
            return s;
        }

        void printArray(const vi &arr){
            for(int i=0; i<arr.size(); i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            long long n; // Length of the array
            cin >> n;
            vector<long long> a(n); // Array to store the elements
            for (int i = 0; i < n; i++) // Loop to input elements into the array
                cin >> a[i];
            // Inputs are now stored in array 'a'

            int flag = 0; // Flag to check if a beautiful array can be formed
            for (int i = 0; i < n; i++) // Loop through each element
            {
                for (int j = i + 1; j < n; j++) // Loop to check pairs of elements
                {
                    // Check if the gcd of any pair of elements is less than or equal to 2
                    if (__gcd(a[i], a[j]) <= 2) // gcd calculation
                    {
                        flag = 1; // Set flag to 1 if condition is met
                    }
                }
            }

            // If no such pair is found, flag remains 0
            // If flag is 0, print "NO", else print "YES"
            if (flag == 0)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
};

int main(){
    // fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}