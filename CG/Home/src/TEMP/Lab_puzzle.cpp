#include <graphics.h>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

const int boardSize = 10;
const int tileSize = 25;
const int rackSize = 10;
const int totalTime = 600;

const int boardLeft = 50;
const int boardTop = 50;
const int rackTop = boardTop + tileSize * boardSize + 40;

const int rackLeft = 20;
const int rackRight = rackLeft + tileSize * rackSize;
const int rackBottom = rackTop + tileSize;

vector<vector<char>> board(boardSize, vector<char>(boardSize, ' '));
vector<vector<char>> boardans(boardSize, vector<char>(boardSize, ' '));
vector<char> playerRack = {};
int remainingTime = totalTime;
int posx = -1, posy = -1;

struct WordInfo
{
    string word;
    int startRow;
    int startCol;
    bool isHorizontal;
};

vector<WordInfo> placedWords;

void drawRack()
{
    setcolor(BLACK);
    int x = 20;
    for (char tile : playerRack)
    {
        rectangle(x, rackTop, x + tileSize, rackTop + tileSize);
        char tileStr[2] = {tile, '\0'};
        outtextxy(x + 7, rackTop + 7, tileStr);
        x += tileSize;
    }
}

void drawBoard()
{
    setcolor(BLACK);
    for (int row = 0; row < boardSize; ++row)
    {
        for (int col = 0; col < boardSize; ++col)
        {
            rectangle(boardLeft + col * tileSize, boardTop + row * tileSize, boardLeft + (col + 1) * tileSize, boardTop + (row + 1) * tileSize);
            char tileChar = board[row][col];
            if (posx == row && posy == col)
            {
                bar(boardLeft + col * tileSize, boardTop + row * tileSize, boardLeft + (col + 1) * tileSize, boardTop + (row + 1) * tileSize);
            }
            if (tileChar != ' ')
            {
                char tileStr[2] = {tileChar, '\0'};
                outtextxy(boardLeft + col * tileSize + 7, boardTop + row * tileSize + 7, tileStr);
            }
        }
    }
    drawRack();
}

void handleMouseClick()
{
    int button, x, y;

    if (ismouseclick(WM_LBUTTONDOWN))
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        int boardCol = (x - boardLeft) / tileSize;
        int boardRow = (y - boardTop) / tileSize;
        if (boardRow >= 0 && boardRow < boardSize && boardCol >= 0 && boardCol < boardSize)
        {
            posx = boardRow;
            posy = boardCol;
        }
        cleardevice();
        drawBoard();
    }
}

void handleInput()
{
    char keyPressed;
    int x, y;
    int time = 0;
    char selectedCharacter;
    while (true)
    {
        if (kbhit())
        {
            keyPressed = getch();

            if (keyPressed == 27)
            {
                break;
            }
            if (keyPressed == 13)
            {
                break;
            }
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Check if the click is inside the rack area
            if (x >= rackLeft && x <= rackRight && y >= rackTop && y <= rackBottom)
            {
                int rackIndex = (x - rackLeft) / tileSize; // Calculate the index of the selected character in the rack
                if (rackIndex >= 0 && rackIndex < playerRack.size())
                {
                    selectedCharacter = playerRack[rackIndex];
                    // Store the selected character
                    playerRack.erase(playerRack.begin() + rackIndex);
                }
            }
            // Check if the click is inside the board area
            int boardCol = (x - boardLeft) / tileSize;
            int boardRow = (y - boardTop) / tileSize;
            if (boardRow >= 0 && boardRow < boardSize && boardCol >= 0 && boardCol < boardSize)
            {
                if (selectedCharacter != ' ' && board[boardRow][boardCol] == ' ')
                {
                    board[boardRow][boardCol] = selectedCharacter;
                    selectedCharacter = ' ';
                }
            }

            cleardevice();
            drawBoard();
        }
    }
    int boardCol = (x - boardLeft) / tileSize;
    int boardRow = (y - boardTop) / tileSize;
    if (boardRow >= 0 && boardRow < boardSize && boardCol >= 0 && boardCol < boardSize)
    {
        if (selectedCharacter != ' ' && board[boardRow][boardCol] == ' ')
        {
            board[boardRow][boardCol] = selectedCharacter;
            selectedCharacter = ' ';
        }
    }

    cleardevice();
    drawBoard();
}

