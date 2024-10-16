            /*  S=AAABBCCD   K=2
              ABBC   NOT POSSIBLE IT CONTAINS 3   A B C
              AAABB  POSSIBLE IT CONTAINS 2 ONLY  A B*/
            
            
                               //BRUTE FORCE
/*#include<bits/stdc++.h>
using namespace std;
int longest(string s,int k)
{
	int maxlen=0;
	map<char,int> mp;
	for(int i=0;i<s.size();i++)
	{
		mp.clear();
		for(int j=i;j<s.size();j++)
		{
			mp[s[j]]++;
			if(mp.size()<=k)
			{
				maxlen=max(maxlen,j-i+1);
			}
			else
			{
				break;
			}
		}
	}
	return maxlen;
}
int main()
{
	string s;
	int k;
	cin>>s>>k;
	int ans=longest(s,k);
	cout<<ans<<endl;
	return 0;
}
TC IS O(N*N*log(256/26 BASED ON CHARACTERS WHAT WE ARE TAKING ))
SC IS O(256)
*/




                                         //BETTER
                                         
                                         
/*#include<bits/stdc++.h>
using namespace std;
int longest(string s,int k)
{
	int maxlen=0,l=0,r=0;
	map<char,int> mp;
	while(r<s.size())
	{
		mp[s[r]]++;
		if(mp.size()>k)
		{
			while(mp.size()>k)
			{
				mp[s[l]]--;
				if(mp[s[l]]==0)
				{
					mp.erase(s[l]);
				}
				l++;
			}
		}
		else
		{
			maxlen=max(maxlen,r-l+1);
		}
		r++;
	}
	return maxlen;
}
int main()
{
	string s;
	int k;
	cin>>s>>k;
	int ans=longest(s,k);
	cout<<ans<<endl;
	return 0;
}
TC IS O(N)+O(N)+O(log256)
SC IS O(256)*/

                            
                               //OPTIMAL
            
#include<bits/stdc++.h>
using namespace std;
int longest(string s,int k)
{
	int maxlen=0,l=0,r=0;
	map<char,int> mp;
	while(r<s.size())
	{
		mp[s[r]]++;
		if(mp.size()>k)
			{
				mp[s[l]]--;
				if(mp[s[l]]==0)
				{
					mp.erase(s[l]);
				}
				l++;
			}
		else
		{
			maxlen=max(maxlen,r-l+1);
		}
		r++;
	}
	return maxlen;
}
int main()
{
	string s;
	int k;
	cin>>s>>k;
	int ans=longest(s,k);
	cout<<ans<<endl;
	return 0;
}

              
