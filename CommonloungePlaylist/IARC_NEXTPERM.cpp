// C++ program to find the smallest number which greater than a given number
// and has same set of digits as given number
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void findNext(int number[], int n)
{
    int i, j;

    // I) Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;


	if(i==0)
		return;

    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;

    // III) Swap the above found smallest digit with number[i-1]
    swap(number[smallest], number[i-1]);

    // IV) Sort the digits after (i-1) in ascending order
    reverse(number+i,number+n);


    return;
}

int main()
{
    int N,K;
    cin>>N>>K;
    while(K--){
		int digits[N];
		for(int i=0;i<N;i++)
			cin>>digits[i];
		findNext(digits, N);
		for(int i=0;i<N;i++){
			cout<<digits[i]<<" ";
		}
		cout<<endl;

    }
    //char digits[] = "534976";

    return 0;
}
