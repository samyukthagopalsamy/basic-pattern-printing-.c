#include<stdio.h>

int main()
{
    
    int i ,j,k,n;
    k=1;
    printf("Number of rows required : ");
    scanf("%d",&n);
        for (i=0;i<n;i++)//loops till number of rows
            {
                for(j=0;j<=i;j++) // prints stars equal to row number
                    printf("  *",k++);
                printf("\n");
             }

    return 0;
}


/*
output:
*
* *
* * *
* * * *
*/

