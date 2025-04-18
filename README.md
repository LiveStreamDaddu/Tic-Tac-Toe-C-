# 🕹️ Tic Tac Toe - C++ with olcPixelGameEngine

This is a simple implementation of the classic **Tic Tac Toe** game using the [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) in C++. The player competes against a basic AI (computer) that makes random valid moves.

## 🎮 Features

- 3x3 Tic Tac Toe grid drawn with `olcPixelGameEngine`
- Player plays as **X** and the computer plays as **O**
- Simple click-based input for placing moves
- Basic computer opponent (random valid moves)
- Displays win/lose messages
- Clean and minimal UI

## 🛠️ Requirements

- A C++17 compatible compiler (e.g., g++, clang++)
- [olcPixelGameEngine.h](https://github.com/OneLoneCoder/olcPixelGameEngine) (included in the project directory)
- CMake (optional, for build automation)

## 🧾 How to Run

1. **Clone this repo** or copy the files into your C++ project folder.

2. **Make sure `olcPixelGameEngine.h` is in the same folder as your `.cpp` file**.

3. **Compile the code:**

   For Linux/macOS:
   ```bash
   g++ main.cpp -o tictactoe -lX11 -lGL -lpthread -std=c++17
   ./tictactoe
   ```

   For Windows (with MinGW):
   ```bash
   g++ main.cpp -o tictactoe.exe -std=c++17 -lgdi32
   tictactoe.exe
   ```

## 🧠 How It Works

- The game window is 400x300 pixels.
- A 3x3 grid is drawn using lines.
- Player clicks a cell to place an `X`.
- The computer randomly picks an empty cell and places an `O`.
- `DrawX()` and `DrawO()` functions draw the respective symbols on the grid.
- `checkWin()` checks for any winning combinations after each turn.
- Game ends once either player wins.

## 📌 To Do / Ideas

- Add a restart option
- Add score tracking
- Improve AI logic using Minimax or heuristics
- Add sound effects and animations

## 👨‍💻 Author

Akshay Pandey  
Made with ❤️ using olcPixelGameEngine

---
