#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
 *
 * Majority Number n/3 + 1
 *
 * Is there better algorithm than O(nlg(n)) ?
 * Is O(n) practical? 
 * Useful links :
 *
 * 1. http://stackoverflow.com/questions/4325200/find-the-majority-element-in-array
 * 2. http://www.geeksforgeeks.org/majority-element/ 
 * 3. https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
 *
 */

/*
	Using findRank Algorithms

	Find the elements at ranks n/3 and 2n/3 then
	It is trivial that the majoirty element is one among them.
	Find that by using a loop of O(n)

	Yo Yo
*/


void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int pivot(int a[], int i, int j){
	int pivot =  i + rand() % (j - i +1);
	return pivot;
}

int partition(int A[], int f, int l, int pivot){

	int i,j;
	i = f;
	swap(&A[pivot],&A[l]);
	j = l - 1;
	
	while( i < j)
	{

		while(A[i] <= A[pivot]) i++;
		while(A[j] > A[pivot]) j--;
		if(i <= j){
			swap(&A[i],&A[j]);
			i++;
		}		
	}
	j++;
	swap(&A[j],&A[l]);	
	return j;
}


// int partition(int A[], int f, int l, int pivot){

// 	int i,j;
// 	i = f;
// 	j = l;
// 	swap(&A[pivot],&A[j]);
// 	while( i < j)
// 	{

// 		while(A[i] <= A[pivot]) i++;
// 		while(A[j] > A[pivot]) j--;
// 		if(i <= j)
// 			swap(&A[i],&A[j]);
// 		i++;
// 		j--;
// 	}
// 	swap(&A[j],&A[l]);	
// 	return j;
// }



// int partition(int arr[], int start, int end, int pos)
// {
//         if (start == end)
//                 return start;

//         int i, j;
//         i = start - 1;
//         j = start;
//         //pos = pivot(arr, start, end);
//         swap(&arr[pos], &arr[end]);
//         while (j < end) 
//         {
//                 if (arr[j] <= arr[end]) 
//                 {
//                         i = i + 1;
//                         swap(&arr[i], &arr[j]);
//                 }
//                 j++;
//         }
//         i = i + 1;
//         swap(&arr[i], &arr[end]);
//         return i;
// }


int findRank(int a[], int i, int j, int r){
	int p = pivot(a,i,j); // modify it with goodPivot to get O(n) algorithm TODO
	int k = partition(a,i,j,p);

	if(r == j-k+1)
		return k; // returns the index of the pivot
	else if( r < j-k+1)
		return findRank(a,k+1,j,r);
	else
		return findRank(a,i,k -  1,r-j+k-1);
}	

int main(int argc, char const *argv[])
{
	int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	int size = sizeof(a) / sizeof(a[0]);
	int oneThird = size/3, twoThrid = (2*size)/3;

	int chanceOne, chanceTwo;

	chanceOne = findRank(a, 0, size -1, oneThird);
	chanceTwo = findRank(a, 0, size -1, twoThrid);

	printf("Possibilities for Majority element are  : %d %d\n", a[(size - 1) - chanceOne + 1], a[(size - 1) - chanceTwo + 1] );


	int ele1 = a[(size - 1) - chanceOne + 1];
	int ele2 = a[(size - 1) - chanceTwo + 1];
	int count1 = 0, count2 = 0;
	for(int i = 1; i < size ; i++){
		if(a[i] == ele1){
			count1++;
		}
	}

	if(count1 >= ((size/3) + 1))
		printf("Majority element can be  %d\n", ele1);

	for(int i = 1; i < size ; i++){
		if(a[i] == ele2){
			count2++;
		}
	}

	if(count2 >= ((size/3) + 1))
		printf("Majority element can be  %d\n", ele2);

	return 0;
}