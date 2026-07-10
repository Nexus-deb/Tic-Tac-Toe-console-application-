# Tic-Tac-Toe-console-application-
This is a Tic-Tac-Toe game I made, with 2 game modes, 1 for offline (1v1  against an IRL friend) and a Computer mode (1v1 against a computer). for now, this is WINDOWS ONLY (Sorry Linux friends)

So let me tell you how it works and how to play it. YOu compile it (about that later) and run it. Then, you'll see a console/terminal open. Don't worry, it's supposed to be like that, no one's hacking you. Then, you'll see a few instructions and a choice. You choose O for Offline mode, or C for Computer mode (doesn't matter if the letter's capital or lowercase). then you enter the X-coordinate of the space you want to go, press Enter, an then enter your Y-coordinate of the space you want to go to. you'll see visual help for that. Then you Press enter again. if this is Offline mode, your friend has to do the same. If this is computer moe, you simply press Enter again, or any other key, but the Enter key is the safest. Repeat until the game ends, then you'll be shown the result of your game, and a choice of playing the game again. Press Y/y and Enter if you want to play again, press N/n if you don't want to play again, then press Enter. If you're exiting the game, you'll have to press Enter again as a confirmation (otherwise it would look like the game crashed, I can remove that later on if it's unnecessary). The Computer will either win, or draw, it always moves in response to your moves. but send screenshots if you managed to win against the Computer, Good Luck with that!

Now, how to compile it on Windows:
You need the MinGW (g++) compiler for this compilation! You can find it at https://www.mingw-w64.org/

Step 1: Download the files and extract the zip folder into an other folder. 
Step 2: Right-click in that folder and select toe option to open the command prompt in that folder (or similar)
Step 3: Enter this in your command prompt: g++ -o tictactoe main.cpp modul.cpp confuncs.cpp
Step 4: Now, enter tictactoe.exe in the command prompt, or double-click the file that just appeared in the folder
Step 5: Enjoy :)

