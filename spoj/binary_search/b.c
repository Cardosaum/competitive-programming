// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include<stdio.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(int i = 0; i < q; i++)
    {
        int query;
        scanf("%d", &query);

        int start = 0, end = n-1, mid;
        while(start <= end)
        {
            mid = (start+end)/2;
            if(arr[mid] == query)
            {
                printf("%d\n", mid);
                break;
            }
            else if(arr[mid] > query) end = mid-1;
            else start = mid+1;
        }
        if(start > end) printf("-1\n");
    }

    return 0;
}