void placeWords()
{
    vector<string> wt = {"TREE", "FLOWER", "RIVER", "MOUNTAIN", "FOREST", "OCEAN", "WILDLIFE", "SUNSHINE", "RAINBOW", "BUTTERFLY", "BIRD", "LAKE", "LANDSCAPE", "ECOLOGY", "EARTH"};
    random_shuffle(wt.begin(), wt.end());

    vector<string> selectedWords;

    // Check if there are at least 3 words
    if (wt.size() >= 3)
    {
        // Use iterators to specify the range
        auto start = wt.begin();   // Starting at the beginning
        auto end = wt.begin() + 4; // Ending after 4 words

        // Make sure you don't go beyond the end of the shuffled vector
        if (end > wt.end())
        {
            end = wt.end();
        }

        selectedWords.insert(selectedWords.end(), start, end);
    }

    for (const string &word : selectedWords)
    {
        int wordLen = word.length();
        bool placed = false;

        while (!placed)
        {
            int row = rand() % boardSize;
            int col = rand() % boardSize;
            bool isHorizontal = rand() % 2 == 0;
            bool valid = true;

            if (isHorizontal)
            {
                if (col + wordLen <= boardSize)
                {
                    for (int i = 0; i < wordLen; i++)
                    {
                        if (board[row][col + i] != ' ' && board[row][col + i] != word[i])
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid)
                    {
                        for (int i = 0; i < wordLen; i++)
                        {
                            board[row][col + i] = word[i];
                            boardans[row][col + i] = word[i];
                        }
                        placed = true;

                        // Store word information in the placedWords vector
                        WordInfo wordInfo;
                        wordInfo.word = word;
                        wordInfo.startRow = row;
                        wordInfo.startCol = col;
                        wordInfo.isHorizontal = true;
                        placedWords.push_back(wordInfo);
                    }
                }
            }
            else
            {
                if (row + wordLen <= boardSize)
                {
                    for (int i = 0; i < wordLen; i++)
                    {
                        if (board[row + i][col] != ' ' && board[row + i][col] != word[i])
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid)
                    {
                        for (int i = 0; i < wordLen; i++)
                        {
                            board[row + i][col] = word[i];
                            boardans[row + i][col] = word[i];
                        }
                        placed = true;

                        // Store word information in the placedWords vector
                        WordInfo wordInfo;
                        wordInfo.word = word;
                        wordInfo.startRow = row;
                        wordInfo.startCol = col;
                        wordInfo.isHorizontal = false;
                        placedWords.push_back(wordInfo);
                    }
                }
            }
        }
    }
}

void showsol()
{
    for (int row = 0; row < boardSize; ++row)
    {
        for (int col = 0; col < boardSize; ++col)
        {
            setcolor(BLACK);
            rectangle(boardLeft + col * tileSize, boardTop + row * tileSize, boardLeft + (col + 1) * tileSize, boardTop + (row + 1) * tileSize);
            char tileChar = boardans[row][col];
            if (tileChar != ' ' && board[row][col] != boardans[row][col])
            {
                setcolor(RED);
                char tileStr[2] = {tileChar, '\0'};
                outtextxy(boardLeft + col * tileSize + 7, boardTop + row * tileSize + 7, tileStr);
            }
            else if (tileChar != ' ' && board[row][col] == boardans[row][col])
            {
                setcolor(GREEN);
                char tileStr[2] = {tileChar, '\0'};
                outtextxy(boardLeft + col * tileSize + 7, boardTop + row * tileSize + 7, tileStr);
            }
        }
    }
    drawRack(); // Display the player's rack
}

void updateTime()
{
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;
}

bool checkWinCondition()
{
    for (const WordInfo &wordInfo : placedWords)
    {
        int wordLen = wordInfo.word.length();

        if (wordInfo.isHorizontal)
        {
            for (int i = 0; i < wordLen; i++)
            {
                if (board[wordInfo.startRow][wordInfo.startCol + i] != wordInfo.word[i])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 0; i < wordLen; i++)
            {
                if (board[wordInfo.startRow + i][wordInfo.startCol] != wordInfo.word[i])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void removeAndFillRack()
{
    int charactersToMove = boardSize * boardSize / 2;
    vector<char> removedCharacters;

    for (int i = 0; i < charactersToMove; i++)
    {
        int row = rand() % boardSize;
        int col = rand() % boardSize;
        if (board[row][col] != ' ')
        {
            removedCharacters.push_back(board[row][col]);
            board[row][col] = ' ';
        }
    }

    // Add the removed characters back to the player's rack
    playerRack.insert(playerRack.end(), removedCharacters.begin(), removedCharacters.end());
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cleardevice();
    srand(static_cast<unsigned>(time(nullptr)));
    setbkcolor(YELLOW);
    int font = BOLD_FONT;
    int direction = HORIZ_DIR;
    int size = 3;
    settextstyle(font, direction, size);

    placeWords();
    removeAndFillRack();

    while (!kbhit())
    {
        cleardevice();
        drawBoard();
        updateTime();
        handleInput();
        showsol();
        getch();
        if (checkWinCondition())
        {
            cleardevice();
            setcolor(BLACK);
            char win[] = "Congratulations! You've won the game!";
            outtextxy(50, 50, win);
            getch();
            break;
        }
        else
        {
            cleardevice();
            setcolor(BLACK);
            char loss[] = "Sorry! You've loss the game!";
            outtextxy(50, 50, loss);
            getch();
            break;
        }
    }

    closegraph();
    return 0;
}

