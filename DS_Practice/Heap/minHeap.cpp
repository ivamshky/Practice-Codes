#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class minHeap{
    int capacity;
    int *harr;
    int heap_size;
    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i){
        return (2*i+1);
    }

    int right(int i){
        return (2*i+2);
    }
public:
    minHeap(int c): capacity(c), heap_size(0){
        harr = new int[capacity];
    }

    void minHeapify(int);
    int extractMin();
    int getMin(){ return harr[0];}
    void deleteKey(int);
    void decreaseKey(int i, int new_val);
    void insertKey(int);
};

void minHeap::decreaseKey(int i, int new_val){
    harr[i] = new_val;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(harr[parent(i)],harr[i]);
        i = parent(i);
    }
}

int minHeap::extractMin(){
    if(heap_size <= 0)
        return INT_MAX;
    if(heap_size==1){
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    minHeapify(0);
    return root;
}

void minHeap::deleteKey(int k){
    decreaseKey(k, INT_MIN);
    extractMin();
}

void minHeap::insertKey(int key){
    if(heap_size==capacity){
        cout<<"Overflow"<<endl;
        return;
    }
    harr[++heap_size - 1] = key;
    int i = heap_size-1;

    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(harr[i],harr[parent(i)]);
        i = parent(i);
    }
}

void minHeap::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l<heap_size && harr[l]<harr[i])
        smallest = l;
    if(r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if(smallest != i){
        swap(harr[i],harr[smallest]);
        minHeapify(smallest);
    }
}

int main()
{
    minHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}