# cc3k  
This is the final project for one course in UW.  
Set up tips & instruction  
1. Rules can be found in _cc3k-villain.pdf_  
2. This C++ program can be only run in Linux  
3. Download all the files, use $>make in the root directory to generate the executable.  
4. ./cc3k to start the game, additional coomand lines are:  
* The command line option -WASD will activate the WASD control, when this activeted the PC can only walk towards north, south, west and east. And the program will automatically decide your action: 
If there is an enemy at that direction, it will attack that enemy; If there is a potion at that direction,
it will use that potion. Otherwise, it will walk towards that direction. Other commands such as f,q,r,
still work as before.  
* The command line option -RandomMap will make the game start to use a random generated map,
a new map will be automatically generated whenever a new game starts. As the default map,
a new map contains 5 floors, and each floor has 5 chambers, the enemies and items are generated
exactly the same with the default one. Notice that when random map is activated, the command line
option of using custom map will no longer available even if the name has been input.  
