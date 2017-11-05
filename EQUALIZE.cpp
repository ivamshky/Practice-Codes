include < bits / stdc++.h >
using namespace std;

int m, n, q, h[1001][1001], k, l, s[1001][1001], cnt = 0;

bool ok(int height) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (h[i][j] >= height);
            //cout<<(h[i][j] >= height)<<endl;
        }
        //cout<<endl;
    }
    for (int i = k; i <= m; i++) {
        for (int j = l; j <= n; j++) {
            int i1 = i - k, j1 = j - l;
            if (s[i][j] - s[i1][j] - s[i][j1] + s[i1][j1] >= k * l / 2 + 1)
                return true;
        }
    }
    return false;
}
int main() {
    //freopen("test01.in", "r", stdin);
    scanf("%d%d%d", & m, & n, & q);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", & h[i][j]);
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= q; i++) {
        cnt = 0;
        scanf("%d%d", & k, & l);
        int left = 0, right = 1e7 + 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (ok(mid))
                left = mid;
            else
                right = mid - 1;

        }
        printf("%d\n", left);
    }
    return 0;
}
