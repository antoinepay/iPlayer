#include <iostream>

using namespace std;

#include "Model/Player.h"
#include "Command/CommandParser.h"

int main() {
    cout << "Imaginary Player v1.0" << endl;
    Player *player = new Player();
    string commandLine;
    cout << endl << ">>> ";
    while(getline(cin,commandLine) && commandLine != "exit") {
        Command *command = CommandParser::parse(commandLine, player);
        if (command != nullptr) {
            cout << command->execute() << endl;
        } else {
            cout << "Unknown command" << endl;
        }
        cout << endl;
        cout << ">>> " + player->displayPlaylist();
    }
    return 0;
}