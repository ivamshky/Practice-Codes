#include <iostream>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <set>
#include <vector>


using namespace std;
const int Nmax = 100100;

vector<int> primes;
int lp[Nmax * 10], A[Nmax];
set<int> actualPositions;
int N, M;

struct SegmentTree {
       int l,r;
       int value;
       SegmentTree *left, *right;
       SegmentTree(){};
       SegmentTree(SegmentTree *_left, SegmentTree * _right):left(_left), right(_right) {
                               if (!left && !right) return ;
                               l = left -> l;
                               r = right -> r;
                               value = max(left -> value, right -> value);
       }
};

SegmentTree * Build(int l, int r) {
            if (l == r) {
               SegmentTree *tree = new SegmentTree();
               tree -> l = tree -> r = l;
               tree -> left = tree -> right = NULL;
               tree -> value = lp[A[l]];
               return tree;
            }
            int mid = (l + r) >> 1;
            return new SegmentTree(Build(l, mid), Build(mid + 1, r));
}

int getMax(SegmentTree *tree, int l, int r) {
    if (l > r) return 1;
    if (tree -> l == l && tree -> r == r) {
             return tree -> value;
    }
    int mid = (tree -> l + tree -> r) >> 1;
    return max(getMax(tree -> left, l, min(r, mid)),
               getMax(tree -> right, max(mid + 1, l), r));
}

void Update(SegmentTree *tree, int idx) {
     if (tree -> l == tree -> r) {
        A[idx] /= lp[A[idx]];
        tree -> value = lp[A[idx]];
        return ;
     }
     int mid = (tree -> l + tree -> r) >> 1;
     if (idx <= mid)
        Update(tree -> left, idx);
     else
         Update(tree -> right, idx);
     tree -> value = max(tree -> left -> value, tree -> right -> value);
}

void Update(SegmentTree *tree, int l, int r) {
     set<int> :: iterator it = actualPositions.lower_bound(l);
     vector<int> toDelete;
     while (it != actualPositions.end() && *it <= r) {
           Update(tree, *it);
           if (A[*it] == 1)
              toDelete.push_back(*it);
           it ++;
     }
     for (int i = 0; i < toDelete.size(); i ++)
         actualPositions.erase(toDelete[i]);
}

inline void Solve() {
       scanf("%d %d", &N, &M);
       assert(1 <= N && N <= 100000);
       assert(1 <= M && M <= 100000);

       actualPositions.clear();
       for (int i = 1; i <= N; i ++) {
           scanf("%d", &A[i]);
           assert(1 <= A[i] && A[i] <= 1000000);
           if (A[i] > 1)
              actualPositions.insert(i);
       }
       SegmentTree *tree = Build(1,N);
       for (int it = 1; it <= M; it ++) {
           int type, l, r;
           scanf("%d %d %d", &type, &l, &r);
           assert(type == 0 || type == 1);
           assert(1 <= l && l <= r && r <= N);
           if (type == 0) {
                 Update(tree, l, r);
           }
           else {
                printf("%d ", getMax(tree, l, r));
           }
       }
       printf("\n");
}

int main() {
    lp[1] = 1;
    for (int i = 2; i < 10 * Nmax; i ++ ){
        if (lp[i] == 0) {
           primes.push_back(i);
           lp[i] = i;
        }
        for (int j = 0; j < primes.size() && primes[j] <= lp[i] && i * 1ll * primes[j] < 10 * Nmax; j ++) {
            lp[primes[j] * i] = primes[j];
        }
    }

    int T;
    scanf("%d",&T);
    assert(1 <= T && T <= 100);
    while (T --> 0) {
          Solve();
    }

    return 0;
}
