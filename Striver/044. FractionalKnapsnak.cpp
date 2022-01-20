/*https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1*/
-----------------------------------------------------------------------------------------
/*
	M1 : sort the item on basis of value / weight
	O(nlogn) time and O(1) space
*/
	// Structure for an item which stores weight and
	// corresponding value of Item
	struct Item {
	    int value, weight;
	    Item(int value, int weight)
	    {
	       this->value=value;
	       this->weight=weight;
	    }
	};

	bool cmp(struct Item a, struct Item b){
		return a.value * b.weight > a.weight * b.value;
	}

	double fractionalKnapsack(int W, struct Item arr[], int n){
	    sort(arr, arr + n, cmp);
	    int curWeight = 0; 
	    double finalvalue = 0.0;

	    for (int i = 0; i < n; i++) {
	        if (curWeight + arr[i].weight <= W) {
	            curWeight += arr[i].weight;
	            finalvalue += arr[i].value;
	        }
	        else {
	            int remain = W - curWeight;
	            finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
	            break;
	        }
	    }

	    // Returning final value
	    return finalvalue;
	}
-----------------------------------------------------------------------------------------