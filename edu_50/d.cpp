#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int MAX = 3 * 100010;

int a[MAX];
int b[MAX];

int main() {

    freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) scanf("%d", &b[i]);

    int n_equal = 0;
    long long sum1 = 0;
    long long sum2 = 0;

    int k1 = n-1;
    int k2 = m-1;

    bool flag = false;
    while (1) {
        if (k1 == -1 && k2 == -1) {
            if (sum1 == sum2) {
                flag = true;
            } else {
                flag = false;
            }
            break;
        }
        if (k1 == -1) {
            while (k2 >= 0) {
                sum2 += (long long)b[k2--];
            }
            if (sum1 == sum2) {
                flag = true;
                ++ n_equal;
            } else {
                flag = false;
            }
            break;
        }
        if (k2 == -1) {
            while (k1 >= 0) {
                sum1 += (long long)a[k1--];
            }
            if (sum1 == sum2) {
                flag = true;
                ++ n_equal;
            } else {
                flag = false;
            }
            break;
        }
        if (sum1 == 0 && sum2 == 0) {
            sum1 += (long long)a[k1--];
            sum2 += (long long)b[k2--];
        } else if (sum1 > sum2) {
            sum2 += (long long)b[k2--];
        } else {
            sum1 += (long long)a[k1--];
        }
        //cout << sum1 << " " << sum2 << endl;
        if (sum1 == sum2) {
            ++ n_equal;
            sum1 = sum2 = 0;
        }
    }

    if (flag) {
        printf("%d\n", n_equal);
    } else {
        printf("-1\n");
    }

    return 0;
}