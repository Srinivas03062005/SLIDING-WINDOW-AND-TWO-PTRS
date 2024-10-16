                        /*  ARR = [1,2,1,3,4] K = 3
                          [1,2,1] TWO DIFF NOT POSSIBLE
                          [2,1,3,4]  FOUR DIFF NOT POSSIBLE
                          [2,1,3]  3 DIFF POSSIBLE
                          [1,3,4] 3 DIFF POSSIBLE
                          [1,2,1,3] 3 DIFF POSSIBLE*/



                                           //BRUTE FORCE
                                           

/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,count=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		map<int,int> mp;              //REINITIALIZED EVERY TIME
		for(int j=i;j<n;j++)
		{
			mp[a[j]]++;
			if(mp.size()==k)
			{
				count++;
			}
			else if(mp.size()>k)
			{
				break;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}*/

/*TC IS O(N*N)
SC IS O(N)*/


/*ARR = [2,1,1,1,3,4,3,2] K = 3

WE DONT KNOW WHETHER TO MOVE L OR R 
WE ARE MISSING SOME SUBARRAYS 

SO.......

BEFORE PROBLEM ALSO SAMETHING HAPPENED SO APPLY SAME HERE ALSO

               SUBARRAY WITH K DIFFERENT INTEGERS / NO OF SUBARRAYS WHERE DIFF INTEGERS <= K*/
               
               
               
  // <=K - <=K-1
  
        
               
               
#include<bits/stdc++.h>
using namespace std;
int kdiff(int a[],int k,int n)
{
	int count=0,l=0,r=0;
	map<int,int> mp;
	while(r<n)
	{
		mp[a[r]]++;
		while(mp.size()>k)
		{
			mp[a[l]]--;
			if(mp[a[l]]==0)
			{
				mp.erase(a[l]);
			}
			l++;
		}
		count=count+(r-l+1);
		r++;
	}
	return count;
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
	cout<<kdiff(a,k,n)-kdiff(a,k-1,n)<<endl;
	return 0;
}
TC IS O(N+N) CALLING TWO TIMES SO O(2*(N+N))
SC IS O(N)

               


