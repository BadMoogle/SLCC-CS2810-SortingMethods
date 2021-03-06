/* Daniel Harper
 * Assignment 2
 * CS-2430
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

#define MAX_RANDOM_ARRAY_LENGTH 50 //length of the ranomized array

void* doThreadedQuickSort(void *arg);
int * threadedQuickSort(int iArray[], int iArrayLength);
void bubbleSort(int iArray[], int iArrayLength);
void quickSort(int iArray[], int left, int right);


//---------------------Main function (program entry point)---------------------------
int main(int argc, char **argv) 
{
    timeval tStart, tFinish; //used to calculate the time a sort takes to run
    double dTime; //Used to calculate the difference between the times
    srand(time(NULL)); //Initialize the random number generator using the time_t
    
    //**************Time the Bubble Sort method***********************
    
    // Fill the array with random numbers
    int * iRandomArray = new int [MAX_RANDOM_ARRAY_LENGTH];
    for (int i = 0; i < MAX_RANDOM_ARRAY_LENGTH; i++)
    {
      iRandomArray[i] = rand() % 1000 + 1;
    }
    cout << fixed; //format the numbers that we put in cout to be a fixed length
    
    //Sort the array using bubbleSort and print the time differece.
    cout << "Sorting the Array using Bubble Sort..." << endl;
    gettimeofday(&tStart, 0);
    bubbleSort(iRandomArray, MAX_RANDOM_ARRAY_LENGTH);
    
    gettimeofday(&tFinish, 0);
    /* The following is a variation of what was found here http://stackoverflow.com/questions/588307/c-obtaining-milliseconds-time-on-linux-clock-doesnt-seem-to-work-properl
     * Apparently the clock() and time() functions on linux are not the same as they are on Windows.  Linux returns seconds, Windows returns milliseconds;
     * And I spent an hour wondering why the documentation I was looking at didn't match up with what was happening */
    dTime = ((tFinish.tv_sec - tStart.tv_sec) * 1000 + (tFinish.tv_usec - tStart.tv_usec)/1000.0) + 0.5;
    dTime /= 1000;
    cout << "Sort took " << setprecision(10) << dTime << " seconds" << endl;
    delete[] iRandomArray; // remove the array we created on the heap
    
    //***************************Time the Quick Sort Method*************************
    
    // Fill the array with random numbers
    iRandomArray = new int [MAX_RANDOM_ARRAY_LENGTH];
    for (int i = 0; i < MAX_RANDOM_ARRAY_LENGTH; i++)
    {
      iRandomArray[i] = rand() % 1000 + 1;
    }
    
    //Sort the array using QuickSort and print the time differece.
    cout << "Sorting the Array using Quick Sort..." << endl;
    gettimeofday(&tStart, 0);
    quickSort(iRandomArray, 0, MAX_RANDOM_ARRAY_LENGTH);
    gettimeofday(&tFinish, 0);
    
 
    /* The following is a variation of what was found here http://stackoverflow.com/questions/588307/c-obtaining-milliseconds-time-on-linux-clock-doesnt-seem-to-work-properl
     * Apparently the clock() and time() functions on linux are not the same as they are on Windows.  Linux returns seconds, Windows returns milliseconds;
     * And I spent an hour wondering why the documentation I was looking at didn't match up with what was happening */
    dTime = ((tFinish.tv_sec - tStart.tv_sec) * 1000 + (tFinish.tv_usec - tStart.tv_usec)/1000.0) + 0.5;
    dTime /= 1000;
    cout << "Sort took " << setprecision(10) << dTime << " seconds" << endl;
    delete[] iRandomArray; // remove the array we created on the heap
    
    
    //***************************Time the Threaded Quick Sort Method*************************
    
    // Fill the array with random numbers
    iRandomArray = new int [MAX_RANDOM_ARRAY_LENGTH];
    for (int i = 0; i < MAX_RANDOM_ARRAY_LENGTH; i++)
    {
      iRandomArray[i] = rand() % 1000 + 1;
    }
    
    //Sort the array using QuickSort and print the time differece.
    cout << "Sorting the Array using the Threaded Quick Sort..." << endl;
    gettimeofday(&tStart, 0);
    iRandomArray = threadedQuickSort(iRandomArray, MAX_RANDOM_ARRAY_LENGTH);
    gettimeofday(&tFinish, 0);
    
    /* The following is a variation of what was found here http://stackoverflow.com/questions/588307/c-obtaining-milliseconds-time-on-linux-clock-doesnt-seem-to-work-properl
     * Apparently the clock() and time() functions on linux are not the same as they are on Windows.  Linux returns seconds, Windows returns milliseconds;
     * And I spent an hour wondering why the documentation I was looking at didn't match up with what was happening */
    dTime = ((tFinish.tv_sec - tStart.tv_sec) * 1000 + (tFinish.tv_usec - tStart.tv_usec)/1000.0) + 0.5;
    dTime /= 1000;
    cout << "Sort took " << setprecision(10) << dTime << " seconds" << endl;
    //delete[] iRandomArray; // remove the array we created on the heap
    
    return 0;
}


