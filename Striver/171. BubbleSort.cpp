/*
	O(n^2) time

	Consider an array arr[] = {5, 1, 4, 2, 8}

	First Pass: 

		Bubble sort starts with very first two elements, comparing them to check which one is greater.
		( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1. 
		( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4 
		( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2 
		( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

	Second Pass: 

		Now, during second iteration it should look like this:
		( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ) 
		( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2 
		( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
		( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 ) 
*/

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already 
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}