#include<stdio.h>
int max(int a,int b)
{
 int c=a>b?a:b;
 return c;
}
int knapsack(int p[],int w[],int n,int mw)
{
 if(n==0||mw==0)
 {
  return 0;
 }
 if(w[n-1]<=mw)
 {
  return max(p[n-1]+knapsack(p,w,n-1,mw-w[n-1]),knapsack(p,w,n-1,mw));
 }
 else
 {
  return knapsack(p,w,n-1,mw);
 }
}
int main()
{
 int w[20];
 int p[20];
 int i,W,n;
 int profit;
 printf("Enter the total number of items\n");
 scanf("%d",&n);
 printf("Enter the weight of the items\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&w[i]);
 }
 printf("Enter the profits of the items\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&p[i]);
 }
 printf("Enter the maximum weight\n");
 scanf("%d",&W);
 profit=knapsack(p,w,n,W);
 printf("The maximum profit is %d",profit);
 return 0;
}
