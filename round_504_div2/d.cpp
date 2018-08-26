#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<map>
#include<stack>
using namespace std;
const int MAX = 200010;

int n, q;
int a[MAX] = {0};
vector<int> c;
map<int, int> m1, m2;
stack<int> s;

int main() {

    freopen("in.txt", "r", stdin);

    scanf("%d%d", &n, &q);
    int n_zero = 0, n_max = 0, i_frist_zero = 0;
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            n_zero ++;
            if (i_frist_zero == 0)
                i_frist_zero = i;
        }
        if (a[i] == q) n_max ++;
    }
    if (n_max == 0 && n_zero == 0) {
        printf("NO\n");
        return 0;
    }
    if (n_zero > 0) {
        if (n_zero == n) {
            printf("YES\n");
            for (int i = 1; i <= n; ++ i)
                printf("%d ", q);
            printf("\n");
            return 0;
        }
        if (n_max == 0) {
            a[i_frist_zero] = q;
        }
        for (int i = 1; i <= n; ++ i)
            if (a[i] == 0)
                a[i] = a[i-1];
        for (int i = n-1; i >= 1; -- i)
            if (a[i] == 0)
                a[i] = a[i+1];
    }

    for(int i = 1; i <= n; ++ i) {
        if (a[i] != a[i-1]) {
            c.push_back(a[i]);
        }
    }

    for (int i = 0; i < c.size(); ++ i) {
        if (m1.find(c[i]) == m1.end()) {
            m1[c[i]] = 1;
            m2[c[i]] = 0;
        } else {
            m1[c[i]] ++;
        }
    }

    bool is_ok = true;
    for (int i = 0; i < c.size(); ++ i) {
        //cout << c[i] << endl;
        if (s.empty()) {
            if (m1[c[i]] == 1) continue;
            s.push(c[i]);
            m2[c[i]] ++;
        } else {
            m2[c[i]] ++;
            //cout << c[i] << " " << m2[c[i]] << " " << s.top() << " " << s.size() << endl;
            if (c[i] < s.top()) {
                is_ok = false;
                break;
            }
            if (m1[c[i]] == 1) continue;
            if (m2[c[i]] == 1) {
                s.push(c[i]);
                continue;
            }
            else {
                if (c[i] != s.top()) {
                    is_ok = false;
                    break;
                } else if (m2[c[i]] == m1[c[i]]) {
                    s.pop();
                }
            }
        }
    }

    if (is_ok) {
        printf("YES\n");
        for (int i = 1; i <= n; ++ i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }

    return 0;
}