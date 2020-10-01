#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n], b[n], c[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
        }
        int p = a[0];
        printf("%d ",a[0]);
      for(int i=1; i<n-1; i++)
      {
         if(p != a[i])
         {
            p = a[i];
            cout << p << " ";

         }
         else if(p != b[i])
         {
            p = b[i];
            cout << p << " ";
         }
         else if(p != c[i])
         {
            p = c[i];
            cout << p << " ";
         }
      }
         if(a[0] != a[n-1] && p != a[n-1])
         {
            p = a[n-1];
            cout << p << " ";

         }
         else if(a[0] != b[n-1] && p != b[n-1])
         {
            p = b[n-1];
            cout << p << " ";
         }
         else if(a[0] != c[n-1] && p != c[n-1])
         {
            p = c[n-1];
            cout << p << " ";
         }
      cout << "\n";
   }
   return 0;
}
