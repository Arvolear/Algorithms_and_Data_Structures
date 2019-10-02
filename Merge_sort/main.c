#include <stdio.h>
#include <stdlib.h>

struct Point //Point (x;y)
{
    int x, y;
};

int cmp(struct Point p1, struct Point p2)
{
    if (p1.x + p1.y < p2.x + p2.y) //first inequality
    {
        return 0; //do not sort
    }

    if (p1.x + p1.y == p2.x + p2.y) //second inequality
    {
        if (p1.x < p2.x)
        {
            return 0; //do not sort
        }
    }

    return 1; //sort
}

void merge(struct Point arr[], int l, int m, int r)
{
    int i, j, k;

    int L = m - l + 1; //L array length
    int R = r - m; //R array length

    struct Point arrLeft[L], arrRight[R]; //tmp arrays

    for (i = 0; i < L; i++) 
    {
        arrLeft[i] = arr[l + i]; //copy L part of main array to L sub-array
    }
        
    for (j = 0; j < R; j++)
    {
        arrRight[j] = arr[m + j + 1]; //copy R part of main array to R sub-array
    }

    i = 0; //L array index
    j = 0; //R array index
    k = l; //main array index

    while (i < L && j < R) //merging into main array
    {
        if (cmp(arrLeft[i], arrRight[j]))
        {   
            arr[k] = arrLeft[i];
            i++;
        }
        else
        {
            arr[k] = arrRight[j];
            j++;
        }

        k++;
    }

    while (i < L) //adding left parts if some
    {
        arr[k] = arrLeft[i];
        i++;
        k++;
    }

    while (j < R) //adding right parts if some
    {
        arr[k] = arrRight[j];
        j++;
        k++;
    }
}

void mergeSort(struct Point arr[], int l, int r)
{
    if (l < r) 
    {
        int m = (r + l) / 2;
        mergeSort(arr, l, m); //divide first half
        mergeSort(arr, m + 1, r); //divide secnd half

        merge(arr, l, m, r); //sort
    }
}

int main()
{
    int n; //amount of points

    printf("%s\n", "Insert amount of points (0 < ?)");
    scanf("%d", &n); //inserting amount of Points > 0

    int checker = 0;

    while (n <= 0) //if input is incorrect
    {
        if (checker > 1) //if input is incorrect more than 3 times 
        {
            return 0; //exit
        }

        printf("%s\n", "Incorrect input!\nInsert amount of points (0 < ?)");
        scanf("%d", &n); //inserting amount of Points > 0

        checker++;
    }


    struct Point arr[n]; //main array

    for (int i = 0; i < n; i++) //inserting points
    {
        struct Point p;

        printf("\n%s%d%s\n", "Insert x and y coordinate of ", i + 1, " point");
        scanf("%d", &p.x);
        scanf("%d", &p.y);

        arr[i] = p;
    }

    mergeSort(arr, 0, n - 1); //calling sort function

    printf("\n%s\n", "Sorted points:");
    for (int i = 0; i < n; i++) //looping through the main array
    {
        printf("%d %d\n", arr[i].x, arr[i].y); //showing the points
    }

    return 0;
}
