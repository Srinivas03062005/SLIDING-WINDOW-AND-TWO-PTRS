/*GIVEN AN ARRAY WHICH CONTAINS 1 AND 0
AND U WILL BE GIVEN AN INTEGER K 
AND U ARE ALLOWED TO FLIP ATMOST K ZEROS TO ONES*/

/*MAX CONSECUTIVE ONES / LONGEST SUBARRAY WITH AT MOST K ZEROS

ARR[]=[1,1,1,0,0,0,1,1,1,1,0]
K=2
*/
                                     //BRUTE FORCE
                                     
/*#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	int maxlen=0;
	for(int i=0;i<n;i++)
	{
		int zeros=0;
		for(int j=i;j<n;j++)
		{
			if(a[j]==0)
			{
				zeros++;
			}
			if(zeros<=k)
			{
				int len=j-i+1;
				maxlen=max(maxlen,len);
			}
			else
			{
				break;
			}
		}
	}
	cout<<maxlen<<endl;
	return 0;
}
TC IS 0(N^2)
SC IS 0(1)*/

                         
                         //BETTER

/*#include<iostream>
using namespace std;
int max(int a[],int k,int n)
{
	int maxlen=0,l=0,r=0,zeros=0;
	while(r<n)
	{
		if(a[r]==0)
		{
			zeros++;
		}
		while(zeros>k)
		{
			if(a[l]==0)
			{
				zeros--;
			}
			l++;
		}
		if(zeros<=k)
		{
			int len=r-l+1;
			maxlen=max(maxlen,len);
		}
		r++;
	}
	return  maxlen;
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
	int ans=max(a,k,n);
	cout<<ans<<endl;
	return 0;
}*/

/*TC IS O(N+N)
SC IS 0(1)
*/

                           //OPTIMAL
            

#include<iostream>
using namespace std;
int max(int a[],int k,int n)
{
	int maxlen=0,l=0,r=0,zeros=0;
	while(r<n)
	{
		if(a[r]==0)
		{
			zeros++;
		}
		if(zeros>k)
		{
			if(a[l]==0)
			{
				zeros--;
			}
			l++;
		}
		if(zeros<=k)
		{
			int len=r-l+1;
			maxlen=max(maxlen,len);
		}
		r++;
	}
	return  maxlen;
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
	int ans=max(a,k,n);
	cout<<ans<<endl;
	return 0;
}
/*TC IS O(N)
SC IS 0(1)*/




