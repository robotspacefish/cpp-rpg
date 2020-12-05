//
//  main.cpp
//  rpg
//
//  Created by Jess on 12/3/20.
//

#include <iostream>
#include <string>
#include <ctime>

enum characterType { PLAYER, OGRE, GOBLIN, SLIME, SKELLY };

int randomEnemyType() {
    return rand() % 4 + 1;
}

std::string getEnemyTypeAsString(int type)
{
    switch (type) {
        case OGRE:
            return "Ogre";
        case GOBLIN:
            return "Goblin";
        case SLIME:
            return "Slime";
        case SKELLY:
            return "Skelly";
        default:
            return "Invalid Enemy Type";
    }
}

int getHealthByType(int type) {
    switch (type) {
        case OGRE:
            return 40;
        case GOBLIN:
            return 30;
        case SKELLY:
            return 20;
        case SLIME:
            return 10;
        default:
            return 0;
    }
}

class Enemy
{
public:
    Enemy()
    {
        type = randomEnemyType();
        health = getHealthByType(type);
    }
    
    void print()
    {
        std::cout << "Enemy Type: " << getEnemyTypeAsString(type) << ", health: " << health << "\n";
    }
    
private:
    int health;
    int type;
};

int main() {
    srand(time_t(NULL));
    
//    enum moveType { ATTACK = 1, RUN };
    int input = 0;
    
    while (input != 2) {
        std::cout << "1. Generate Enemy\n";
        std::cout << "2. Quit\n\n";
        
        std::cout << "Enter a selection: ";
        std::cin >> input;
        
        switch (input) {
            case 1:
                std::cout << "Enemy Type: " << getEnemyTypeAsString(randomEnemyType()) << "\n";
                break;
            case 2:
                std::cout << "Goodbye!";
            default:
                std::cout << "Invalid selection";
                break;
        }
    }
    return 0;
}
