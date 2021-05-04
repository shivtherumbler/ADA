#include <bits/stdc++.h>

using namespace std;

struct item
{
    int value, weight;

};

bool comp(struct item a, struct item b)
{
    double a1 = (double)a.value / (double)a.weight;
    double a2 = (double)b.value / (double)b.weight;
    return a1 > a2;
}

double fractionalKnapsack(int W, struct item arr[], int n)
{

    sort(arr, arr + n, comp);


    for (int i = 0; i < n; i++)
    {
    	printf("\nValue  %d \nWeight %d\nValue/Weight %f", arr[i].value, arr[i].weight, ((double)arr[i].value / arr[i].weight));
    }

    int currentWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {

        if (currentWeight + arr[i].weight <= W)
        {
            currentWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            int remain = W - currentWeight;
            finalvalue += arr[i].value
                          * ((double)remain
                             / (double)arr[i].weight);
            break;
        }
    }


    return finalvalue;
}


int main()
{
    int W = 50;
    struct item arr[3] = { { 30, 10 }, { 100, 20 }, { 120, 30 } };

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nMaximum value we can obtain = %f", fractionalKnapsack(W, arr, n));
    return 0;
}
