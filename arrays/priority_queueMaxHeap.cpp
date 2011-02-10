#include <iostream>
#include <vector>

#define SIZE 50

using namespace std;

void display( int A[] , int n ){
	for(int i = 0 ; i < n ; i++ )
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int heapMaximum( int A[] ){
	return A[0];
}

void maxHeapify( int a[] , int i , int heapSize ){
	int l = 2*i+1;
	int r = 2*i+2;

	int largest = -1;
	if( l < heapSize && a[l] > a[i] ){
		largest = l;
	}
	else largest = i;

	if( r < heapSize && a[r] > a[largest] ){
		largest = r;
	}

	if( largest != i ){
			swap( a[largest] , a[i] );
			maxHeapify( a , largest , heapSize );
	}
}

int heapExtractMax( int A[] , int &heapSize ){
	if( heapSize == 0 )
		return -1;
	int MAX = A[0];
	A[0] = A[heapSize-1];
	heapSize = heapSize-1;
	maxHeapify( A , 0 , heapSize );
	return MAX;
}

void heapIncreaseKey( int A[] , int i , int key ){
	if( key < A[i] )
		return;
	A[i] = key;
	while( i > 0 && A[ i/2 ] < A[ i ] )
	{
		swap( A[ i ] , A[ i/2 ] );
		i = i/2;	// i.e. i = parent(i);
	}
}

void maxHeapInsert( int A[] , int key , int &heapSize ){
	heapSize = heapSize + 1;
	A[ heapSize-1 ] = INT_MIN;
	display(A,heapSize);
	heapIncreaseKey( A , heapSize-1 , key );
}

int main(){
	int A[SIZE],heapSize=0;
	char ch='y';
	while( ch == 'y' || ch == 'Y' )
	{
		int key;
		cout<<"Key to insert: ";
		cin>> key;

		maxHeapInsert( A , key , heapSize );

		display( A , heapSize );

		cout<<"Continue: (y/n): ";
		cin>>ch;
	}
}