#include <iostream>
#include <random>
#include <time.h>
#include <fstream>




using namespace std;




//declare global variables here
int MAXRANGE = 1000000;

//file pointer
ofstream output;

//initialize variables for timer
clock_t tstart, tend;
double cpu_time_used_insertionsort,cpu_time_used_mergesort,
cpu_time_used_quicksort,cpu_time_used_heapsort;

//array using vector library

vector<int> arrayint, insertionsortarray, mergesortarray, quicksortarray, heapsortarray; 




/*Utility Functions*/

//outputs to a file
void outputfile(){
    output.open("output.txt", ios::out); 
    
output << "Original Array : " << "["; 

for (int i = 0; i < arrayint.size(); i++) 
{
    output << arrayint[i] << ", "; 
}
output << "]" << endl;
output << endl;

//print the truncated insertion sorted array
output << "Insertion Sorted Array : " << "[";



for (int i = 0; i < insertionsortarray.size(); i++)
{
    output << insertionsortarray[i] << ", ";
}
output << "]" << endl;
output << "Time to execute : " << cpu_time_used_insertionsort << endl;
output << endl;



output << "Merge Sorted Array : " << "[";

for (int i = 0; i < mergesortarray.size(); i++)
{
    output << mergesortarray[i] << ", ";
}
output << "]" << endl;
output << "Time to execute : " << cpu_time_used_mergesort << endl;
output << endl;


output << "Quicksorted Array : " << "[";

for (int i = 0; i < quicksortarray.size(); i++)
{
    output << quicksortarray[i] << ", ";
}
output << "]" << endl;
output << "Time to execute : " << cpu_time_used_quicksort << endl;
output << endl;


output << "Heapsorted Array : " << "[";

for (int i = 0; i < heapsortarray.size(); i++)
{
    output << heapsortarray[i] << ", ";
}
output << "]" << endl;
output << "Time to execute : " << cpu_time_used_heapsort << endl;
output << endl;

}

//print truncated array function
void printpartialarray(vector<int> array, int valuestoprint, int n)
{
for (int i = 0; i < valuestoprint; i++)
{
    cout << array[i] << ", ";
}

cout << "... " << array[n-1];

}

//print array function
void printarray(vector<int> array)
{
for (int i = 0; i < array.size(); i++)
{
    cout << array[i] << ", ";
}
}

//randomizer using the random library
int randomnumber()
{

//generator for a random value
random_device randomgen; 

//distribution range
uniform_int_distribution<> from(0, MAXRANGE);

//generate a random integer and return the random integer
int randomint = from(randomgen);
return randomint;
}

//function to fill array with random integers
void fillrand(int N){

//iterating over N to insert values to array
for (int i = 0; i < N; i++)
{
    arrayint.insert(arrayint.begin(),randomnumber());
}
}

//function to fill array with integers in increasing order 
void fillsorted(int N){

//take input for X variable
int X;
cout << "Enter X variable : ";
cin >> X;

//iterating over N to insert values to array
for (int i = 0; i < N; i++)
{
    arrayint.push_back(N+(i+1)*X);
}
}



//swap function for 2 elements in array
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}







/*Sorting Functions*/

//Merge Sort

//merging function
void merge(vector<int>& array, int start, int mid, int end)
{

    //declare size of left and right subarrays
    int subarrayL = mid - start + 1;
    int subarrayR = end - mid;
    
    //create left and right subarrays
    auto *leftArray = new int[subarrayL];
    auto *rightArray = new int[subarrayR];
    

    //iterate over subarrays
    for (int i = 0; i < subarrayL; i++)
    {
        //copy values from original array
        leftArray[i] = array[start + i];
    }
    
    for (int j = 0; j < subarrayR; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }
    

    //initialize indexes;
    int indexL = 0;
    int indexR = 0;
    int indexMerged = start;
    
    //merge left and right subarrays
    while(indexL < subarrayL && indexR < subarrayR)
    {
        //finds the lowest value between left and right subarray
        if (leftArray[indexL] <= rightArray[indexR])
        {
            //copies the value to the merged array
            array[indexMerged] = leftArray[indexL];
            //increment indexes
            indexL = indexL + 1;
            indexMerged = indexMerged + 1;
            
        }
        else
          {
            array[indexMerged] = rightArray[indexR];
            indexR = indexR + 1;
            indexMerged = indexMerged + 1;
            
        }
    }

    //copies the remaining contents of subarray to merged array if any
    while(indexL < subarrayL)
    {
        array[indexMerged] = leftArray[indexL];
        indexL = indexL + 1;
        indexMerged = indexMerged + 1;
    }


    
      while(indexL < subarrayR)
    {
         array[indexMerged] = rightArray[indexR];
            indexR = indexR + 1;
            indexMerged = indexMerged + 1;
    }
    
    
}


