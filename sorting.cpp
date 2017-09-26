#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <algorithm>
#include <math.h>

#define SIZE 30
#define BUFFER 1000

using namespace std;

void heapsort(int arrar[], int n, int *num);
void quicksort(int array[], int left, int right, int *num);
void heapify(int arr[], int n, int i, int *num);
int partition(int array[], int left, int right, int *num);
float mean(int array[]);
float std_dev(int array[]);

int main(int argc, char **argv[])
{
	int comp_quick[SIZE];     //allocate arrays for storing number of comparisons
	int comp_heap[SIZE];  
	int random_quick[BUFFER];
	int random_heap[BUFFER];
	int num = 0;

	srand((unsigned int)time(NULL));    // seed rand() with system time
	int n = sizeof(random_heap) / sizeof(random_heap[0]);  //used later for heapsort

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < BUFFER; j++)   //random numbers stored into an array of size BUFFER
		{
			random_quick[j] = random_heap[j] = (int)(rand() % 10000) + 1;  // limit data to 0 to 10000.
		}
		quicksort(random_quick, 0, SIZE, &num);
		comp_quick[i] = num;
		num = 0;
		heapsort(random_heap, n, &num);
		comp_heap[i] = num;
		num = 0;
	}

	sort(comp_quick, comp_quick + SIZE);
	sort(comp_heap, comp_heap + SIZE);
	cout << "Quick Sort Results" << endl;
	cout << "Min: " << comp_quick[0] << " Max: " << comp_quick[SIZE] << " Mean: " << mean(comp_quick) << " Median: " << comp_quick
		[SIZE / 2] << " Mean: " << m
ean(comp_quick) << " Std Dev: " << std_dev(comp_quick) << endl << endl;

	cout << "Heap Sort Results" << endl;
	cout << "Min: " << comp_heap[0] << " Max: " << comp_heap[SIZE] << " Mean: " << mean(comp_heap) << " Median: " << comp_heap
		[SIZE / 2] << " Mean: " << mean(comp_heap) << " Std Dev: " << std_dev(comp_heap) << endl;

	return 0;
}

 void quicksort(int array[], int left, int right, int *num)
{
	 // top = subscript of beginning of array
	 // bottom = subscript of end of array

	 int middle;
	 if (left < right)
	 {
		 middle = partition(array, left, right, num);
		 quicksort(array, left, middle, num);   // sort first section
		 quicksort(array, middle + 1, right, num);    // sort second section
	 }
	 return;
}
 int partition(int array[], int left, int right, int *num)
 {
	 int x = array[left];
	 int i = left - 1;
	 int j = right + 1;
	 int temp;
	 do
	 {
		 do
		 {
			 j--;
			 *num++;
		 } while (x > array[j]);

		 do
		 {
			 i++;
			 *num++;
		 } while (x <array[i]);

		 if (i < j)
		 {
			 temp = array[i];
			 array[i] = array[j];
			 array[j] = temp;
		 }
	 } while (i < j);
	 return j;           // returns middle subscript  
 }


void heapsort(int arr[], int n, int *num)
{
		// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, num);

		// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
			// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0, num);
		}
}

void heapify(int arr[], int n, int i, int *num)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
		*num++;
	}

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
		*num++;
	}

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest, num);
	}
}

float mean(int array[])
{
	float sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += array[i];
	}
	return sum / SIZE;
}

float std_dev(int array[])
{
	float mean = 0; 
	float std = 0;

	for(int i = 0; i < SIZE; i++)
	{
		mean += array[i];
	}
	mean = mean / SIZE; 

	for (int i = 0; i < SIZE; i++)
	{
		std = pow((array[i] - mean), 2); 
	}
	std = sqrt(std / SIZE);
	return std;
} 
