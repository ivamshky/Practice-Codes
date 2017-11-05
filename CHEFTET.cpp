#include<bits/stdc++.h>
#define NMAX 11111
int A[NMAX], B[NMAX], N;
void ReadInput(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&B[i]);
    }
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
    }
}

int Solve()
{
    long long sum=0;
    for(int i=1;i<=N;i++) sum += A[i]+B[i];
    if(sum%N != 0) return -1;
    int ans = sum/N;
    int ok = false, ok2 = false;

    for(int i=1;i<=N;i++){
        int x = A[i]+B[i];
        if(i<N) x +=B[i+1];
        if(x==ans){
            A[i] = ans;
            B[i] = B[i+1] = 0;
            continue;
        }
        if(x<ans){
            ok=true;
            return -1;
        }
        if(A[i]+B[i] == ans){
            A[i] = ans;
            B[i] = 0;
            continue;
        }
        if(i<N && A[i]+B[i+1] == ans){
            A[i] = ans;
            B[i+1] = 0;
            A[i+1] +=B[i];
            B[i] = 0;
            continue;
        }
        if(i<N && A[i] == ans){
            A[i+1] += B[i];
            B[i] = 0;
            continue;
        }
        ok2 = true;
        return -1;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        ReadInput();
        printf("%d\n",Solve());
    }
    return 0;
}




