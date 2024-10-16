                   
				   
				   
				   
				   
				                                 //SLIDING WINDOW




//1.CONSTANT WINDOW
//  7 4
//  1 2 3 3 4 5 1
//  1 2 3 3     2 3 3 4     3 3 4 5     3 4 5 1


/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,r;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	l=0;
	r=k-1;
	int maxsum=INT_MIN,sum=0;
	for(int i=l;i<=r;i++)
	{
		sum=sum+a[i];
	}
	maxsum=max(maxsum,sum);
	while(r<n-1)
	{
		sum=sum-a[l];
		l++;
		r++;
		sum=sum+a[r];
		maxsum=max(maxsum,sum);
	}
	cout<<maxsum<<endl;
	return 0;
}*/


//2.LONGEST SUBARRAY/SUBSTRING   WHERE <CONDITION>


/*LONGEST SUBARRAY WITH SUM<=K
ARR=[2,5,1,7,10]  K=14
2 5 1 7    SUM>K   SO NO
5 1 7 10   SUM>K   SO NO
2 5 1      SUM<=K  AND 3 IS THE LONGEST SO YES
5 1 7      SUM<=K  AND 3 IS THE LONGEST SO YES
1 7 10     SUM>K   SO NO*/


/*GENERATING ALL THE POSSIBLE SUBARRAYS 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				cout<<a[k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}*/

//BRUTE FORCE
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	int sum=0,maxlen=0;
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=i;j<n;j++)
		{
			sum=0;
			for(int k=i;k<=j;k++)
			{
				sum=sum+a[k];
				if(sum<=target)
				{
					maxlen=max(maxlen,k-i+1);
				}
				else if(sum>target)
				{
					break;
				}
			}
		}
	}
	cout<<maxlen<<endl;
	return 0;
}*/


//BETTER

//USING r EXPAND
//USING l SHRINK

/*FIRST BOTH WILL POINT TO THE FIRST INDEX AND GOES ON USING r
IF AT ANY INDEX SUM > THE CONDITION THEN DO l++*/

/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	int sum=0,maxlen=0,l=0,r=0;
	while(r<n)
	{
		sum=sum+a[r];
		while(sum>target)
		{
			sum=sum-a[l];
			l=l+1;
		}
		if(sum<=target)
		{
			maxlen=max(maxlen,r-l+1);
		}
		r=r+1;
	}
	cout<<maxlen<<endl;
	return 0;
}*/              //TC IS 0(N+N)



//OPTIMAL        //TC IS 0(N);

/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	int sum=0,maxlen=0,l=0,r=0;
	while(r<n)
	{
		sum=sum+a[r];
		if(sum>target)
		{
			sum=sum-a[l];
			l=l+1;
		}
		if(sum<=target)
		{
			maxlen=max(maxlen,r-l+1);
		}
		r=r+1;
	}
	cout<<maxlen<<endl;
	return 0;
}*/

//3.NO OF SUB ARRAYS WHERE  <CONDITION>
//4.SHORTEST/MINIMUM  WINDOW/LENGTH   <CONDITION>

















