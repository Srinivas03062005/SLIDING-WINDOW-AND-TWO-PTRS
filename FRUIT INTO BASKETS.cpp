
/*PROBLEM STATEMENT: U GO TO A FARM AND U GIVEN TWO BASKETS AND IN THE FARM THERE ARE TREES
                   AND THESE ARE FRUITS THAT THEY PRODUCED 
                   ARR[]=[3,3,3,1,2,1,1,2,3,3,4]
                   TREE 0 PRODUCES TYPE 3 FRUITS 
                   TREE 1 PRODUCES TYPE 3 FRUITS
                   TREE 2 PRODUCES TYPE 3 FRUITS                        |       |     |       |
                   TREE 3 PRODUCES TYPE 1 FRUITS                        |       |     |       |
                   TREE 4 PRODUCES TYPE 2 FRUITS                        |_______|     |_______|
                   AND U ARE ALLOWED TO COLLECT FRUITS
                   BUT THERE IS A CONDITION
                   IN EACH INDIVIDUAL BASKET CAN HOLD ONLY SINGLE TYPE
                   BY USING THESE 2 BASKETS WHAT IS THE MAXIMUM FRUITS U CAN TAKE?


FRUIT INTO BASKET/ MAX LENGTH SUBARRAY WITH ATMOST 2 TYPES OF FRUITS*/


                                    //BRUTE FORCE
                                    
/*#include<bits/stdc++.h>
using namespace std;
int fruit(int a[],int n)
{
	int maxlen=0;
	for(int i=0;i<n;i++)
	{
		set<int> st;
		for(int j=i;j<n;j++)
		{
			st.insert(a[j]);
			if(st.size()<=2)
			{
				int len=j-i+1;
				maxlen=max(maxlen,len); 
			}
			if(st.size()>2)
			{
				break;
			}
		}
	}
	return maxlen;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=fruit(a,n);
	cout<<ans<<endl;
	return 0;
}
TC IS O(N*N)  
AND IN THE SECOND LOOP WE ARE USING SET DATA STRUCTURE
THAT USES O(logN) N IS SIZE OF THE SET  AND THAT IS MAX 3 ONLY
SO CONSTANT TIME ONLY 

SC IS 0(3) ->   O(1)
*/
                
                                //BETTER
                
/*#include<bits/stdc++.h>
using namespace std;
int fruit(int a[],int n)
{
	int maxlen=0,l=0,r=0;
	map<int,int> mp;
	while(r<n)
	{
		mp[a[r]]++;
		if(mp.size()>2)
		{
			while(mp.size()>2)
			{
				mp[a[l]]--;
				if(mp[a[l]]==0)
				{
					mp.erase(a[l]);
				}
				l++;
			}
		}
		if(mp.size()<=2)
		{
			maxlen=max(maxlen,r-l+1);
		}
		r++;
	}
	return maxlen;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=fruit(a,n);
	cout<<ans<<endl;
	return 0;
}
TC IS O(N+N)
SC IS O(3)  ->   O(1)
*/

                      //OPTIMAL
                      

#include<bits/stdc++.h>
using namespace std;
int fruit(int a[],int n)
{
	int maxlen=0,l=0,r=0;
	map<int,int> mp;
	while(r<n)
	{
		mp[a[r]]++;
		if(mp.size()>2)
			{
				mp[a[l]]--;
				if(mp[a[l]]==0)
				{
					mp.erase(a[l]);
				}
				l++;
			}
		if(mp.size()<=2)
		{
			maxlen=max(maxlen,r-l+1);
		}
		r++;
	}
	return maxlen;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=fruit(a,n);
	cout<<ans<<endl;
	return 0;
}
TC IS O(N)
SC IS 0(1)

 

