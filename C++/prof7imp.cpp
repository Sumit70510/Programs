//Back-end complete function template for C++

class Solution{
public:
	// Similar to standard partition method. Here we pass the pivot element
	// too instead of choosing it inside the method.
	int partition(char arr[], int low, int high, char pivot) {
	    int i = low;
	    char temp1, temp2;
	    for (int j = low; j < high; j++) {
	        if (arr[j] < pivot) {
	            temp1 = arr[i];
	            arr[i] = arr[j];
	            arr[j] = temp1;
	            i++;
	        } else if (arr[j] == pivot) {
	            temp1 = arr[j];
	            arr[j] = arr[high];
	            arr[high] = temp1;
	            j--;
	        }
	    }
	    temp2 = arr[i];
	    arr[i] = arr[high];
	    arr[high] = temp2;

	    // Return the partition index of an array based on the pivot
	    // element of other array.
	    return i;
	}
public:
	// Method which works just like quick sort
	void matchPairsUtil(char *nuts, char *bolts, int low, int high) {
	    if (low < high) {
	        // Choose last character of bolts array for nuts partition.
	        int pivot = partition(nuts, low, high, bolts[high]);

	        // Now using the partition of nuts choose that for bolts
	        // partition.
	        partition(bolts, low, high, nuts[pivot]);

	        // Recur for [low...pivot-1] & [pivot+1...high] for nuts and
	        // bolts array.
	        matchPairsUtil(nuts, bolts, low, pivot - 1);
	        matchPairsUtil(nuts, bolts, pivot + 1, high);
	    }
	}
public:
	void matchPairs(char nuts[], char bolts[], int n) {
	    matchPairsUtil(nuts, bolts, 0, n - 1);
	}

};
