                  
				              // BINARY SUBARRAY WITH SUM / COUNT SUBARRAYS SUM EQUALS K
				               
				        
//ARR=[1,0,0,1,1,0] , GOAL=2
//OLD VIDEO OKATI CHUDAMANNARU BASED ON THIS


/*IF WE DO DIRECTLY FOR ==GOAL
WE CANNOT DO IT 
AND WE DONT KNOW WHETHER TO MOVE L OR R  SO NOT POSSIBLE*/

/*HERE THE IDEA IS
WE ARE FINDING SUBARRAYS WITH <=GOAL
THEN THAT CONATINS 
IF GOAL = 2 
0 1 2  SUM SUBARRAYS

AND FINALLY 
THAT     <= GOAL -  <=GOAL-1 (IF GOAL = 2 THEN SUBARRAYS WITH 0 AND 1 SUM SUBARRAYS WILL BE REMOVED)*/

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
	}
	cout<<binarysubarraywithsum(a,goal,n)-binarysubarraywithsum(a,goal-1,n)<<endl;
	return 0;
}

/* FOR TEST CASE 5 2
                 1 0 1 0 1
                 ANSWER IS 4
              */
/*TC IS O(N+N) AND WE ARE CALLING TWICE SO O(2*2N)
SC IS O(1)*/

