#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

long long upper_div(long long a, int x) {
    if (a % x == 0)
        return a / x;
    return a / x + 1;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int T;
    cin >> T;
    while (T --) {
        int n, x;
        cin >> n >> x;
        long long sum = 0;
        long long _max = 0;
        for (int i = 0; i < n; ++ i) {
            int a;
            cin >> a;
            _max += upper_div(a, x);
            sum += a;
        }
        long long _min = upper_div(sum, x);
        cout << _min << " " << _max << endl;
    }

    return 0;
}
