/* 
 *2015.10.31.
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char* szin;
    char ertek;
} kartya;


int bennevan(int kiosztott[], int num, int darab)
{
    int i;
    for(i=0; i<darab; i++)
    {
        if(kiosztott[i]==num)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    int i;
    char j;
    char input;
    char input2;
    char input3;
    srand(time(NULL));
    int r;
    int kiosztott[15];
    kartya jatekoskartya[12];
    kartya osztokartya[12];
    int money=500;
    int p=2;
    int q=2;
    int jatekososszeg=0;
    int osztoosszeg=0;
    int k=0;
    int vege=0;
    kartya pakli[52];
    for(i=0, j=1; i<10; i++, j++)
    {
        pakli[i].szin="Clover";
        pakli[i].ertek=j;

    }
    for(i=13, j=1; i<23; i++, j++)
    {
        pakli[i].szin="Heart";
        pakli[i].ertek=j;

    }
    for(i=26, j=1; i<36; i++, j++)
    {
        pakli[i].szin="Pike";
        pakli[i].ertek=j;
    }
    for(i=39, j=1; i<49; i++, j++)
    {
        pakli[i].szin="Tile";
        pakli[i].ertek=j;
    }
    pakli[10].szin="Clover";
    pakli[10].ertek="J";
    pakli[11].szin="Clover";
    pakli[11].ertek="Q";
    pakli[12].szin="Clover";
    pakli[12].ertek="K";

    pakli[23].szin="Heart";
    pakli[23].ertek="J";
    pakli[24].szin="Heart";
    pakli[24].ertek="Q";
    pakli[25].szin="Heart";
    pakli[25].ertek="K";

    pakli[36].szin="Pike";
    pakli[36].ertek="J";
    pakli[37].szin="Pike";
    pakli[37].ertek="Q";
    pakli[38].szin="Pike";
    pakli[38].ertek="K";

    pakli[49].szin="Tile";
    pakli[49].ertek="J";
    pakli[50].szin="Tile";
    pakli[50].ertek="Q";
    pakli[51].szin="Tile";
    pakli[51].ertek="K";


    printf("\t\tBlackJack Game\n\n");
    printf(" Informations:\n");
    printf(" The objective of the game is to beat the dealer in one of the following ways: \n");
    printf("\t- Get 21 points on the player's first two cards \n\t\t(called a \"blackjack\" or \"natural\"), without a dealer blackjack;\n");
    printf("\t- Reach a final score higher than the dealer without exceeding 21; or\n");
    printf("\t- Let the dealer draw additional cards until their hand exceeds 21.");
    printf("\n\n You start with 500 credit.\n One round costs 100 credit.");


    do
    {
        do
        {
            jatekososszeg=0;
            osztoosszeg=0;
            p=2;
            q=2;
            k=0;

            if(money==0)
            {
                printf(" You don't have any credit left!\n\n\tGAME OVER!");
                break;
            }
            printf("\n_____________________________________________________________________\n");
            r = rand() %53;
            jatekoskartya[0].szin=pakli[r].szin;
            jatekoskartya[0].ertek=pakli[r].ertek;
            kiosztott[0]=r;
            k++;
            jatekososszeg+=jatekoskartya[0].ertek;
            r = rand() %53;
            do
            {
                r = rand() %53;
            }
            while (bennevan(kiosztott, r, k)==1);
            jatekoskartya[1].szin=pakli[r].szin;
            jatekoskartya[1].ertek=pakli[r].ertek;
            kiosztott[1]=r;
            k++;
            jatekososszeg+=jatekoskartya[1].ertek;

            r = rand() %53;
            do
            {
                r = rand() %53;
            }
            while (bennevan(kiosztott, r, k)==1);
            osztokartya[0].szin=pakli[r].szin;
            osztokartya[0].ertek=pakli[r].ertek;
            kiosztott[2]=r;
            k++;
            osztoosszeg+=osztokartya[0].ertek;
            r = rand() %53;
            do
            {
                r = rand() %53;
            }
            while (bennevan(kiosztott, r, k)==1);
            osztokartya[1].szin=pakli[r].szin;
            osztokartya[1].ertek=pakli[r].ertek;
            kiosztott[3]=r;
            k++;
            osztoosszeg+=osztokartya[1].ertek;


            printf(" Your cards:     %6s %d ; %6s %d\n", jatekoskartya[0].szin, jatekoskartya[0].ertek,
                   jatekoskartya[1].szin, jatekoskartya[1].ertek);
            printf(" Your score: %d\n", jatekososszeg);
            printf(" The dealer's first card: %6s %d\n", osztokartya[0].szin, osztokartya[0].ertek);


            while(osztoosszeg<16)
            {
                r = rand() %53;
                do
                {
                    r = rand() %53;
                }
                while (bennevan(kiosztott, r, k)==1);
                kiosztott[k]=r;
                osztokartya[p].szin=pakli[r].szin;
                osztokartya[p].ertek=pakli[r].ertek;
                osztoosszeg+=osztokartya[p].ertek;

                p++;
                if (osztoosszeg>21)
                {
                    vege=1;
                    break;
                }
            }

            do
            {
                printf(" Do you want to get another card? [y], if yes, 2x[enter], if no!\n");
                scanf("%c%*c", &input);
                if(input=='y')
                {
                    r = rand() %53;
                    do
                    {
                        r = rand() %53;
                    }
                    while (bennevan(kiosztott, r, k)==1);
                    kiosztott[k]=r;
                    k++;
                    jatekoskartya[q].szin=pakli[r].szin;
                    jatekoskartya[q].ertek=pakli[r].ertek;
                    jatekososszeg+=jatekoskartya[q].ertek;
                    printf(" Your random card:\t%6s %d\n", jatekoskartya[q].szin, jatekoskartya[q].ertek);
                    printf(" Your score: %d\n", jatekososszeg);
                    q++;
                    if(jatekososszeg>21)
                    {
                        vege=2;
                        break;
                    }
                }
            }
            while(input=='y');

            if(jatekososszeg>21)
            {
                vege=2;
            }
            else if(jatekososszeg==osztoosszeg)
            {
                vege=5;
            }
            else if(osztoosszeg>21)
            {
                vege=1;
            }
            else if(jatekososszeg<osztoosszeg)
            {
                vege=3;
            }
            else if(jatekososszeg>osztoosszeg)
            {
                vege=4;
            }


            if(vege==1)
            {
                printf(" Congratulations! You won! The dealer's score is more than 21!\n");
                money+=100;
                printf("  _ _ _ _ _ _ _ _  \n You have %d credit left \n  - - - - - - - -  \n", money);
            }
            if(vege==2)
            {
                printf(" You lose! Your score is more than 21!\n");
                money-=100;
                printf("  _ _ _ _ _ _ _ _  \n You have %d credit left\n  - - - - - - - -  \n", money);
            }
            if(vege==3)
            {
                printf(" You lose! The dealer's score is higher than yours!\n");
                money-=100;
                printf("  _ _ _ _ _ _ _ _  \n You have %d credit left\n  - - - - - - - -  \n", money);
            }
            if(vege==4)
            {
                printf(" Congratulations! You won! The dealer's score is lower than yours!\n");
                money+=100;
                printf("  _ _ _ _ _ _ _ _  \n You have %d credit left\n  - - - - - - - -  \n", money);
            }
            if(vege==5)
            {
                printf(" Draw! The dealer has the same score as you have!\n  _ _ _ _ _ _ _ _  \n You have %d credit left\n  - - - - - - - -  \n", money);
            }
            if(vege==6)
            {
                printf(" Black Jack!\n  _ _ _ _ _ _ _ _  \n You have %d credit left\n  - - - - - - - -  \n", money);}
                       printf(" Do you want to continue? [i], if yes, 2x[enter], if no!\n");
                           scanf("%c%*c", &input2);
                           if(input2!='i'){break;}
                       } while (input2=='i');
                           if(money=0) {
                           printf(" You lose the game! Do you want to play again? [1], if yes, 2x[enter], if no!");
                                   scanf("%c%*c", &input3);}
                               }while (input3=='1');

                                   return 0;
                               }
