#include <iostream>
#include <vector>
#include <algorithm>

#include "./player.cpp"
#include "./chicken.cpp"
#include "./egg.cpp"

using namespace std;

class EggSystem {
    public:
    Player *player;
    Chicken *chicken;
    vector<Egg*> eggs;

    EggSystem(Player *pl, Chicken *chick) {
        player = pl;
        chicken = chick;
    }

    void tick() {
        vector<int> deadEggs;
        for(int i = 0; i < eggs.size(); i++) {
            eggs[i]->tick();
            if(!eggs[i]->alive) deadEggs.push_back(i);
        }
        reverse(deadEggs.begin(), deadEggs.end());
        for(int x : deadEggs) eggs.erase(eggs.begin() + x);

        // Add eggs
        if(rand() % 100 <= 1) {
            eggs.push_back(new Egg(chicken->curX, chicken->curY));
        }

        // Check for collisions
        for(int i = 0; i < eggs.size(); i++) {
            if(eggs[i]->curX >= player->curX && eggs[i]->curX <= player->curX + 70) {
                if(eggs[i]->curY >= player->curY && eggs[i]->curY <= player->curY + 75) {
                    eggs[i]->alive = false;
                    player->health--;
                }
            }
        }
    }

    void draw() {
        for(Egg *egg : eggs) {
            egg->draw();
        }
    }
};