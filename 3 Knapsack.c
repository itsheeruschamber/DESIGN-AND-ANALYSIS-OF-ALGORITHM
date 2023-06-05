#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int weight;
    int value;
};
int cmpfunc(const void* a, const void* b)
 {
    struct Item* item1 = (struct Item*) a;
    struct Item* item2 = (struct Item*) b;
    double r1 = (double)item1->value / item1->weight;
    double r2 = (double)item2->value / item2->weight;
    if (r1 > r2)
        return -1;
    else if (r1 < r2)
        return 1;
    else
        return 0;
}
double fractionalKnapsack(int W, struct Item* items, int n) 
{
    qsort(items, n, sizeof(struct Item), cmpfunc);
    int i;
    double totalValue = 0.0;
    for (i = 0; i < n; i++)
    {
        if (W == 0)
            return totalValue;
        if (items[i].weight <= W)
        {
            totalValue += items[i].value;
            W -= items[i].weight;
        }
        else 
        {
            totalValue += items[i].value * ((double)W / items[i].weight);
            W = 0;
        }
    }
    return totalValue;
}
int main() 
{
    int n, i, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    struct Item items[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    double maxTotalValue = fractionalKnapsack(W, items, n);
    printf("The maximum total value for the given weight capacity is: %0.2lf\n", maxTotalValue);
    return 0;
}
