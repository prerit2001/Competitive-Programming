/*https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#*/
--------------------------------------------------------------------------------------
/*
	M1: Backtracking
	O(M^n) time and O(M) space 
*/
	#define pb push_back
	#define ll long long int
	vector<int>adj[50];
	int R;
	int M;
	int color[50]; //  it stores the color of the vertex.

	bool is_safe(ll src, ll c){
	    for(auto x: adj[src])
		    if(color[x]==c)
		    	return false;
	    return true;
	}

	bool solve(ll n) // here n is the vertex number
	{
	    if(n==R) // it means we filled all the vertices
		    return true;
	    for(int i=1;i<=M;i++) // we have color from 1 to M.
	    {
	        if(is_safe(n,i)) // here we try to fill the vertex n with color i
	        {
	            color[n]=i;
	            if(solve(n+1)) // increment the vertex count
	    	        return true;
	            
	            color[n]=-1;  // backtracking 
	        }
	    }
	    return false;
	}

	bool graphColoring(bool graph[101][101], int m, int V) {   
	    for(int i=0;i<V;i++)
	    adj[i].clear();
	    R=V; M=m;
	    memset(color,-1,sizeof(color)); // represents it is empty
	    for(int i=0;i<V;i++)
	    {
	        for(int j=0;j<V;j++)
	        {
	            if(graph[i][j]==1)
	            {
	                adj[i].pb(j);
	            }
	        }
	    }
	    
	    if(solve(0)) // if the vertex vecome V it means all the vertex are successfully filled
	    {
	        /*for(int i=0;i<V;i++)
	        cout<<color[i]<<" ";
	        cout<<"\n";*/
	        return true;
	    
	    }
	   
	    return false;
	}
--------------------------------------------------------------------------------------