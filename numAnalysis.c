/* Author: Amethyst Skye
 *
 * Description: This is a program written in C which asks the use to input a number. The program will then analyze the
 * number by listing all possible factors, the sum of possible factors, primality, and the "mood" of that number.
 */

#include <stdio.h>

int main()
{
    char str[120];
    int n,fc = 0,sum = 0; /*n=number, fc=factor counter*/

    printf("Enter a number:");
    fgets(str,120,stdin);
    sscanf(str,"%d",&n); /*convert string into int*/
    printf("Analyzing the number:%d\n",n);

    /*listing factors*/
    printf("Factors of %d are:",n);
    for(int i = 1;i < n;i++){
        if(n%i == 0){
            sum += i;
            fc++; /*factor counter ticks*/
            printf("%d ",i);
        }
    }
    printf("\n");

    /*prime or composite?*/
    if(fc>1) printf("%d is composite.\n",n);
    else printf("%d is prime.\n",n);

    /*sum of factors*/
    printf("The sum of factors is %d.\n",sum);

    /*mood of number*/
    if(sum < n) printf("The number %d is sad.\n",n);
    else if(sum > n) printf("The number %d is happy.\n",n);
    else if(sum == n) printf("The number %d is perfect.\n",n);
}
