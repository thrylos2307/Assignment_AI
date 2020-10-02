#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,k,l,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>l;
        int ar[k+1];
    int pos[n+1]={0};
         if(k*l<n)
         cout<<-1;
         else if(k==1 && n>k)
         {
             cout<<-1;
         }
         
         else
         {
             
             for(int i=0;i<k+1;i++)
             {
                    ar[i]=l;
             }
             int j=0;
             for(int i=1;i<=n;i++)
             {
                   j=j%k;
                   if(ar[j+1]==0)
                   while(ar[j+1]==0)
                   {
                         j++;
                         j=j%k;
                   }
                   pos[i]=j+1;
                   ar[j+1]--;

                 j++;
             }
             for(int i=1;i<=n;i++)
         cout<<pos[i]<<" ";


         }
        cout<<"\n";         
         
    }
}
