

                  /*WE HAVE TO PICKUP THE ELEMENTS CONSECUTIVELY NOT BY RANDOM
                  AND   FROM THE FIRST OR FROM THE END ONLY AND BY FIRST AND LAST NOT BY MIDDLE*/

                  /*ARRAY 6 2 3 4 7 2 1 7 1
                  6 2 3 4
                  6 2 3                 1
                  6 2                 7 1
                  6                 1 7 1
                                  2 1 7 1
                  LSUM                RSUM           SUM
                  15                   0             15
                  11                   1             12
                  8                    8             16
                  6                    9             15
                  0                   11             11*/
                  
#include<iostream>
using namespace std;

int maxpoints(int a[],int k,int n)
{
	int lsum=0,rsum=0,maxsum=0;
	for(int i=0;i<=k-1;i++)
	{
		lsum=lsum+a[i];
	}
	maxsum=lsum;
	int rindex=n-1;
	for(int i=k-1;i>=0;i--)
	{
		lsum=lsum-a[i];
		rsum=rsum+a[rindex];
		rindex=rindex-1;
		maxsum=max(maxsum,lsum+rsum);
	}
	
	return maxsum;	
}
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int z=maxpoints(a,k,n);
	cout<<z;
	return 0;
}
