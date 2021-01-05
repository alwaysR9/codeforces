#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int NUM = 300010;
int k[NUM];
int c[NUM];

long long work(int n, int m) {
    sort(k, k+n, [](int a, int b) {
        return a > b;
    });

    long long res = 0;
    int min_c = 1;
    for (int i = 0; i < n; ++ i) {
        if (min_c <= k[i]) {
            res += c[min_c-1];
            min_c ++;
        } else {
            res += c[k[i]-1];
        }
    }
    return res;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &k[i]);
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d", &c[i]);
        }

        cout << work(n, m) << endl;
    }

    return 0;
}