void mergesort(vector<int>& array, int start, int end)
{
    if (start >= end){
        return;
    }
    //finds the middle index of array
    int mid = start + (end - start)/ 2;
    //recursive call to sort first half of array
    mergesort(array, start, mid);
    //recursive call to sort second half of array
    mergesort(array, mid + 1, end);
    //call to merge array
    merge(array, start, mid, end);
  
}


//Insertion Sort

void insertionsort(vector<int>& array, int n)
{

    //initialize variables
    int key;
    int i;
    int j;
    
    //iterate starting from the second element of array
    for(i = 1; i < n; i++)
    {
        //assigns iterator element to key
        key = array[i];

        //index of element behind iterator 
        j = i - 1;
        
        
        while(j >= 0 && key < array[j])
        {
            //move element to front
            array[j+1] = array[j];
            //decrement j
            j = j - 1;
        }
        
        //moves key to j+1 after while loop
        array[j+1] = key;
    }
}


//Quick Sort




//function to pass a random element from array to partition function pivot



// function to rearrange array (find the partition point)
int partition(vector<int>& array, int start, int end) {
    
  // select the rightmost element as pivot

  int pivot = array[end];
  
  // pointer for smaller element
  int i = (start - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = start; j < end; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[end]);
  
  // return the partition point
  return (i + 1);
}



void quicksort(vector<int>& array, int start, int end) {
 



 while (start < end) {
      
    // find the pivot element
    int pi = partition(array, start, end);

    if((pi-start) <= (end - pi))
    {
    quicksort(array, start, pi - 1);
    start = start + 1;
    }
    // recursive call on the left of pivot
    
    

    else
    {
    // recursive call on the right of pivot
    quicksort(array, pi + 1, end);
    end = pi - 1;
    }

  }
}

 
 


//Heap Sort
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
//main function to do heap sort
void heapsort(vector<int>& arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}




/*Main Function*/

int main() {


//initialize N variable
int N;
cout << "Please input N (Number of integers): ";

//take input for size of array(N)
cin >> N;

//method of filling array with values
fillsorted(N);  //fillsorted(N) for increasing order, fillrand(N) for random values

//copy generated arrays to other arrays
insertionsortarray = arrayint;
mergesortarray = arrayint;
quicksortarray = arrayint;
heapsortarray = arrayint;

//print the truncated original array
cout << "Original Array : " << "[";
printpartialarray(arrayint, 4, N);
cout << "]" << endl;
cout << endl;


//print the truncated insertion sorted array
cout << "Insertion Sorted Array : " << "[";

//execute algorithm and display running time
tstart = clock();
insertionsort(insertionsortarray, N);
tend = clock();
cpu_time_used_insertionsort = ((double) (tend - tstart)) / CLOCKS_PER_SEC;
printpartialarray(insertionsortarray, 4, N);
cout << "]" << endl;
cout << "Time to execute : " << cpu_time_used_insertionsort << endl;
cout << endl;


//print the truncated merge sorted array
cout << "Merge Sorted Array : " << "[";

//execute algorithm and display running time
tstart = clock();
mergesort(mergesortarray, 0, N-1);
tend = clock();
cpu_time_used_mergesort = ((double) (tend - tstart)) / CLOCKS_PER_SEC;
printpartialarray(mergesortarray, 4, N);
cout << "]" << endl;
cout << "Time to execute : " << cpu_time_used_mergesort << endl;
cout << endl;


//print the truncated quicksorted array
cout << "Quicksorted Array : " << "[";

//execute algorithm and display running time
tstart = clock();
quicksort(quicksortarray, 0, N-1);
tend = clock();
cpu_time_used_quicksort = ((double) (tend - tstart)) / CLOCKS_PER_SEC;
printpartialarray(quicksortarray, 4, N);
cout << "]" << endl;
cout << "Time to execute : " << cpu_time_used_quicksort << endl;
cout << endl;

//print the truncated quicksorted array
cout << "Heapsorted Array : " << "[";

//execute algorithm and display running time
tstart = clock();
heapsort(heapsortarray, N);
tend = clock();
cpu_time_used_heapsort = ((double) (tend - tstart)) / CLOCKS_PER_SEC;
printpartialarray(heapsortarray, 4, N);
cout << "]" << endl;
cout << "Time to execute : " << cpu_time_used_heapsort << endl;
cout << endl << endl;

//output results
outputfile();

cout << "File output at /output.txt";
cout << endl;


return 0;


}

  
