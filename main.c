/* 
Oliver Amparo
project 2 Yahtzee
00316561@student.necc.edu
Basic yahtzee game

*/


include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 5
#define SCORECARD_SIZE 13
/*prototypes for all the functions */
void getFrequency(int dice_array[] , int frequency_array[] );
void printScoreCard(int scorecard[] );
int roll();
void reRoll(int dice_array[] , int keepArray[] );
void printHand(int dice_array[] );
int getChanceScore(int dice_array[] );
int sumOfNum(int dice_array[] , int num, int frequency_array[]);
int getThreeOfKindScore(int dice_array[], int frequency_array[]);
int getFourOfKindScore(int dice_array[], int frequency_array[]);
int getSmallStraightScore(int dice_array[]);
int getLargeStraightScore(int dice_array[] );
int getFullHouseScore(int dice_array[], int frequency_array[] );
int getYahtzeeScore(int dice_array[] );
int highest(int scorecard []);

/* rolling 5 dice*/
int roll(int dice_array[], int size)
{
/*loop variable and upper bound */
    int numbarange = 6;
    int upper = 6;
    
    /* using time to get random seeds*/
    srand(time(0));
    for(int i= 1; i < 6; i++ )
    {
        dice_array[i] = rand() % upper + 1;

    }
    /*
    for(int i = 0; i < numbarange; i++)
    {
         printf("%i\n smething ", dice_array[i]);
    }
    */


}
/*frequency of how much things happen */
void getFrequency(int dice_array[], int frequency_array[])
{
    int size = 7;

    for(int count = 1; count < size; count++)

    {
/* getting value of each die and adding 1 to frequency*/
        frequency_array[dice_array[count]] +=1;



    }

/* print value of each number*/
    for (int i = 1; i < 7; i++)
    {
        printf("%i : %i\n", i, frequency_array[i] * i);
    }


}
/* print all indexes in dice_array*/
void printHand(int dice_array[] )
{
    /* formating the output*/
    int size = 6;
    printf("Your hand\n");
    printf("[");
    for(int i = 1; i < size; i++)
    {

        printf("%i ", dice_array[i]);
    }
    printf("]\n");
}

/* reroll using the keep array which has 0s and 1s*/
void reRoll(int dice_array[], int keepArray[])
{
    int keepsize = 6;
    int keep = 5;


    int upper = 6;

/* getting user input for keep size array*/

    printf("For each value Place a 1 to keep that value, place a 0 to reroll\n");
    for (int i = 1; i < keepsize; i++)
    {
        scanf("%i", &keepArray[i]);


    }
    /* random seed with time*/
    srand(time(0));
    
    /* keeping or using random seed to change 0 values*/
    for (int compare = 0; compare < keep; compare++)
    {
/*same as roll */
        if(keepArray[compare] == 0)
        {
            int anumb = rand() % upper + 1;

            //printf("%i", anumb);
            dice_array[compare] = anumb;


        }
        else if (keepArray[compare] == 1)
        {
            dice_array[compare] = dice_array[compare];
        }

    }







}
/* adding all the values in dice array*/
int getChanceScore(int dice_array[] )

{
    int size = 6;
    int cha = 0;
    for(int i = 1; i < size; i++)
    {
        cha += dice_array[i];
    }
/* returning all added values*/
    return cha;

}



/* 3 of a kind*/
int getThreeOfKindScore(int dice_array[] ,int frequency_array[])
{
    int size = 6;
    
    /*variable that changes */
    int multi = 0;
/* cycle and see if frequency is 3*/
    for(int i = 1; i < 7; i++)
    {

        if(frequency_array[i] ==  3 )
        {
            for(int some = 1; some < 6; some++)
            {
                /*  add every value*/
                multi += dice_array[some];

            }


        }

    }
    /*return added value */
    return  multi;


    //return 0;
}
/* basically the same as above but with 4 */
int getFourOfKindScore(int dice_array[], int frequency_array[])
{
    int size = 7;
    int mult = 0;

    for(int i = 1; i < size; i++)
    {

        if(frequency_array[i] == 4)
        {
            for(int some = 1; some < 6; some++)
            {
                mult += dice_array[some];

            }


        }

    }
    return  mult;
}
/* full house uses frequency array*/
int getFullHouseScore(int dice_array[], int frequency_array[])
{
    int size = 7;
    int val1 = 0;
    int secval = 0;
/*  cheaking if there is a value of 3 and 2 on frequency*/
    for(int i = 1; i < size; i++)
    {
        if (frequency_array[i] == 3)
        {
            val1 = 3;


        }

        if (frequency_array[i] == 2)
        {
            secval = 2;
        }

        if (val1 == 3 && secval == 2)
        {
            /* returning 25 that the score*/ 
            return 25;
        }

    }

    return 0;

}



