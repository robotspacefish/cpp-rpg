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
        gold = rand() % 20;
    }
    
    void takeDamage(int str) {
        health -= str;
    }
    
    int getStrength()
    {
        return maxHealth()/3;
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
        gold = rand() % 20;
    }
    
    int getHealth() {
        return health;
    }
    
    bool isDead() {
        return health <= 0;
    }
    
    int maxHealth() {
        return getHealthByType(type);
    }
    
    int getGold()
    {
        return gold;
    }
    
private:
    int health;
    int type;
    int gold;
};

int main() {
    srand(time(NULL));
    
    enum moveType { ATTACK = 1, RUN };
    int input = -1;
    int strength = 10;
    int health = 100;
    int gold = 0;
    
    Enemy enemy;
    
    while (input != 0) {
        std::string enemyType = enemy.getTypeString();
        int maxHealth = enemy.maxHealth();
        int enemyHP = enemy.getHealth();
        
        if (enemyHP == maxHealth)
            std::cout << "\nA " << enemyType << " with " << enemyHP << "HP approaches.\n";
        else
            std::cout << "\nThe " << enemyType << " has " << enemyHP << "HP left.\n";
        
        std::cout << "You have " << health << "HP and " << strength << " strength.\n\n";
        std::cout << "What would you like to do?\n";
        
        std::cout << "1. Attack\n";
        std::cout << "2. Run\n";
        std::cout << "0. Quit\n\n";
        
        std::cout << "Enter your selection: ";
        std::cin >> input;
        
        switch (input) {
            case ATTACK:
                enemy.takeDamage(strength);
                
                if (enemy.isDead())
                {
                    int enemyGold = enemy.getGold();
                    gold += enemyGold;
                    std::cout << "\nYou defeated the " << enemyType << " and received " << enemyGold << " gold.\n";
                    std::cout << "You have " << gold << " total gold.\n";
                    
                    enemy.generateNew();
                }
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
