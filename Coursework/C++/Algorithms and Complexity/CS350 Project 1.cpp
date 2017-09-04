/*
    Program:     Analyzing Sorting Algorithms
    Author:      Jason Custodio
    Class:       CS350
    Date:        03/05/2016
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

clock_t start;
clock_t  stop;
const int SIZE  = 100000000;
const int RANGE = SIZE+5;

void Create       (vector<int>&);
void Display      (vector<int>&);
void SelectionSort(vector<int>&);
void InsertionSort(vector<int>&);
void MergeSort    (vector<int>&);
void MergeSort    (vector<int>&, int, int, double&);
void Merge        (vector<int>&, int, int, int, double&);
void BucketSort   (vector<int>&);
void QuickSort    (vector<int>&);
void QuickSort    (vector<int>&, int, int);
void ShellSort    (vector<int>&);
void Sort         (vector<int>&);

int main()
{
    vector <int> input;
    Create(input);
    vector <int> copy = input;

    //***************************
    cout << "Array Size:     "
         << SIZE << endl << endl;
/*
    cout << "Selection Sort: ";
    SelectionSort(input);
    input = copy;
*/
    cout << "Insertion Sort: ";
	InsertionSort(input);
    input = copy;

	cout << "Shell Sort:     ";
	ShellSort(input);
    input = copy;

	cout << "Merge Sort:     ";
	MergeSort(input);
    input = copy;

    cout << "Bucket Sort:    ";
	BucketSort(input);
    input = copy;

    cout << "Quick Sort:     ";
	QuickSort(input);
    input = copy;

    cout << "C++ Sort:       ";
    Sort(input);

    return 0;
}

void Sort(vector<int>& input)
{
    //www.cplusplus.com/reference/algorithm/sort/
    start = clock();
    sort(input.begin(),input.end());
    stop = clock();
    cout << difftime(stop,start) << " ms\n\n";
}

void Create(vector <int>& input)
{
    /*
    for(int i = SIZE; i>0; --i)
    {
        input.push_back(i);
    }
    */

    for(int i = 0; i<SIZE; ++i)
    {
        int x = (rand()%5)+1;
        input.push_back(i+x);
    }


    /*
    for(int i = 0; i<SIZE; ++i)
        input.push_back(rand()%RANGE);
    */
}

void Display(vector <int>& input)
{
	for(unsigned int i = 0; i<input.size(); ++i)
		cout << "  " << input[i];
    cout << endl;
}

void SelectionSort(vector <int>& input)
{   //www.algolist.net/Algorithms/Sorting/Selection_sort
    int i    = 0;
    int j    = 0;
    int min  = 0;
    int temp = 0;

    start = clock();
    for(i = 0; i < input.size() - 1; i++)
    {
        min = i;                              //Position to swap smallest value
        for(j = i + 1; j < input.size(); j++) //Finds smallest value
            if (input[j] < input[min])
                min = j;

        if(min != i)                          //SWAP
        {
            temp       = input[i];
            input[i]   = input[min];
            input[min] = temp;
        }
    }
    stop = clock();

	cout << difftime(stop,start) << " ms\n\n";
}

void InsertionSort(vector <int>& input)
{   //www.algolist.net/Algorithms/Sorting/Insertion_sort
    int i    = 0;
	int j    = 0;
	int temp = 0;

    start = clock();
    for(i = 1; i < input.size(); i++)
	{
		j = i;
		while(j > 0 && input[j - 1] > input[j])
		{
			temp         = input[j];
            input[j]     = input[j - 1];        //SWAP if value to left is greater
            input[j - 1] = temp;
            j--;
        }
    }
    stop = clock();

	cout << difftime(stop,start) << " ms\n\n";
}

void MergeSort(vector<int>& input)
{
    double time = 0; //To save running time

    MergeSort(input, 0, input.size()-1, time);

    cout << time << " ms\n\n";
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void MergeSort(vector <int>& input, int l, int r, double& time)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        MergeSort(input, l, m, time);
        MergeSort(input, m+1, r, time);
        Merge(input, l, m, r, time);
    }
}

//Merge the two haves input[l..m] and input[m+1..r] of vector input
void Merge(vector <int>& input, int l, int m, int r, double& time)
{
    //http://geeksquiz.com/merge-sort/
    int i  = 0;
    int j  = 0;
    int k  = 0;
    int n1 = m - l + 1;
    int n2 = r - m;

    //Create Temp Vectors
    vector<int> L(n1);
    vector<int> R(n2);

    //Copy Data
    for(i = 0; i < n1; i++)
        L[i] = input[l + i];
    for(j = 0; j < n2; j++)
        R[j] = input[m + 1+ j];

    //Merge the temp vectors back into input[l..r]
    i = 0;
    j = 0;
    k = l;

    start = clock();
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            input[k] = L[i];
            i++;
        }
        else
        {
            input[k] = R[j];
            j++;
        }
        k++;
    }
    //Copy the remaining elements of L, if there are any
    while (i < n1)
    {
        input[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R, if there are any
    while (j < n2)
    {
        input[k] = R[j];
        j++;
        k++;
    }
    stop = clock();
    time += difftime(stop,start);
}

void BucketSort (vector<int>& input)
{
    //www.sanfoundry.com/cpluscplus-program-implement-bucket-sort/
    //Range of values is [0,SIZE]
    int i = 0;
    int j = 0;
    int k = 0;

    //Create RANGE number of empty buckets
    vector<int> buckets(RANGE);

    start = clock();
    //Increment the number of times each element is present in input
    //Insert them in the buckets
    for (i = 0; i < input.size(); ++i)
        ++buckets[input[i]];

    //Sort using insertion sort and concatenate
    for (i = 0, j = 0; j < RANGE; ++j)
        for (k = buckets[j]; k > 0; --k)
            input[i++] = j;
    stop = clock();
    cout << difftime(stop,start) << " ms\n\n";
}

void QuickSort(vector<int>& input)
{
    start = clock();
    QuickSort(input, 0, input.size());
    stop  = clock();
    cout << difftime(stop,start) << " ms\n\n";
}

void QuickSort(vector<int>& input, int left, int right)
{   //www.algolist.net/Algorithms/Sorting/Quicksort
    int i = left;
    int j = right;
    int temp;
    int pivot = input[(left + right) / 2];
    //Partition
    while (i <= j)
    {
        while (input[i] < pivot)
            i++;
        while (input[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
      /* recursion */
    if (left < j)
        QuickSort(input, left, j);
    if (i < right)
        QuickSort(input, i, right);
}



void ShellSort(vector<int>& input)
{
	//geeksquiz.com/shellsort/
    //Start with a big gap, then reduce the gap
	int i    = 0;
	int j    = 0;
	int gap  = 0;
	int temp = 0;
	
    start = clock();
    for (gap = input.size()/2; gap > 0; gap /= 2)
    {
        //Do a gapped insertion sort for this gap size.
        //The first gap elements input[0..gap-1] are already in gapped order
        //keep adding one more element until the entire vector is
        //gap sorted
        for (i = gap; i < input.size(); i += 1)
        {
            //Add input[i] to the elements that have been gap sorted
            //Save input[i] in temp and make a hole at position i
            temp = input[i];

            //Shift earlier gap-sorted elements up until the correct
            //location for input[i] is found
            for (j = i; j >= gap && input[j - gap] > temp; j -= gap)
                input[j] = input[j - gap];

            //Put temp (the original input[i]) in its correct location
            input[j] = temp;
        }
    }
    stop = clock();
    cout << difftime(stop,start) << " ms\n\n";
}

