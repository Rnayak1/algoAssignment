#include <bits/stdc++.h> 
	using namespace std; 
	  
	

	int maximumProfit(int price[],n) 
	{ 
	     
		 int buy = 0;   
		 int sell = 1; 
		 int temp = 0;
	   int MaxProfit = price[1] - price[0]; 
	   int BuyDay = price[0]; 
	   for(int i = 1; i < size; i++) 
	   {   
	   		//compare current maximum difference with difference of each day's price with minimum      
	     	if (price[i] - BuyDay > MaxProfit)                         
	        {
	       		MaxProfit = price[i] - BuyDay;
	       		buy = temp;    
	       		sell = i;     
	        }
	        //updates BuyDay if a price less than current min price is found
	        if (price[i] < BuyDay) 
	        {
	       		BuyDay = price[i];
	       		temp = i;
	        }                      
	    }
	     if(MaxProfit < 1)
	     {
	     	cout<<"\n\n No Maximum profit found!!";
	     }
	     else
	     {
	     	cout<<"\n\nBuy Day: "<<buy+1<<",Sell Day:  "<<sell+1;
	     } 
	     
	     cout<<"\n";  
	     return MaxProfit; 
	}  
	  
	/* Driver program to test above function */
	int main() 
	{ 
	  int size;
	  
	  
	  cout << "Enter Number of consecutive days: ";
	  cin >> size;
	  int price[size];
	  cout<<"\nEnter Price per share for the stock \n";
	  for(int i=0;i < size;i++)
	  {
	  	cout<<"Enter price [ "<<i+1<<" ] : ";
	  	cin>>price[i];
	  }
	

	    
	  int profit = maximumProfit(price,size);
	  if(profit > 0)
	  	cout << "\nMaximum money earned " << profit;
	  
	  cout<<endl;
	  return 0; 
}


	  /*
	    Time Complexity:
	     line 17-29 runs n time that is number of days
	     therefore,T(n)=O(n) 
--------------------------------------------------
Member 1 = Rohit Nayak
	  */
