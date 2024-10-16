            /*S=AABABBA   K=2
            GIVEN A STRING WHICH WILL HAVE ALL THE UPPERCASE LETTERS 
            AND AN INTEGER K 
		    K SIGNIFIES THAT WE CAN TAKE ATMOST K CHARACTERS FROM THE GIVEN STRING AND WE CAN CONVERT THEM INTO ANY UPPER CASE LETTERS 
		    AFTER THAT WE HAVE TO FINDOUT LONGEST SUBSTRING  WHICH HAS ALL THE CHARACTERS EQUAL*/
		    
		    
		    
		                                        //BRUTE FORCE
		                                        
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int k,maxans=0,maxlen=0;
	cin>>s>>k;
	for(int i=0;i<s.size();i++)
	{
		int hash[26]={0};
		for(int j=i;j<s.size();j++)
		{
			hash[s[j]-'A']++;
			maxans=max(maxans,hash[s[j]-'A']);
			int changes=(j-i+1)-maxans;
			if(changes<=k)
			{
				maxlen=max(maxlen,j-i+1);
			}
			else
			{
				break;
			}
		}
	}
	cout<<maxlen<<endl;
	return 0;
}*/

/*TC IS O(N*N)
SC IS O(26)*/

            
            
                                                  //BETTER
												  
												  
            
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int k;
	cin>>s>>k;
	int l=0,r=0,maxlen=0,maxfrequency=0;
	int hash[26]={0};
	while(r<s.size())
	{
		hash[s[r]-'A']++;
		maxfrequency=max(maxfrequency,hash[s[r]-'A']);
		while( ((r-l+1)-maxfrequency) >k)
		{
			hash[s[l]-'A']--;
			maxfrequency=0;
			for(int i=0;i<26;i++)
			{
				maxfrequency=max(maxfrequency,hash[i]);
			}
			l++;
		}
		if( ((r-l+1)-maxfrequency) <=k)
		{
			 maxlen=max(maxlen,r-l+1);
		}
		r++;
	}
	cout<<maxlen<<endl;
	return 0;
}         */  
   
/*TC IS O((N+N)*26)
SC IS O(26)*/

                                                     
                                            //OPTIMAL
											
											
											
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int k;
	cin>>s>>k;
	int l=0,r=0,maxlen=0,maxfrequency=0;
	int hash[26]={0};
	while(r<s.size())
	{
		hash[s[r]-'A']++;                                              //AAABBCCD   K=2 
		maxfrequency=max(maxfrequency,hash[s[r]-'A']);
		if( ((r-l+1)-maxfrequency) >k)
		{
			hash[s[l]-'A']--;
			l++;
		}
		if( ((r-l+1)-maxfrequency) <=k)
		{
			 maxlen=max(maxlen,r-l+1);
		}
		r++;
	}
	cout<<maxlen<<endl;
	return 0;
}        

/*TC IS O(N)
SC IS O(26)*/
 										

