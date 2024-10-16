/*  WILL BE GIVEN A STRING s AND A STRING t
    s=ddaaabbca t=abc
    AND WHAT WE HAVE TO DO IS
    MIN LENGTH SUBSTRING IN s THAT CONTAINS ALL THE CHARACTERS IN t
    
    EXAMPLE :  s=ddaaabbca t=abc
               daaa  NOT POSSIBLE
               aabbc POSSIBLE
               bca  POSSIBLE
               
               
               s=ddaaabbca t=abbc
               bca NOT POSSIBLE
               abbc POSSIBLE
               
THE IDEA IS TAKE A MAP DATA STRUCTURE
AND SEND ALL THE t  STRING CHARACTERS INTO IT 
AND TRAVERSE THE STRING s IF THE CHARACTER IN s NOT IN THE MAP THEN 
MAP[CHAR]-- IT
OTHERWISE IF IT IS THERE THEN (HOW U KNOW IF (FREQUENCY>0)) MAP[CHAR]--
AND COUNT++  
IF THE TAKEN CHARACTER FROM STRING  s  IS THERE IN MAP BUT IT IS NEGATIVE SO DONT COUNT++   *****
BUT MAP[CHAR]--        */


/*#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s,t;
   cin>>s>>t;
   int minlen=INT_MAX;
   int sindex=-1;
   for(int i=0;i<s.size();i++)
   {
   	  int hash[256]={0},count=0;
      for(int j=0;j<t.size();j++)
      {
      	hash[t[j]]++;
	  }
	  for(int j=i;j<s.size();j++)
	  {
	  	if(hash[s[j]]>0)
	  	{
	  		count++;
		}
		hash[s[j]]--;
		if(count==t.size())
		{
			if(j-i+1<minlen)
			{
				minlen=j-i+1;
				sindex=i;
				break;
			}
		}
	  }
   }
   //cout<<sindex<<" "<<minlen<<endl;
   for(int i=sindex;i<sindex+minlen;i++)
   {
   	  cout<<s[i];
   }
   return 0;
}     */

/*TC IS O(N*N)
SC IS O(256)*/



                                     //OPTIMAL
									 
#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s,t;
   cin>>s>>t;
   int hash[256]={0};
   int l=0,r=0,minlen=INT_MAX,sindex=-1,count=0;
   for(int i=0;i<t.size();i++)
   {
   	  hash[t[i]]++;
   }
   while(r<s.size())
   {
   	  if(hash[s[r]]>0)
   	  {
   	  	  count++;
	  }
	  hash[s[r]]--;
	  while(count==t.size())
	  {
	  	if(r-l+1<minlen)
	  	{
	  		minlen=r-l+1;
	  		sindex=l;
		}
		hash[s[l]]++;
		if(hash[s[l]]>0)
		{
			count--;
		}                                                 
		l++;
	  }
	  r++;
   }
   for(int i=sindex;i<sindex+minlen;i++)
   {
   	  cout<<s[i];
   }
   return 0;
}    									 
//s=ddaaabbca t=abc	
								 
									     