// Used to pass the array and length to the posix thread created since we're technically allowed only one argument
struct arrayThreadInformation
{
    int* iArrayInfo;
    int iArrayLength;
};

//-----------------------------Bubblesort Algorithm-----------------------------
void bubbleSort(int iArray[], int iArrayLength)
{
  for (int i = 0; i < (iArrayLength - 1); i++)
  {
      for (int j = 0; j < (iArrayLength - i); j++)
      {
	  //Swap the values if the current is greater than the next in line
	  if (iArray[j] > iArray[j + 1])
	  {
	      int iTemp = iArray[j];
	      iArray[j] = iArray[j + 1];
	      iArray[j + 1] = iTemp;
	  }
      }
  }
  return;
}

/*---------------------Quicksort algorithm------------------------
 * Was told to get it from the internet.  Used http://www.algolist.net/Algorithms/Sorting/Quicksort with minor modifications
 * to make the code more the style I'm used to.
 * Basically sorts the array in a matter that uses left <= pivot <= right to prove that it is sorted.
 * Then chooses a new pivot by recursively calling the function.*/
void quickSort(int iArray[], int left, int right)
{
    int iLeftIterator = left, iRightIterator = right; //Used to keep track of where we are looking at in the array
    int pivot = iArray[(left + right) / 2]; //Choose a new pivot value
    
    /* iLeftIterator starts at the left of the array and gradually increments itself until it gets to the pivot
     * iRightIterator starts at the end of the array and gradually decrements itself until it gets to the pivot
     * if the value of either is greater or less than that of the pivot then it continues incrementing/decrementing the other
     * until it gets to a place where it can swap the two values. */  
    while (iLeftIterator <= iRightIterator)
    {
	while (iArray[iLeftIterator] < pivot)
	{
	    iLeftIterator++;
	}
	while (iArray[iRightIterator] > pivot)
	{
	    iRightIterator--;
	}
	if (iLeftIterator <= iRightIterator)
	{
	    int iTemp = iArray[iLeftIterator];
	    iArray[iLeftIterator] = iArray[iRightIterator];
	    iArray[iRightIterator] = iTemp;
	    iLeftIterator++;
	    iRightIterator--;
	}
    }
    
    //Once we've gone through an iteration of swapping values, we then recursively call the fuction to move the pivot
    //and begin sorting anew until both iterators have reached the other side.
    if (left < iRightIterator)
    {
	quickSort(iArray, left, iRightIterator);
    }
    if (iLeftIterator < right)
    {
	quickSort(iArray, iLeftIterator, right);
    }
    
    return;
}

/* --------------------Threaded Quick Sort-----------------------------
 * This algorithm basically divides the array into two parts then creates threads to Quicksort those sections.
 * Then it is a matter of merging the two sorted arrays together using an iterator and passing the new array back.
 * This may be more work for smaller arrays, but hopefully will pay out for larger ones.
 */
int * threadedQuickSort(int iArray[], int iArrayLength)
{
    pthread_t thread1, thread2;
    int iDivider = iArrayLength / 2;
    int * iTempArray1 = new int[iDivider];
    int * iTempArray2 = new int[iDivider];
    
    //Split the arrays into two separate to avoid concurrency issues
    for (int i = 0; i < iDivider; i++)
    {
	iTempArray1[i] = iArray[i];
    }
    for (int i = 0; i <= iDivider; i++)
    {
	iTempArray2[i] = iArray[i + iDivider];
    }
    
    //Load the information on both arrays into a structure so that we can pass it to a thread
    struct arrayThreadInformation aInfo1, aInfo2;
    aInfo1.iArrayInfo = iTempArray1;
    aInfo1.iArrayLength = iDivider - 1;
    aInfo2.iArrayInfo = iTempArray2;
    aInfo2.iArrayLength = iDivider;
    
    //Create the threads to concurrently sort both arrays
    pthread_create( &thread1, NULL, doThreadedQuickSort, (void *)&aInfo1);
    pthread_create( &thread1, NULL, doThreadedQuickSort, (void *)&aInfo2);
    
    //Wait until the work is finished to complete the next step of merging them back together
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    
    int * iNewArray = new int[iArrayLength]; //New array to hold the sorted contents
    
    //Merge the arrays back together
    int iArray1Iterator = 0, iArray2Iterator = 0, iNewArrayIterator = 0;
    while (iArray1Iterator < iDivider || iArray2Iterator < iDivider)
    {
	if (iTempArray1[iArray1Iterator] <= iTempArray2[iArray2Iterator])
	{
	    iNewArray[iNewArrayIterator] = iTempArray1[iArray1Iterator];
	    iArray1Iterator++;
	}
	else
	{
	    iNewArray[iNewArrayIterator] = iTempArray2[iArray2Iterator];
	    iArray2Iterator++;
	}
	iNewArrayIterator++;
    }
    return iNewArray; //return the newly sorted array
}

/* Used handle the information from the newly created threads
 */
void* doThreadedQuickSort(void *arg)
{
    struct arrayThreadInformation * aInfo;
    aInfo = (struct arrayThreadInformation *) arg;
    quickSort(aInfo->iArrayInfo, 0, aInfo->iArrayLength);
    return NULL;
}