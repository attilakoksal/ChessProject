# Online Multiplayer Chess Game


*Authors: Attila Koksal, Rushil Mohandas, Ray Wang, Nishant Tiwari*

Project Description: 

Why is it important or interesting to us?

Aside from the fact that all of us find chess interesting, we also believe that a chess game would properly demonstrate our ability to manipulate inputs and outputs. It will help us to understand the technological complexity of building a physical game to digital software. 


What languages/tools/technologies do we plan to use?

We plan to use C++, an object oriented language, to develop this project. We also need a chess rulebook of some form and a game engine to ensure the game is developed properly. We aim to create an app with a PVP (player vs player) game interface. With the current time constraints, we will also try to add additional graphics or sound systems to make the game experience more engaging. 


What will be the input/output of our project?

Majority of inputs of the computer will involve operating the chess pieces, as given according to the algorithm. The output will be more focused on the result of those particular moves. Mainly, the input will also contain the current situation of the chess board, track of scores of both players. On the other hand, output should have the future situation after the move, keeping track of new scores and checking to see if the result of the game needed to be declared (win, loss, or draw).  Moreover, we also need to keep track of any killed pieces while playing the chess game. 


What are the features that the project provides?

Playing chess with engaging experience will be the first utmost feature required. Players can enjoy the 2D UI chess game. An accurate chess board representation is also important. Accurate movement of chess pieces as according to physical game rules. Along with that, user interface of input/output is definitely required. 

The navigation diagram provides a layout of the chess game we plan to implement. It consists of multiple screens/windows that will be essential in laying the fundamentals. Such a beginning will display the "Welcome to Chess" message. Along with it, the next movement will shift towards the main menu, and that will provide the user with multiple options such as Start Game (which will prompt the user to begin the game), How to Play (paragraphic guidelines), and Settings (which gives the the user the ability to, for example, change the background color). The Start Game option will initiate the program to run, and the screen will shift from displaying a chess board and will update according to the given movements, captures, checkmates, and restrictions. Finally, the program will end, thus prompting the user to return to the main menu.

![Navigation diagram - Chess project drawio-1](https://user-images.githubusercontent.com/129913303/237000256-ffd5b38c-e532-41e7-9e06-c4d78be98667.png)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

The class diagram represents the number of classes implemented in the program. The "Chess Game" class worked as an all-round class that would initiate the function to run the chess game. The Player class is created to keep track of the players currently playing chess and records the name and color selection. On the other hand, the Display class is used to showcase the chess board and all the chess pieces in the background. The Pieces class acts as a foundation class which consists of all the details, the moves of the pieces, etc. Other subclasses include Pawns, Rooks, Knight, Queens, Bishops, and Kings, and this consists of all the movements. The subclasses also consist of options such as removing the piece when it got captured and checking if the king is captured, which will end the game.

![classdiag](https://github.com/cs100/final-project-rmoha023-ntiwa006-akoks002-swang433-1/assets/129913303/bf0fcb47-6c0f-4608-808d-67ab896f0cd9)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

![layoutproj1](https://github.com/cs100/final-project-rmoha023-ntiwa006-akoks002-swang433-1/assets/129913303/4957ff56-69d9-4e86-950f-209809bf9905)
![layoutporj2](https://github.com/cs100/final-project-rmoha023-ntiwa006-akoks002-swang433-1/assets/129913303/ef1fe7a5-cb31-408e-a652-3575b17f5384)
