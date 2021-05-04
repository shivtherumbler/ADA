#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort (int [], int, int);
int count=0;

int main()
{
    int list[1000];
    int size=1000, i;
    time_t t1,t2,t3,t4;

    for(int i=0;i<1000;i++)
    {
        list[i] = rand()%1000;
        //printf(" %d ",list[i]);
    }
    t1= clock();
    partition(list, 0, 999);
    t2 = clock();

    //printf("Enter the number of elements: ");
    //scanf("%d", &size);
    //printf("Enter the elements to be sorted:\n");
    //for (i = 0; i < size; i++)
    //{
      //  scanf("%d", &list[i]);
    //}
    quicksort(list, 0, size - 1);
    printf("After applying quick sort:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");


    printf("Time to sort list array: ");
    printf(" %f ",(float)(t2-t1)/CLOCKS_PER_SEC);

    t1= clock();
    quicksort(list, 0, 999);
    t2 = clock();
    printf("\nTime to sort sorted list array: ");
    printf(" %f ",(float)(t2-t1)/CLOCKS_PER_SEC);
    printf("\nNo. of recursive calls: ");
    printf(" %d ", count);

    count=0;
    t3= clock();
    quicksort(list, 0, 999);
    t4 = clock();
    printf("\nTime to sort sorted list array: ");
    printf(" %f ",(float)(t4-t3)/CLOCKS_PER_SEC);
    printf("\nNo. of recursive calls: ");
    printf(" %d ", count);

   return 0;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (list[j] > pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return (i + 1);
}

void quicksort(int list[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(list, low, high);

        quicksort(list, low, pi - 1);
        quicksort(list, pi + 1, high);
    }
    count++;
}
