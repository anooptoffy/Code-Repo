
#include<iostream>
#include<algorithm> // for heap operations
#include<vector>

using namespace std;

int main()
{
     int a[] = {20, 30, 40, 25, 15};

    // Initializing a vector
    vector<int> v1(a,a+5); 
     
    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());
     
    // Displaying the maximum element of heap
    // using front()
    v1.push_back(99);
    push_heap(v1.begin(), v1.end());
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;
     
    return 0;
}