
#include <vector>
#include <iostream>
using namespace std;

bool accepting = true;

void test_case() {
    int n;
    cin >> n;
    if (n == 0) {
        accepting = false;
        return;
    }
    
    vector<int> nums(2 * n + 1), pref(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        nums[i + n] = nums[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        pref[i] = pref[i - 1] + nums[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int total = pref[i + i - 1] - pref[i - 1];
        if (total >= 0) {
            ans++;
        }
    }
    
    cout << ans << endl;
}

int main() {
    while (accepting) {
        test_case();
    }
}
