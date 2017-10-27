#include <iostream>

using namespace std;

#include "Model/Player.h"
#include "Command/CommandParser.h"

int main() {
    Player *player = new Player();
    string commandLine;
    while(getline(cin,commandLine) && commandLine != "exit") {
        Command *command = CommandParser::parse(commandLine, player);
        if (command != nullptr) {
            cout << command->execute() << endl;
        } else {
            cout << "Unknown command" << endl;
        }
    }
    return 0;
}