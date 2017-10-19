#include <bits/stdc++.h>
using namespace std;

// Vector to contain coordinates x and y.
vector < pair <int,int> > node;	

// Matrix to calculate the cost. 
// We follow a top down approach starting and travel in reverse from home to office.
int dp[12][1 << 11];

// Global integer declared to hold number of customers
int n;

// Function to calculate the cost from office to home visiting all the customers
// It starts from home-> last customer -> second last customer -> ..... -> office. 
// One can also start from the reverse. 
// Time complexity is very high maybe to the order of 10!
// It needs to check all the possibilities in shortest time. 

int calc(int current_node, int visited_node_mask){

	// Base Case 
	// if current_node == 0 && visited_node_mask == 0 it means we have visited all the nodes and are at home. 
	// Therefore return 1e9 (10 to the power 9) <- Maximum possible value.
	// but if only current_node == 0 then we have reached the office without going through all the customers therefore
	// return the MAX value as it is not the correct step or a step to solution
	if(current_node==0 && visited_node_mask==0)
		return 0;
	else if(current_node==0)
		return 1e9;

	// if the matrix value at this particular point is not -1 then we have already visited the matrix and calculated the minimum value
	// therefore to save time we return the current value of the particular point. 
	if(dp[current_node][visited_node_mask]!=-1)
		return dp[current_node][visited_node_mask];

	// If we are visiting the current position in matrix for the first time
	// Initialize it as the MAX value of INT.
	// Ideally all the INT in program should be LONG LONG INT 
	dp[current_node][visited_node_mask]=1e9;
	
	// We start iterating from last node to office
	// This for loop helps in recursing through all the possibilites. 
	for(int i=n;i>=0;i--){

		// This helps checks whether we have visited a node or not
		// For example if visitednodemask = 11111011111 and i = 4 therefore (1<<i)=10000
		// If we AND both the values we get a value greater than zero
		// but if i=5 then 1<<i = 100000 
		// 11111011111
	//	AND00000100000
	//		00000000000 <- Gives a complete zero value, it means we have already visited the node therefore we will not go forward.
		if(visited_node_mask & (1<<i)){
			// Calculates the dist between 2 nodes
			int dist =abs(node.at(current_node).first - node.at(i).first) + abs(node.at(current_node).second - node.at(i).second);
			// Recursively calls the calc fucntion and appends the current distance. 
			dp[current_node][visited_node_mask]=min(dp[current_node][visited_node_mask],calc(i,visited_node_mask ^ (1<<i)) + dist);
		}
	}

	// returns the value after recursion is complete
	return dp[current_node][visited_node_mask];

}

int main(){

	int x,y;
	// temporary variable to store the second coordinate
	pair<int,int> coord;
	// loop for 10 test cases
	for(int t=0;t<10;t++){
		cin>>n;
		// Coordinate of Office
		cin>>x>>y;
		node.push_back(make_pair(x,y));
		
		// Coordinate of Home
		cin>>x>>y;
		
		// Coordinate of home is temporarily stored in PAIR
		coord=make_pair(x,y);

		for(int i=0;i<n;i++){
			cin>>x>>y;
			node.push_back(make_pair(x,y));
		}
		// Mask is created for N+1 nodes.
		int visited_node_mask = (1<<(n+1)) - 1;

		// Home node is pushed into the vector
		node.push_back(coord);
		
		// Matrix is assigned to -1 else garbage value pop up. 
		memset(dp,-1,sizeof(dp));

		// Function is called.
		cout<<"#"<<t+1<<" "<<calc(n+1,visited_node_mask)<<endl;
		
		// vector is cleared for next test case. else may result in wrong value
		node.clear();
	}


	return 0;
}