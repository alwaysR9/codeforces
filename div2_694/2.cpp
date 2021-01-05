#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int NUM = 100010;
int ori[NUM];
int cur[NUM];

long long work(int n, int x) {
    long long sum = 0;
    for (int i = 0; i < n; ++ i) {
        sum += ori[i];
    }

    bool is_over = false;
    for (int t = 0; ; ++ t) {
        for (int i = 0; i < n; ++ i) {
            if (cur[i] % x != 0) {
                is_over = true;
                break;
            }
            cur[i] = cur[i] / x;
            sum += ori[i];
        }
        if (is_over)
            break;
    }
    return sum;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int T;
    cin >> T;
    while (T --) {
        int n, x;
        cin >> n >> x;

        for (int i = 0; i < n; ++ i) {
            cin >> ori[i];
            cur[i] = ori[i];
        }

        cout << work(n, x) << endl;
    }

    return 0;
}
