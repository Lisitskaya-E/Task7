#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int* f6(int a[],int b[], int n, int m)
{

    int* c;
    c = (int*) malloc((n+m)*sizeof(int));
    int A=0, B=0, i;
    for (i = 0; i< m+n; i++)
    {
        if ((A < n)&&(B<m))
        {
            if (a[A]<b[B])
            {
                c[i]=a[A];
                A+=1;
            }
            else
            {
                c[i]=b[B];
                B+=1;
            }
        }
        else
        {
            if (A == n)
            {
                c[i]=b[B];
                B+=1;
            }
            else
            {
                c[i]=a[A];
                A+=1;
            }

        }
    }
    return c;
}
int main()
{
    int N;
    setlocale(LC_ALL,"Rus");
    printf("Номер задачи: \n");
    scanf("%d", &N);
    while(N)
    {

        if (N == 4){int n;
        setlocale(LC_ALL,"Rus");
        printf("Введите кол-во элементов массива: \n");
        scanf("%d", &n);
        int a[n];
        int i=0, max1, max2, c=0;
        printf("Введите массив: \n");
        scanf("%d%d", &a[0], &a[1]);

        if (a[0] > a[1])
        {
            max2= a[1];
            max1=a[0];
        }
        else
        {
            max1=a[1];
            max2=a[0];
        }

        for (i = 2; i<n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] >= max1)
            {
                max2=max1;
                max1 = a[i];
            }
            else
            {
                if (a[i] > max2)
                {
                    max2 = a[i];
                }
            }
        }


        printf("%4d", max2);

    }

    if (N==5)
    {
        int n;
        setlocale(LC_ALL,"Rus");
        printf("Введите кол-во элементов массива: \n");
        scanf("%d", &n);
        int a[n];
        int i=0, l=0, r=n-1, x;
        printf("Введите массив: \n");


        for (i = 0; i<n; i++)
        {
            scanf("%d", &a[i]);

        }
        printf("Введите элемент: \n");
        scanf("%d", &x);
        i = bin_s(a, n, l, r, x);
        if (i==-1)
        {
            printf("нет такого");
        }
        else
        {
            printf("%4d", i+1);
        }


    }

    if (N==6)
    {
        int n, m;
        printf("Введите m и n: \n");
        scanf("%d%d", &n, &m);
        int* a;
        a = (int*) malloc(n*sizeof(int));
        int* b;
        b = (int*) malloc(m*sizeof(int));
        int i=0;
        printf("Введите массивы: \n");
        for (i=0; i<n; i++)
        {
            scanf("%d", a+i);
        }
        for (i=0; i<m; i++)
        {
            scanf("%d", b+i);
        }
        int* c = f6(a, b, n, m);
        for (i=0; i<n+m; i++)
            printf("%d ", c[i]);

    }



    printf("\nНомер задачи: \n");
    scanf("%d", &N);
}
}
int bin_s(int a[], int n, int l, int r,  int x)
{
    int m=(l+r)/2;
    if (l>r)
    {
        return -1;
    }
    else
    {
        if (a[m] == x)
        {
            return m;
        }
        if (a[m]>x)
        {
            return bin_s(a, n, l, m-1, x);
        }
        else
        {
            return bin_s(a, n, m+1, r, x);
        }
    }

}
