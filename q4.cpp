
#include<iostream>

using namespace std;


int * final_bill_board ;
			
int maxBoard(int * a ,int s,int temp){

	int max = 0;
	int index = 0;
	for (int i = 0; i < s; ++i)			//		function used to find max bill board 
										//		on the basis of its revenue
	{									//		( based on knapsack problem )
		if(max < a[i])					//
		{								
			max = a[i];					
			index = i;
		}
	}
	if(temp == 0)
		return max;
	else
	
		return index;
	
}


int calculateRevenue(int *bill_board, int *revenue,int n,int t,int m){
	
	int max_revenue = 0;							//
	int selected_bill_board = 0;					//		function used to find and calculate 
	int present_bill_board;							//		possible and optimal revenue for the
	for (int i = 0; i < n; ++i)						//		given problem
	{												//
			int *possibleBoards,*revenueCanHave;
			possibleBoards = new int [n-(i+1)];
			revenueCanHave = new int [n-(i+1)];
			final_bill_board = new int [n-(i+1)]; 
	
			present_bill_board = i;
			possibleBoards[0] = bill_board[i];
			revenueCanHave[0] = revenue[i]; 
			int k = 1;
			for (int j = i+1; j < n; ++j)
			{
				// checking the distane contraints with every pair or bill boards
				if( ( bill_board[i] -  bill_board[j] > t ) || ( bill_board[j] -  bill_board[i] > t ) )
				{
						possibleBoards[k] = bill_board[j];
						revenueCanHave[k] = revenue[j];
						k++;
				}

			}

	//		for (int l = 0; l < n-(i+1); ++l)
	//		{
	//			cout<<" NEW "<<l+1<<"	"<<possibleBoards[l]<<"	"<<revenueCanHave[l]<<" NEW ";
	//		}
			int r=0;
			while ( selected_bill_board + possibleBoards[maxBoard(revenueCanHave,n-(i+1),1)]  <= m ){
					int index = maxBoard(revenueCanHave,n-(i+1),1);
					selected_bill_board = selected_bill_board+possibleBoards[index];
					final_bill_board[r] = possibleBoards[index]; 		
					max_revenue  = max_revenue + revenueCanHave[index];
					possibleBoards[index] = 0;
					revenueCanHave[index] = 0;
					r++;
			}
			cout<<"\n";
	}

return max_revenue;
}


int  main(){
	int n,m;
	int *bill_board,*revenue;
	cout<<"\nEnter length of highway : ";
	cin>>m;
	cout<<"\nAssuming minimum distance between bill board is 5";
	int t = 5;
	cout<<"\nEnter no. of bill boards : ";
	cin>>n;
	bill_board = new int[n];
	revenue = new int[n];
	cout<<"Enter details : ";
	cout<<"\nS.no   Bill_Board  Revenue \n";
	for (int i = 0; i < n; ++i)
	{
		cout<<i+1<<"\t ";cin>>bill_board[i];cout<<"\t ";cin>>revenue[i];cout<<"\n";
	}
	int temp = calculateRevenue(bill_board,revenue,n,t,m);
	cout<<"\nMax Revenue : "<<temp<<"\n";	return 0;
}
