           /* GIVEN AN ARRAY = [1,1,2,1,1] K=3
            AND UR TASK IS TO COUNT NO OF SUBARRAYS WHERE THE COUNT OF ODD INTEGERS EXACTLY EQUAL TO THE GIVEN K
            
            EXAMPLE : ARRAY = [1,1,2,1,1] K=3
                        TAKEN [1,2,1]  SUBARRAY
                        ODD 2
                        EVEN 1
                        NOT POSSIBLE SUBARRAY
                    
                        TAKEN [1,1,2,1] SUBARRAY
                        ODD 3
                        EVEN 1
                        POSSIBLE SUBARRAY
                        
                        AND [1,2,1,1] ALSO POSSIBLE
                        
                        TOTAL ANSWER IS 2
                        
******IMP
                     
HERE WE ARE LINKING THIS PROBLEM WITH PREVIOUS (BINARY SUBARRAY WITH SUM)

THE IDEA IS CONVERTING ALL ODDS WITH 1
                       ALL EVENS WITH 0
                       
 EXAMPLE : [1,1,2,1,1]  ->  [1,1,0,1,1]*/
 
 int binarysubarraywithsum(int a[],int goal,int n)
{
	if(goal<0)               //WHY THIS CONDITION IS IF THE GOAL IS 0 THEN FOR GOAL-1 -> GOAL IS -1 ,-1 NOT POSSIBLE SO RETURN 0
	{
		return 0;
	}
	int l=0,r=0,sum=0,count=0;
	while(r<n)
	{
		sum=sum+a[r];
		while(sum>goal)
		{
			sum=sum-a[l];
			l++;
		}
		count=count+(r-l+1);
		r++;
	}
	return count;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,goal,count=0;
	cin>>n>>goal;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%2==0)
		{
			a[i]=0;
		}
		else
		{
			a[i]=1;
		}
	}
	cout<<binarysubarraywithsum(a,goal,n)-binarysubarraywithsum(a,goal-1,n)<<endl;
	return 0;
}                  
                       
