#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>


using namespace std;

/// <summary>
/// Facilitates dispensing stamps for a postage stamp machine.
/// </summary>
class StampDispenser
{
public:
    /// <summary>
    /// Initializes a new instance of the <see cref="StampDispenser"/> class that will be 
    /// able to dispense the given types of stamps.
    /// </summary>
    /// <param name="stampDenominations">
    /// The values of the types of stamps that the machine has.  
    /// Should be sorted in descending order and contain at least a 1.
    /// </param>
    /// <param name="numStampDenominations">
    /// The number of types of stamps in the stampDenominations array. 
    /// </param>
    StampDispenser(const int* stampDenominations, size_t numStampDenominations);
	~StampDispenser() { delete [] denominations; }
    /// <summary>
    /// Returns the minimum number of stamps that the machine can dispense to
    /// fill the given request.
    /// </summary>
    /// <param name="request">
    /// The total value of the stamps to be dispensed.
    /// </param>
    /// <returns>
    /// The minimum number of stamps needed to fill the given request.
    /// </returns>
    int CalcNumStampsToFillRequest(int request);

private:
	int* denominations; 
	size_t numDenominations;

    /// <summary>
    /// The comparator function used in the C++ BIF qsort() to sort an array 
    /// of integer into descending order.
    /// </summary>
    /// <param name="p, q">
    /// The two elements in the array to be compared.
    /// </param>
    /// <returns>
    /// If p > q, the function returns a value less than 0.
	/// If p < q, the functionreturns a value greater than 0.
	/// Otherwise, the function returns 0.
    /// </returns>
	static int comp( const void* p, const void* q) {return (*(int*)q - *(int*)p);}

	/// <summary>
    /// A helper function recursively prints out all the stamp values returned by the dispenser for a given request on the screen.
    /// </summary>
    /// <param name="request">
    /// The input stamp value.
    /// </param>
    /// <param name="stampTrack">
    /// An int array with each element value represents the last stamp value used to make that element value.
    /// </param>
    /// <returns>
    /// </returns>
	void trackPrint( int request, vector<int> stampTrack )
	{
		if( request == 0 )
			return;
		else
		{
			cout << stampTrack[request];
			if(stampTrack[request] == 1)
				cout << "cent ";
			else
				cout << "cents ";
			trackPrint(request-stampTrack[request], stampTrack);
		}
	}
}; 

StampDispenser::StampDispenser(const int* stampDenominations, size_t numStampDenominations)
{
	cout << "Prepare the Stamp Dispenser for you ..." << endl;

	///Validate the pointer and input array size.
	assert(numStampDenominations > 0 && stampDenominations != nullptr);

	///Initialize member variables. 
	denominations = new int[numStampDenominations];
	///Set up a flag to check if the input denominations contain 1 cent.
	bool hasOne = false;
	for( size_t i = 0; i < numStampDenominations; i++ )
	{
		denominations[i] = stampDenominations[i];
		if( denominations[i] == 1 )
			hasOne = true;
	}
	///If input does not contain 1 cent, fail.
	assert( hasOne );
	
	numDenominations = numStampDenominations;

	///Sort the denominations in value descending order.
	qsort(denominations, numDenominations, sizeof(int), this->comp);

	///Make the program user-friendly by printing out some system info.
	cout << "The denominations in the dispenser are: ";
	for( size_t i = 0; i < numDenominations; i++ )
		cout << denominations[i] << " ";
	cout << endl << endl;
}

int StampDispenser::CalcNumStampsToFillRequest(int request)
{
    /// <param name="numOfStamps">
    /// Save the number of stamps used to make the requested value.
    /// </param>
    /// <param name="lastUsed">
    /// Save the denomination of the last used stamp.
	/// </param>
    /// <param name="stampUsed">
    /// An array used to save each number of stamps used to make the value that is between 1 and the requested.
	/// </param>
    /// <param name="stampTrack">
    /// An array that is indexed by a value and contains the denomination of the last used stamp to make that value.
	/// </param>

	int numOfStamps;
	int lastUsed;
	vector<int> stampUsed(request+1, 0);
	vector<int> stampTrack(request+1, 0);

	///A Dynamic Programming solution. Start from the value of 1 cent,
	///calculate the number of stamps needed to make that value until the requested value.
	///Save each intermediate result for each intermediate value into a table (array) to lookup for future calculations.
	for( int i = 1; i <= request; i++ )
	{
		
		///Initialize the values for the variables in each iteration.
		numOfStamps = numeric_limits<int>::max();
		lastUsed = 0;

		///For the current value i, minmumNumOfStamps(i) = min{ minmumNumOfStamps(i-denominations[j])+1 }, where denominations[j] <= i.
		///for example, we have denominations {3, 2, 1} less than value i,
		///then minmumNumOfStamps(i) = min(minmumNumOfStamps(i-3)+1, minmumNumOfStamps(i-2)+1, minmumNumOfStamps(i-1)+1).
		for( size_t j = 0; j < numDenominations; j++ )
		{
			if( denominations[j] > i )
				continue;

			if(stampUsed[i-denominations[j]] + 1 < numOfStamps)
			{
				///Record current minmumNumOfStamps and according last used denomination for i
				numOfStamps = stampUsed[i-denominations[j]] + 1;
				lastUsed = j;
			}
		}

		///Save the minmumNumOfStamps for value i in stampUsed[i],
		///put the last denomination that is used for making i into stampTrack[i].
		stampUsed[i] = numOfStamps;
		stampTrack[i] = denominations[lastUsed];
	}
	
	///Print out all the stamp values used to make the requested value.
	///Make the program user-friendly.
	cout << "you would like to have stamps with value of " << request << endl << endl;
	cout << "The dispenser will give you the following stamps: ";
	trackPrint(request, stampTrack);
	cout << endl << endl;

	///Return the minimum number of stamps used for the requested value. 
	return stampUsed[request];
}


int main()
{
    int stampDenominations[] = {2, 90, 30, 24, 10, 6, 1};
    StampDispenser stampDispenser(stampDenominations, 7);
    ///assert(stampDispenser.CalcNumStampsToFillRequest(18) == 3);

	///Test case for StampDispenser.
	cout << "Please enter the requested value of stamps: ";
	int request;
	cin >> request;
	cout << "The total number of stamps you have is: " << stampDispenser.CalcNumStampsToFillRequest(request) << endl;

    return 0;
}