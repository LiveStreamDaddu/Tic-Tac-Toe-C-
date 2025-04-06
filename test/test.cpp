#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include <ctime>

class tic_tac_toe : public olc::PixelGameEngine {
public:
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }; 
    char player = 'X';
    char computer = 'O';
    bool playerTurn = true; 
    bool gameOver = false;  

    tic_tac_toe() {
        sAppName = "Tic Tac Toe";
    }

    bool OnUserCreate() override {
        Clear(olc::BLACK);
        DrawGrid(); 
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        if (gameOver) {
           
            olc::vf2d pos(300, 10);
            if (checkWin(spaces, player, computer) == 1) {
                DrawString(pos, "You win!", olc::GREEN);
            }
            else if (checkWin(spaces, player, computer) == 2) {
                DrawString(pos, "You lose!", olc::RED);
            }
            return true;
        }

        if (playerTurn) {
            turn(spaces);
        }
        else {
            compturn(spaces); 
            playerTurn = true; 
        }

        return true;
    }

    void DrawGrid() {
        DrawLine(100, 0, 100, 300, olc::WHITE);
        DrawLine(200, 0, 200, 300, olc::WHITE);
        DrawLine(0, 100, 300, 100, olc::WHITE);
        DrawLine(0, 200, 300, 200, olc::WHITE);
    }

    void turn(char* spaces) {
        if (GetMouse(0).bPressed) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();
            int index = -1;

           
            if (mouseX < 100 && mouseY < 100) index = 0;
            else if (mouseX < 200 && mouseY < 100) index = 1;
            else if (mouseX < 300 && mouseY < 100) index = 2;
            else if (mouseX < 100 && mouseY < 200) index = 3;
            else if (mouseX < 200 && mouseY < 200) index = 4;
            else if (mouseX < 300 && mouseY < 200) index = 5;
            else if (mouseX < 100 && mouseY < 300) index = 6;
            else if (mouseX < 200 && mouseY < 300) index = 7;
            else if (mouseX < 300 && mouseY < 300) index = 8;

           
            if (index != -1 && spaces[index] == ' ') {
                spaces[index] = player;
                DrawX(index);
                if (checkWin(spaces, player, computer) == 1) gameOver = true;
                playerTurn = false; 
            }
        }
    }

    void compturn(char* spaces) {
        srand(time(0));
        int number;
        while (true) {
            number = rand() % 9;
            if (spaces[number] == ' ') {
                spaces[number] = computer;
                DrawO(number);
                if (checkWin(spaces, player, computer) == 2) gameOver = true;
                break;
            }
        }
    }

    void DrawX(int index) {
        int xOffset = (index % 3) * 100; 
        int yOffset = (index / 3) * 100; 
        DrawLine(xOffset + 10, yOffset + 10, xOffset + 90, yOffset + 90, olc::YELLOW);
        DrawLine(xOffset + 10, yOffset + 90, xOffset + 90, yOffset + 10, olc::YELLOW);
    }

    void DrawO(int index) {
        int xOffset = (index % 3) * 100 + 50; 
        int yOffset = (index / 3) * 100 + 50;
        DrawCircle(xOffset, yOffset, 40, olc::RED);
    }

    int checkWin(char* tiles, char player, char computer) {
        char winners[2] = { player, computer };
        for (char winner : winners) {
            if ((tiles[0] == winner && tiles[1] == winner && tiles[2] == winner) ||
                (tiles[3] == winner && tiles[4] == winner && tiles[5] == winner) ||
                (tiles[6] == winner && tiles[7] == winner && tiles[8] == winner) ||
                (tiles[0] == winner && tiles[3] == winner && tiles[6] == winner) ||
                (tiles[1] == winner && tiles[4] == winner && tiles[7] == winner) ||
                (tiles[2] == winner && tiles[5] == winner && tiles[8] == winner) ||
                (tiles[0] == winner && tiles[4] == winner && tiles[8] == winner) ||
                (tiles[2] == winner && tiles[4] == winner && tiles[6] == winner)) {
                return (winner == player) ? 1 : 2;
            }
        }
        return 0; 
    }
};

int main() {
    tic_tac_toe game;
    if (game.Construct(400, 300, 2, 2)) {
        game.Start();
    }
    return 0;
}