/* if score is 1, 2, 3, 4 or 3, 4, 5, 6*/
int getSmallStraightScore(int dice_array [])
{
    int size = 7;
    int inarow = 0;

   for (int i = 1; i < size; i++)
   {
       /* increment inarow if the next number is 1 bigger*/
       if (dice_array[i + 1] - dice_array[i] == 1)
       {

           inarow++;

       }
       /* checks on if it is a straight of 4 and returns 30*/
       if (inarow > 3)
        {
            return 30;

        }

    }
   return 0;


}
/* large straight of 5 ex 1 2 3 4 5 or 2 3 4 5 6*/
int getLargeStraightScore(int dice_array[] )
{
    int size = 7;
    int inarow = 0;
/* basically same as above*/
   for (int i = 0; i < size; i++)
   {
       if (dice_array[i + 1] - dice_array[i] == 1)
       {

           inarow++;

       }
       if (inarow > 4)
        {
            /* if in a row is 5 return 40*/
            return 40;

        }

    }
   return 0;
}


/* check if all the values are the same*/
int getYahtzeeScore(int dice_array[])
{
    int size = 6;
    int temp = 0;

    for(int i= 1; i < size; i ++)
    {
        /* check if values next to each other are the same*/
        if(dice_array[i] == dice_array[i + 1] )
        {
            /* adding to temp*/
            temp++;
        }
/* if temp is 5 then return the best score 50*/
        if (temp >= 4)
        {
            return 50;
        }

    }
    return 0;
}

/* cheaking for the biggest value of the whole array*/
int highest(int scorecard [])
{
    int newhigh = scorecard[0];
    for (int i= 1;i < 13; i++ )
    {
        if (newhigh > scorecard[i])
        {
            newhigh = scorecard[i];

            return newhigh;
        }

        return newhigh;
    }


}




/*printing all the scores basically main loop at this point */
void printScoreCard(int scorecard[] )
{
    int size = 6;
    int dice_array[HAND_SIZE];
    int frequency_array[7]= {-5, 0, 0, 0, 0, 0, 0};



/* rolling dice*/
    roll(dice_array, size);

/* printing the array*/
     printHand(dice_array );


    int count = 0;
    int newcount = 0;
/* asking 2 times for user input*/
    for (int someval = 0; someval < 6; someval++)
    {

        if ( count < 2 )
        {
            int keepArray[6];

            reRoll(dice_array, keepArray);


            printHand(dice_array );
        }
        count++;


        if(frequency_array[someval] = 0)
        {
            newcount++;
        }


    }

    getFrequency(dice_array, frequency_array);





/*
personal testing
    dice_array[1] = 1;
    dice_array[2] = 2;
    dice_array[3] = 3;
    dice_array[4] = 4;
    dice_array[5] = 9;
*/


    scorecard[0] = frequency_array[1];
    scorecard[1] = frequency_array[2];
    scorecard[2] = frequency_array[3];
    scorecard[3] = frequency_array[4];
    scorecard[4] = frequency_array[5];
    scorecard[5] = frequency_array[6];
    scorecard[6] = frequency_array[7];


/* printing all the scoreboard*/


    scorecard[7] = getChanceScore(dice_array);
    printf("chance %i\n", scorecard[7]);




    scorecard[8] = getThreeOfKindScore(dice_array, frequency_array);
    printf("Three of a kind:  %i\n", scorecard[8]);


    scorecard[9] = getFourOfKindScore( dice_array, frequency_array);
    printf("Four of a kind: %i\n", scorecard[9]);

    scorecard[10] = getFullHouseScore(dice_array, frequency_array);
    printf("Full house: %i\n", scorecard[10]);


    scorecard[11] = getSmallStraightScore(dice_array);
    printf("small straight: %i\n", scorecard[11]);


    scorecard[12] = getLargeStraightScore(dice_array);
    printf("big straight: %i\n", scorecard[12]);

    scorecard[13]= getYahtzeeScore(dice_array);
    printf("Yahtzee:  %i\n", scorecard[13]);




    int highval = highest(scorecard);

    if (highval > scorecard[7] )
    {
        printf("Highest score: %i", highval);
    }
    else
    {
        printf("Highest score: %i", scorecard[7]);

    }





}




int main() {

    /*
     dice in hand array are your dice to play
      dice to roll is a parallel array used to
     mark which dice in hand to roll and which keep.
     In the dice to roll array, a 1 means roll the parallel die
      if it is a 0 then do not roll that die and keep its value
     */
    int dice_in_hand[HAND_SIZE] = {0};
    int dice_to_roll[HAND_SIZE] = {0};






    /*
     ÃŸScore card array keeps the score for each category
      works with the enum above to use worrds instead of index numbers

    int scorecard[SCORECARD_SIZE] = {0};
*/


    int scorecard[SCORECARD_SIZE];

/*print all the cards */
    printScoreCard(scorecard);



    return 0;
}