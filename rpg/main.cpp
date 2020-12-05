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
    
    void takeDamage(int str) {
        health -= str;
    }
    
    void print()
    {
        std::cout << "Enemy Type: " << getEnemyTypeAsString(type) << ", health: " << health << "\n";
    }
    
    std::string getTypeString() {
        return getEnemyTypeAsString(type);
    }
    
    void generateNew()
    {
        type = randomEnemyType();
        health = getHealthByType(type);
    }
    
    int getHealth() {
        return health;
    }
    
    bool isDead() {
        return health <= 0;
    }
    
private:
    int health;
    int type;
};

int main() {
    srand(time(NULL));
    
    enum moveType { ATTACK = 1, RUN };
    int input = -1;
    Enemy enemy;
    
    while (input != 0) {
        std::string enemyType = enemy.getTypeString();
        int enemyHP = enemy.getHealth();
        
        std::cout << "\n2A " << enemyType << " with " << enemyHP << "HP approaches. What would you like to do?\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Run\n";
        std::cout << "0. Quit\n\n";
        
        std::cout << "Enter a selection: ";
        std::cin >> input;
        
        switch (input) {
            case ATTACK:
                break;
            case RUN:
                std::cout << "You are too scared of the " << enemyType << " and you run away.\n";
                
                enemy.generateNew();
                break;
            default:
                break;
        }
    }
    return 0;
}
