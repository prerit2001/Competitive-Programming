/*https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769*/
-----------------------------------------------------------------------------------------
/*
	M1: Brute Force -> Graph
	O(n^2) time and O(n) space
	-> store for each pairs check if a know b
	-> traverse each element and check if ith person is celebrity or not
*/
	int findCelebrity(int n) {
	    vector<int> indegree(n), outdegree(n);
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(knows(i, j)) {
	                indegree[j]++;
	                outdegree[i]++;
	            }
	        }
	    }
	    int celebrity = -1;
	    for(int i = 0; i < n; i++) {
	        if(indegree[i] == n - 1 && outdegree[i] == 0) {
	            celebrity = i;
	            break;
	        }
	    }
	    return celebrity;
	}
-----------------------------------------------------------------------------------------
/*
	M2: Brute force but without any store just blindly check if the ith person is celebrity
	O(n^2) time and O(1) space
*/		
	int findCelebrity(int n) {
	    int celebrity = -1;
	    for(int i = 0; i < n; i++) {
	        bool knowAny = false, knownToAll = true;
	        for(int j = 0; j < n; j++) {
	            if(knows(i, j)) {
	                knowAny = true;
	                break;
	            }
	        }
	        for(int j = 0; j < n; j++) {
	            if(i != j and !knows(j, i)) {
	                knownToAll = false;
	                break;
	            }
	        }
	        if(!knowAny && knownToAll) {
	            celebrity = i;
	            break;
	        }
	    }
	    return celebrity;
	}
-----------------------------------------------------------------------------------------
/*
	M3: Stack
	O(n) time and O(n) space
	Algorithm is as follows:

	->	Create a stack and push all ids in it.
	->	Run a loop while there are more than one element in the stack and in each iteration do the following-:
	->	Pop two elements from the stack, let these elements be ‘id1’ and ‘id2’.
	->	If the person with ‘id1’ knows the person with ‘id2’  i.e ‘knows(id1, id2)’ return true, then the person with ‘id1’ cannot be a celebrity, so push ‘id2’ in the stack.
	->	Otherwise, if the person with ‘id1’ doesn't know the person with ‘id2’  i.e knows(id1, id2) return false, then the person with ‘id2’ cannot be a celebrity, so push ‘id1’ in the stack.
	->	Only one id remains in the stack, you need to check whether the person having this id is a celebrity or not, this can be done by running two loops. One checks whether this person is known to everyone or not and another loop will check whether this person knows anyone or not.
	->	If this person is a celebrity return his id otherwise return -1.
*/
	int findCelebrity(int n) {

	    // Create a stack and push all ids in it.
	    stack<int> ids;
	    for(int i = 0; i < n; i++) {
	        ids.push(i);
	    }

	    // Finding celebrity.
	    while(ids.size() > 1) {
	        int id1 = ids.top();
	        ids.pop();
	        int id2 = ids.top();
	        ids.pop();
	        
	        if(knows(id1, id2)) {
	            // Because person with id1 can not be celebrity. 
	            ids.push(id2); 
	        }
	        else {
	            // Because person with id2 can not be celebrity.
	            ids.push(id1); 
	        }
	    }

	    int celebrity = ids.top();
	    bool knowAny = false, knownToAll = true;

	    // Verify whether the celebrity knows any other person.
	    for(int i = 0; i < n; i++) {
	        if(knows(celebrity, i)) {
	            knowAny = true;
	            break;
	        }
	    }

	    // Verify whether the celebrity is known to all the other person.
	    for(int i = 0; i < n; i++) {
	        if(i != celebrity and !knows(i, celebrity)) {
	            knownToAll = false;
	            break;
	        }
	    }

	    if(knowAny or !knownToAll) {
	        // If verificatin failed, then it means there is no celebrity at the party.
	        celebrity = -1;
	    }

	    return celebrity;
	}
/*
	M4: M3 Without Stack
	O(n) time and O(1) space
*/
	int findCelebrity(int n) {

	    int ids = 0;
	    for(int i = 1; i < n; i++) {
	        int id1 = ids;
	        int id2 = i;
	        if(knows(id1, id2)) {
	            // Because person with id1 can not be celebrity. 
	            ids = id2; 
	        }
	        else {
	            // Because person with id2 can not be celebrity.
	            ids = id1;
	        }
	    }

	    // Finding celebrity.
	    

	    int celebrity = ids;
	    bool knowAny = false, knownToAll = true;

	    // Verify whether the celebrity knows any other person.
	    for(int i = 0; i < n; i++) {
	        if(knows(celebrity, i)) {
	            knowAny = true;
	            break;
	        }
	    }

	    // Verify whether the celebrity is known to all the other person.
	    for(int i = 0; i < n; i++) {
	        if(i != celebrity and !knows(i, celebrity)) {
	            knownToAll = false;
	            break;
	        }
	    }

	    if(knowAny or !knownToAll) {
	        // If verificatin failed, then it means there is no celebrity at the party.
	        celebrity = -1;
	    }

	    return celebrity;
	}
-----------------------------------------------------------------------------------------