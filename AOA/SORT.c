#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void
insertionSort (long int arr[], int n)
{
  long int i, j, temp;
  for (i = 1; i < n; i++)
    {
      temp = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > temp)
	{
	  arr[j + 1] = arr[j];
	  j--;
	}
      arr[j + 1] = temp;
    }

}

void
selectionSort (long int arr[], int n)
{
  long int i, j, key, temp;
  for (i = 0; i < n; i++)
    {
      key = arr[i];
      for (j = i + 1; j < n; j++)
	{
	  if (arr[j] < key)
	    {
	      key = arr[j];
	    }
	}
      temp = arr[i];
      arr[i] = key;
      key = temp;
    }
}


int partition(long int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

 
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(long int a[], int low, int high)
{
    int partitionIndex; 

    if (low < high)
    {
        partitionIndex = partition(a, low, high); 
        quickSort(a, low, partitionIndex - 1);  
        quickSort(a, partitionIndex + 1, high); 
    }
}


int
main ()
{
  int arr[5] = { 3, 6, 2, 0, 7 }, n = 50000;
  long int randArray[n],sortedArray[n],reverseArray[n];
  clock_t start, end;
  double excution_time;
  long int i;        
    for(i=0;i<n;i++){
  randArray[i]=rand()%100; 
    }
    for(i=n;i>=0;i--){
  reverseArray[n-i]=i;  
    }
    
printf("\n-------------------Insertion Sort--------------------\n");
printf("\nAvg Case\n");
  start = clock ();
    insertionSort (randArray, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by insertionSort : %lf \n", excution_time);

printf("\nBest Case\n");
  start = clock ();
    insertionSort (randArray, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by insertionSort : %lf \n", excution_time);
  
printf("\nWorst Case\n");
  start = clock ();
    insertionSort (reverseArray, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by insertionSort : %lf \n", excution_time);
    
printf("\n-------------------Selection Sort--------------------\n");
printf("\nAvg Case\n");
  start = clock ();
    selectionSort (randArray, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by selectionSort : %lf \n", excution_time);

printf("\nBest Case\n");
  start = clock ();
    selectionSort (randArray, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by selectionSort : %lf \n", excution_time);
  
printf("\nWorst Case\n");
  start = clock ();
    selectionSort (reverseArray, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by selectionSort : %lf \n", excution_time);
  
    
printf("\n-------------------Quick Sort--------------------\n");
printf("\nAvg Case\n");
  start = clock ();
    quickSort (randArray,0, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by quickSort : %lf \n", excution_time);

printf("\nBest Case\n");
  start = clock ();
    quickSort (randArray,0, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by quickSort : %lf \n", excution_time);
  
printf("\nWorst Case\n");
  start = clock ();
    quickSort (reverseArray,0, n);  
  end = clock ();
  
  excution_time = ((double) (end - start)) ;
  printf ("The time taken by quickSort : %lf \n", excution_time);
    
  return 0;
}


