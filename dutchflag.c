#include<stdio.h>
void swap(int *a,int *b);
void sort012(int a[],int arr_size)
{
    int lo=0;
    int high=arr_size-1;
    int mid=0;
    while(mid<=high)
    {
        switch(a[mid])
        {
            case 0:swap(&a[lo++],&a[mid++]);
            break;
            case 1: mid++;
            break;
            case 2: swap(&a[mid],&a[high--]);
            break;
        }

    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printarray(int arr[],int arr_size)
{
    int i;
    for(i=0;i<arr_size;i++)
        printf("%d",arr[i]);
        printf("\n");
}
int main()
{
    int arr[]={0,1,2,0,2,2,2,1,1,1,0};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    int i;
    sort012(arr,arr_size);
    printarray(arr,arr_size);
    getchar();
    return 0;
}

