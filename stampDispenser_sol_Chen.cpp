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
private:
    /// Private parameters:
    int * p_stamps;
    size_t p_numStamps;
    /// Comparator function used in qsort()
    static int comp( const void* p, const void* q) {return (*(int*)q - *(int*)p);}

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
    StampDispenser(const int* stampDenominations, size_t numStampDenominations)
    {
        // validate inputs
        assert(numStampDenominations > 0 && stampDenominations != nullptr); 
        // initialize parameters
        p_stamps = new int[numStampDenominations]; 
        p_numStamps = numStampDenominations;
        //check if the input denominations contain 1
        bool hasOne = false;
        for( size_t i = 0; i < numStampDenominations; i++ )
        {
            p_stamps[i] = stampDenominations[i];
            if( p_stamps[i] == 1 )
                hasOne = true;
        }        
        assert( hasOne );

        ///Sort the denominations in value descending order.
        qsort(p_stamps, p_numStamps, sizeof(int), this->comp);

    }
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
    int CalcNumStampsToFillRequest(int request)
    {
        int numStamp; // save the number of the stamps for return
        int lastUsed; // index of the last used stamp
        vector<int> stampUsed(request+1, 0); 
        vector<int> stampTrack(request+1, 0);
        for( int i = 1; i <= request; i++ )
        {
            ///Initialize the values for the variables in each iteration.
            numStamp = INT_MAX;
            lastUsed = 0;

            for (size_t j = 0; j < p_numStamps; j++)
            {
                if ( p_stamps[j] > i)
                    continue;
                if ( stampUsed[i - p_stamps[j]] + 1 < numStamp )
                {
                    numStamp = stampUsed[i - p_stamps[j]] + 1;
                    lastUsed = j;
                }
            }
            stampUsed[i] = numStamp;
            stampTrack[i] = p_stamps[lastUsed];        
        }
        return stampUsed[request];
    }
}; 

int main()
{
    int stampDenominations[] = {90, 30, 24, 10, 6, 2, 1};
    //int stampDenominations[] = {10,20,5, 2, 1};
    StampDispenser stampDispenser(stampDenominations, 7);
    assert(stampDispenser.CalcNumStampsToFillRequest(18) == 3);
    //cout << "The total number of stamps " << stampDispenser.CalcNumStampsToFillRequest(19) << endl;
    //cout << "The total number of stamps " << stampDispenser.CalcNumStampsToFillRequest(10) << endl;
    return 0;
}