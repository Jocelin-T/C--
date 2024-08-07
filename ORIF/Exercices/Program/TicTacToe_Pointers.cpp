#include <iostream>
#include <ctime>

// #################################### TicTacToe(Morpion) with pointers ####################################
void drawBoard(char *spaces);
void playerMove(char *spaces, char player, char computer);
void computerMove(char *spaces, char player, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces, char player, char computer);

int main(){
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ 
    // /!\  When using pointers, be careful that your code isn't   /!\ 
    // /!\  dereferencing "nullptr" or pointing to free memory     /!\ 
    // /!\  this will cause undefined behavior !!!                 /!\ 
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ 

    char spaces[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running){
        playerMove(spaces, player, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces, player, computer)){
            running = false;
            break;
        }

        computerMove(spaces, player, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces, player, computer)){
            running = false;
            break;
        }
    }
    
    return 0;
}
// Grid creation
void drawBoard(char *spaces){
    std::cout << "\n";
    std::cout << "       |       |       " << "\n";
    std::cout << "   " << spaces[6] << "   |   " << spaces[7] << "   |   " << spaces[8] << "   " << "\n";
    std::cout << "_______|_______|_______" << "\n";
    std::cout << "       |       |       " << "\n";
    std::cout << "   " << spaces[3] << "   |   " << spaces[4] << "   |   " << spaces[5] << "   " << "\n";
    std::cout << "_______|_______|_______" << "\n";
    std::cout << "       |       |       " << "\n";
    std::cout << "   " << spaces[0] << "   |   " << spaces[1] << "   |   " << spaces[2] << "   " << "\n";
    std::cout << "       |       |       " << "\n";
    std::cout << "\n";

}
void playerMove(char *spaces, char player, char computer){
    int nbr;
    do{
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> nbr;
        nbr--;
        if(spaces[nbr] != player && spaces[nbr] != computer){
            spaces[nbr] = player;
            break;
        }
    }while(!nbr > 0 || !nbr < 8);

}
void computerMove(char *spaces, char player, char computer){
    int nbr;
    srand(time(0));

    while(true){
        nbr = rand() % 9; // Make the random number between 0-8
        std::cout << nbr << "\n";
        if(spaces[nbr] != player && spaces[nbr] != computer){
            spaces[nbr] = computer;
            break;
        }
    }

}
bool checkWinner(char *spaces, char player, char computer){
    std::string playerWin = "********** You Win! **********\n";
    std::string computerWin = "********** You loose! **********\n";

    // Rows check
    if(spaces[6] == spaces[7] && spaces[7] == spaces[8]){ // Row 1
        spaces[6] == player ? std::cout << playerWin : std::cout << computerWin;
    }
    else if(spaces[3] == spaces[4] && spaces[4] == spaces[5]){ // Row 2
        spaces[3] == player ? std::cout << playerWin : std::cout << computerWin;
    }
    else if(spaces[0] == spaces[1] && spaces[1] == spaces[2]){ // Row 3
        spaces[0] == player ? std::cout << playerWin : std::cout << computerWin;
    }
    // Columns check 
    else if(spaces[6] == spaces[3] && spaces[3] == spaces[0]){ // Column 1
        spaces[6] == player ? std::cout << playerWin : std::cout << computerWin;
    }
    else if(spaces[7] == spaces[4] && spaces[4] == spaces[1]){ // Column 2
        spaces[7] == player ? std::cout << playerWin : std::cout << computerWin;
    }
    else if(spaces[8] == spaces[5] && spaces[5] == spaces[2]){ // Column 3
        spaces[8] == player ? std::cout << playerWin : std::cout << computerWin;
    }
    // Diagonal check
    else if(spaces[6] == spaces[4] && spaces[4] == spaces[2]){ // Diagonal TopLeft->BotRight
        spaces[6] == player ? std::cout << playerWin : std::cout << computerWin;
    }
    else if(spaces[0] == spaces[4] && spaces[4] == spaces[8]){ // Diagonal BotLeft->TopRight
        spaces[0] == player ? std::cout << playerWin : std::cout << computerWin;
    }
    // No Winner
    else{
        return false;
    }
    // Winner
    return true;
}
bool checkTie(char *spaces, char player, char computer){
    for(int i = 0; i < 9; i++){
        if(spaces[i] != player && spaces[i] != computer){
            return false;
        }
    }
    std::cout << "It's a tie\n";
    return true;
}
