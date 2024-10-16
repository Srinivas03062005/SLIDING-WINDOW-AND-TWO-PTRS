                    /* S=BBACBA 
                       STRING CONTAINS ONLY A B C*/

                                //BRUTE FORCE
                        
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int count=0;
	for(int i=0;i<s.size();i++)
	{
		int hash[3]={0};  // every time reinitialized to 0's
		for(int j=i;j<s.size();j++)
		{
			hash[s[j]-'a']=1;
			if(hash[0]+hash[1]+hash[2]==3)
			{
				count=count+1;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
TC IS O(N*N)
SC IS O(1)
*/



                                 //BETTER BRUTE FORCE
                                 
                           /*FOR SOME TESTCASES IT IS BETTER 
						   BUT FOR WORST TEST CASE AS IT IS SAME
                           EXAMPLE: AAAAAAAAAAAAAAAAAAAA*/
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int count=0;
	for(int i=0;i<s.size();i++)
	{
		int hash[3]={0};  // every time reinitialized to 0's
		for(int j=i;j<s.size();j++)
		{
			hash[s[j]-'a']=1;
			if(hash[0]+hash[1]+hash[2]==3)
			{
				count=count+(s.size()-j);             IF FOUND THEN NOT TRAVERSING ENTIRE,JUST DOING   SIZE-J 
				                                      THATS IT WE WILL GET ALL WITH THAT CHARACTER 
				break;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}*/

                                //OPTIMAL
                 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int lastseen[3]={-1,-1,-1};         //NOT {-1}    IF IT IS THEN -1 0 0 
	int count=0;
	for(int i=0;i<s.size();i++)
	{
		lastseen[s[i]-'a']=i;
		if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1)
		{
			int a=min(lastseen[0],lastseen[1]);
			count=count+(1+min(a,lastseen[2]));
		}
	}
	cout<<count<<endl;
	return 0;
}
TC IS O(N)
SC IS O(1)

