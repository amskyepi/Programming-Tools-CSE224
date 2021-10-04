/*
 * Stick | Amethyst Skye | CSE224
 *
 * Description: A program written in C which allows the user to play a game if
 * sticks with the CPU. The user will be prompted to choose how many sticks to play
 * with. The CPU and user will take turns removing 1-4 sticks from the pile until
 * the pile is empty. Whoever removes the last stick from the pile is declared as
 * the winner.
 *
 */

#include <stdio.h>

int printSticks();

int main(){
    //Greet user
    printf("Hello, welcome to Stick!\n");
    int numSticks,numTaken;
    char str[120]; //temp storage for 120 characters of user input

    printf("How many sticks shall we play with?\n(Enter a number which is 10 or greater)\n");
    fgets(str, 120, stdin); //get user input
    sscanf(str,"%d",&numSticks); //convert input into an integer

    if (numSticks>=10){
        printf("Alright, perfect!\n");
        printSticks(numSticks); //calling numSticks function
        int turn=1; //user goes first

        while(numSticks!=0){
            while (turn==1){
                numTaken=0; //clear variable
                printf("Choose 1-4 sticks to take from the pile.\n");
                fgets(str,120,stdin); //user takes a turn
                sscanf(str,"%i",&numTaken); //numTaken = # of sticks selected to be removed

                if (numTaken>=1 && numTaken<=4){ //takes 1-4 sticks
                    numSticks=numSticks-numTaken; //new pile amount
                    printSticks(numSticks); //calling numSticks function
                    if (numSticks==0){
                        printf("Congrats, You won!\n"); //user wins
                        return 0;
                    }

                    else turn=2; //CPU takes a turn
                }

                else{ //all other cases
                    int n=1;
                    while (n=1){ //infinite loop until user behaves
                        if (numTaken>=1 && numTaken<=4){ //good behavior
                            numSticks=numSticks-numTaken;
                            printSticks(numSticks);
                            turn=2; //CPU takes a turn
                            break;
                        }

                        else{ //bad behavior
                            printf("Please try again.\n");
                            fgets(str,120,stdin);
                            sscanf(str,"%d",&numTaken);
                        }
                    }
                }
            }

            while (turn==2){ //CPU
                int cnumTaken=(numSticks%5); //alg for CPU turn

                if (cnumTaken!=0){
                    numSticks=numSticks-cnumTaken;
                    printf("I took %d sticks\n",cnumTaken);
                    printSticks(numSticks);
                }

                else numSticks--;

                if (numSticks==0){ //if CPU wins
                    printf("I won!\n");
                    return 0; //exit
                }

                else turn=1; //user takes a turn
            }
        }
    }
    else{
    printf("Exiting...\n");
    return(0); //exit
    }
}

//Function for Printing Sticks
int printSticks(int numSticks)
{
    for (int count=0;count<numSticks;count++){
        printf("|"); //prints number of | equal to numSticks
        }

    printf("(%d)\n",numSticks); //prints numSticks in parenthases
}
