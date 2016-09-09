#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

/*
	10^4 smallest number from an array of size 10^6

	Running and compiling

	$g++ ksmallestHeap.cpp data_decimal.in
	$./a.out

	Complexity is O(nlog(k))
*/



#define MAX_ARRAY_SIZE 1000000
#define MAX_HEAP_SIZE 10000

using namespace std;

main(int argc, char const *argv[])
{

	int a[MAX_HEAP_SIZE];

	// Opening the file for reading
	ifstream fp;
	fp.open(argv[1]);

	for (int i = 0; i < MAX_HEAP_SIZE; ++i)
	{
		fp >> a[i];
		//cout << a[i] << endl;
	}

	//  Creating vector
	std::vector<int> v(a,a+10000);
	//  Converting the vector to Heap using make_heap function
	make_heap(v.begin(),v.end());

	int element;
	for (int i = MAX_HEAP_SIZE; i < MAX_ARRAY_SIZE; ++i)
	{
		pop_heap(v.begin(),v.end()); 
		v.pop_back();
		fp >> element;
		v.push_back(element);
    	push_heap(v.begin(), v.end());
	}

	pop_heap(v.begin(),v.end()); 
	v.pop_back();
	
	sort_heap (v.begin(),v.end()); // not acutally needed
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}


   	fp.close();
	return 0;
}