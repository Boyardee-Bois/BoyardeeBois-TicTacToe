# BoyardeeBois-TicTacToe
# Build Instructions
1. Requires a C++ compiler
2. Compile with: g++ -std=c++11 -o tictactoe main.cpp

# Run Instructions
1. Run the executable: ./tictactoe
2. Any on-screen prompts within the game should be followed

# Tic Tac Toe Overview and How to Play!

When the game begins, it will randomly decide who goes first

You will be given the icon of an X or O

When it is your turn, enter a number from 1-9 corresponding to the board to place your icon

Once you have placed your icon, whatever numbered spot you occupied can no longer be placed on.

Your turn is now over and it is the other player's turn

They will place their different icon using the same grid repeating previous steps

To win, there must be 3 matching icons in a vertical, horizontal, or diagnol line

If all 9 spots of the board are filled with no 3 matching icons in any form of line, the game ends in a draw

The board will clear and the game will reset to randomly choosing who goes first again

_____________________________________________________________________________________________

# Requirements of The Game:

1. Creation of the 3x3 board where the game will be played

2. X and O icons that are to be placed on the board

3. Win conditions: 3 of the same icons in a horizontal, vertical, and diagonal line counting as a win

4. Stalemate conditions: Board is filled with no 3 same icon in a line

5. How to place down X and O icons on specific board spaces (i.e Player inputs the number 5 for the middle of the board)

6. If a spot is occupied by an X or O, both players are unable to place on said spot for the rest of the game

7. Boundaries of the board where the player cannot place an icon outside of the 1-9 numbered board

8. With a scoring feature, be able to add a win count to a certain player (Can include wins, draws, or even losses)

9. Game must decide and announce which player goes first

10. Game can be played in a Player vs Player format

11. Any incorrect inputs from the player should be given repeated instructions and explanations
