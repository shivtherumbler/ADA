#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int [], int, int, int);
void part(int [],int, int);

int main()
{
    int list[10000];
    int i, size=10000;
    time_t t1,t2;

    for(int i=0;i<10000;i++)
    {
        list[i] = rand()%10000;
        //printf(" %d ",list[i]);
    }
    t1= clock();
    part(list, 0, 9999);
    t2 = clock();

    //printf("Enter total number of elements:");
    //scanf("%d", &size);
    //printf("Enter the elements:\n");
    //for(i = 0; i < size; i++)
    //{
      //   scanf("%d", &list[i]);
    //}
    //part(list, 0, size - 1);
    //printf("After merge sort:\n");
    //for(i = 0;i < size; i++)
    //{
         //printf("%d   ",list[i]);
    //}
    printf("Time to sort array: ");
    printf(" %f ",(float)(t2-t1)/CLOCKS_PER_SEC);

    t1= clock();
    part(list, 0, 9999);
    t2 = clock();
    printf("\nTime to sort sorted array: ");
    printf(" %f ",(float)(t2-t1)/CLOCKS_PER_SEC);
   return 0;
}

void part(int list[],int low,int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;
        part(list, low, mid);
        part(list, mid + 1, high);
        merge(list, low, mid, high);
    }
}

void merge(int list[],int low,int mid,int high)
{
    int i, mi, k, l, temp[10000];

    l = low;
    i = low;
    mi = mid + 1;
    while ((l <= mid) && (mi <= high))
    {
        if (list[l] >= list[mi])
        {
            temp[i] = list[l];
            l++;
        }
        else
        {
            temp[i] = list[mi];
            mi++;
        }
        i++;
    }
    if (l > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    else
    {
        for (k = l; k <= mid; k++)
        {
             temp[i] = list[k];
             i++;
        }
    }

    for (k = low; k <= high; k++)
    {
        list[k] = temp[k];
    }
}
