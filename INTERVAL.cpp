#include <bits/stdc++.h>
#define N 300005
using namespace std;
typedef long long ll;
const long long oo = (ll)1e18;
int t, n, m;
ll f[N];
ll Tmp[N];
int b[202];
ll sum[N];

int front;
int top;

int nx[N];

void add(int pos) {
    while (top > front && Tmp[pos] > Tmp[nx[top]] ) top--;
    top++;
    nx[top] = pos;
}

void del(int pos) {
    while (front < top && nx[front + 1] <= pos) front++;
}

ll getmax() {
    return Tmp[nx[front + 1]];
}

ll getSum(int l, int r) {
    return sum[r] - sum[l - 1];
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            sum[i] = sum[i - 1] + x;
        }

        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);

        for (int i = 1; i <= n - b[m] + 1; i++) {
            f[i] = getSum(i, i + b[m] - 1);
        }

        for (int i = m - 1; i >= 1; i--) {
            int len = n - b[i + 1] + 1;
            for (int j = 1; j <= len; j++) {
                    Tmp[j] = f[j];
              //      cout << Tmp[j] << " ";
            }

            front = 0;
            top = 0;

            int st = 2;
            int fn = b[i] - b[i + 1] - 1;

            for (int j = st; j <= fn; j++) {
                add(j);
            }

            int cur = fn;
            for (int j = 1; j <= n - b[i] + 1; j++) {
                cur++;
                add(cur);
                f[j] = getSum(j, j + b[i] - 1) - getmax();
                del(j + 1);
            }
        }

        ll ret = -oo;
        for (int i = 1; i <= n - b[1] + 1; i++)
            ret = max(ret, f[i]);

        printf("%lld\n", ret);
    }
    return 0;
}

