/******************************************************************************

                            Welcome To Morpion Game.
                    Developed with C By Med Rami! Enjoy :)
                                Version 2022

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void welcome()
{
    printf("\n\n");
    printf("\t\t\tXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO\n");
    printf("\t\t\tOX                                                      OX\n");
    printf("\t\t\tXO              WELCOME TO MORPION GAME                 XO\n");
    printf("\t\t\tOX            Developed with C By Med Rami              OX\n");
    printf("\t\t\tXO                      ENJOY :)                        XO\n");
    printf("\t\t\tOX                                                      OX\n");
    printf("\t\t\tXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO\n");
    printf("\n\n");
}

// ------------------------ Structs
// Player Struct
typedef struct
{
    char fullName[30];
    short played; // games played
    short wins;   // games won
    char style;   // X or O
} Player;

// Game Struct
typedef struct
{
    char **board;
    Player *player1;
    Player *player2;
} Game;

// ------------------------ Functions
// Create Player
Player *createPlayer()
{
    Player *player = (Player *)malloc(sizeof(Player));
    fgets(player->fullName, sizeof(player->fullName), stdin);

    return player;
}

// Initialise Board
char **initBoard()
{
    char **board = (char **)malloc(3 * sizeof(char *));
    int i, j;
    for (i = 0; i < 3; i++)
        board[i] = (char *)malloc(3 * sizeof(char));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = (3 * i + j + 1) + '0';
        }
    }
    return board;
}

// Draw Board
void drawBoard(char **board)
{
    //system("clear");
    int i, j;
    for (i = 0; i < 3; i++)
    {             
        printf("\n---------------\n");
        for (j = 0; j < 3; j++)
        {
            printf("  %c  ", board[i][j]);
        }
    }
    printf("\n---------------\n");
}

// Create Game
Game *newGame()
{
    Game *game = (Game *)malloc(sizeof(Game));

    game->board = initBoard();

    printf("1st Player, What is your name? ");
    game->player1 = createPlayer();

    printf("2nd Player, What is your name? ");
    game->player2 = createPlayer();

    game->player1->style = "OX"[rand() % 2];
    game->player2->style = (game->player1->style) == 'X' ? 'O' : 'X';

    printf("Are you ready?\n");
    printf("%s You'll be playing %c\n", game->player1->fullName, game->player1->style);
    printf("And you %s you'll be playing %c\n", game->player2->fullName, game->player2->style);
    printf("Ready!! Let's Go...");
    return game;
}

// Play Turn
void play(Game *game, Player *player)
{
    char ij[9][3] = {"00", "01", "02", "10", "11", "12", "20", "21", "22"};

    printf("It's your turn (%c) %s ", player->style, player->fullName);
    bool valid = true;
    char input = '\0';
    int position = 0;
    do
    {
        valid = true;
        scanf("%c", &input);
        position = (int)input - 48;
        if (position > 0 && position < 10)
        {
            int i = ij[position - 1][0] - 48;
            int j = ij[position - 1][1] - 48;

            if (game->board[i][j] == (position + '0'))
            {
                game->board[i][j] = player->style;
            }
            else
            {
                drawBoard(game->board);
                printf("Not Valid!! Box is not empty! Try again: ");
                valid = false;
            }
        }
        else
        {
            drawBoard(game->board);
            printf("Not Valid!! check your choice! Try again (1-9): ");
            valid = false;
        }
    } while (!valid);

    drawBoard(game->board);
}

// Check Win
char checkWin(char **board)
{
    // Check cols & rows
    int i;
    for (i = 0; i < 3; i++)
    {
        // rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0]; // X or O
        }
        // cols
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i]; // X or O
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2]; // X or O
    }

    return '\0';
}

// Check Drow
bool checkDrow(char **board)
{
    int i, j, filled = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] != ((3 * i + j + 1) + '0'))
                filled++;
        }
    }
    return (filled >= 9);
}

// Start Game
void startGame(Game *game)
{
    int turn = 1;
    while (true)
    {
        drawBoard(game->board);
        play(game, turn == 1 ? game->player1 : game->player2);

        char winner = checkWin(game->board);
        if (winner != '\0')
        {
            printf("Holyaa!! You Win %c\n", winner);
            break;
        }
        else if (checkDrow(game->board))
        {
            printf("Game on drow!\n");
            break;
        }
        turn = (turn == 1) ? 2 : 1;
    }
    playAgain(game);
}

// Play Again
void playAgain(Game *game)
{
    int replay = 0;
    printf("Do you want to play again? (1 or 0): ");
    scanf("%d", &replay);
    if (replay == 1)
    {
        game->board = initBoard();
        startGame(game);
    }
}

int main()
{
    welcome();
    Game *game = newGame();
    system("clear");
    startGame(game);

    return 0;
}
