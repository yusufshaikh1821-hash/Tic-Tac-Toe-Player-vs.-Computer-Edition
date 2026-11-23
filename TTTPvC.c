#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void grid3x3(char *);
void grid3x3(char *g)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf("%c", *g);
                break;
            }
            printf("%c | ", *g);
            g++;
        }
        printf("\n");
        g++;
    }
}

char check(char g[][3], char x, char o)
{
    int p1, p2, p3, p4;
    int c1, c2, c3, c4;
    char p = 'P';
    char c = 'C';
    char t = 'T';
    for (int i = 0; i < 3; i++)
    {
        p1 = p2 = p3 = p4 = 0;
        c1 = c2 = c3 = c4 = 0;
        for (int j = 0; j < 3; j++)
        {
            if (g[i][j] == x)
            {
                p1++;
            }
            else if (g[i][j] == o)
            {
                c1++;
            }
            if (g[j][i] == x)
            {
                p2++;
            }
            else if (g[j][i] == o)
            {
                c2++;
            }
            if (i == 0)
            {
                if (g[j][j] == x)
                {
                    p3++;
                }
                else if (g[j][j] == o)
                {
                    c3++;
                }
                if (g[j][2 - j] == x)
                {
                    p4++;
                }
                else if (g[j][2 - j] == o)
                {
                    c4++;
                }
            }
        }
        if (i == 0)
        {
            if (p1 == 3 || p2 == 3 || p3 == 3 || p4 == 3)
            {
                return p;
            }
            else if (c1 == 3 || c2 == 3 || c3 == 3 || c4 == 3)
            {
                return c;
            }
        }
        else if (i != 0)
        {
            if (p1 == 3 || p2 == 3)
            {
                return p;
            }
            else if (c1 == 3 || c2 == 3)
            {
                return c;
            }
        }
    }
    return t;
}

int main()
{
    srand(time(0));

    char start_game;
    char grid[3][3];
    int player[5];
    int computer[4];
    char x = 'X';
    char o = 'O';
    int trigger;
    int min = 1;
    int max = 9;
    char outcome;

    printf("Tic-Tac-Toe\n");
    printf("Player : X\n");
    printf("Computer : O\n");

    printf("Enter any Character to Start Game :-> ");
    scanf("%c", &start_game);

    printf("Game Started!\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = '.';
        }
    }

    grid3x3(&grid[0][0]);

    for (int i = 0; i < 5; i++)
    {
        do
        {
            trigger = 0;
            printf("Player :-> ");
            scanf("%d", &player[i]);
            for (int j = 0; j < i; j++)
            {
                if (player[i] == player[j] || player[i] == computer[j] || player[i] < 1 || player[i] > 9)
                {
                    trigger++;
                    break;
                }
            }
        } while (trigger);

        switch (player[i])
        {
        case 1:
            grid[0][0] = x;
            break;
        case 2:
            grid[0][1] = x;
            break;
        case 3:
            grid[0][2] = x;
            break;
        case 4:
            grid[1][0] = x;
            break;
        case 5:
            grid[1][1] = x;
            break;
        case 6:
            grid[1][2] = x;
            break;
        case 7:
            grid[2][0] = x;
            break;
        case 8:
            grid[2][1] = x;
            break;
        case 9:
            grid[2][2] = x;
            break;
        default:
            break;
        }

        grid3x3(&grid[0][0]);

        outcome = check(grid, x, o);

        if (outcome == 'P' || outcome == 'C')
        {
            break;
        }

        if (i == 4)
        {
            break;
        }

        do
        {
            trigger = 0;
            computer[i] = (rand() % (max - min + 1)) + min;
            for (int j = 0; j < i; j++)
            {
                if (computer[i] == computer[j] || computer[i] == player[j] || computer[i] == player[i] || computer[i] < 1 || computer[i] > 9)
                {
                    trigger++;
                    break;
                }
            }
        } while (trigger);

        printf("Computer :-> %d\n", computer[i]);

        switch (computer[i])
        {
        case 1:
            grid[0][0] = o;
            break;
        case 2:
            grid[0][1] = o;
            break;
        case 3:
            grid[0][2] = o;
            break;
        case 4:
            grid[1][0] = o;
            break;
        case 5:
            grid[1][1] = o;
            break;
        case 6:
            grid[1][2] = o;
            break;
        case 7:
            grid[2][0] = o;
            break;
        case 8:
            grid[2][1] = o;
            break;
        case 9:
            grid[2][2] = o;
            break;
        default:
            break;
        }

        grid3x3(&grid[0][0]);

        outcome = check(grid, x, o);

        if (outcome == 'P' || outcome == 'C')
        {
            break;
        }
    }

    printf("Game Ended!\n");

    if (outcome == 'P')
    {
        printf("Player Wins!\n");
    }
    else if (outcome == 'C')
    {
        printf("Computer Wins!\n");
    }
    else if (outcome == 'T')
    {
        printf("Game Ties!\n");
    }

    printf("Thank You!");

    return 0;
}