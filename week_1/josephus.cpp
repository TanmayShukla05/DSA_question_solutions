#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int pos = 0;                 // survivor when n = 1
    for (int i = 2; i <= n; i++) {
        pos = (pos + k) % i;     // shift due to eliminating k-th person
    }
    return pos;                  // 0-indexed survivor
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;   // use +1 if you want 1-indexed
}