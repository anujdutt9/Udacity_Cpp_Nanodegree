#include <iostream>

#define LOG(x) std::cout << x << std::endl

// A class is private by default
class Player{
    public:
    int x, y;
    int speed;

    // pass in the "player" object by reference as we'll be modifying it's value
    void Move(int xa, int ya){
        x += xa * speed;
        y += ya * speed;
    }
};

// // pass in the "player" object by reference as we'll be modifying it's value
// void Move(Player& player, int xa, int ya){
//     player.x += xa * player.speed;
//     player.y += ya * player.speed;
// }

int main(){
    // Create an instance of the class
    // variable "player" (object) of type "Player"
    Player player;
    
    // access and set the values in the class
    player.x = 5;
    player.y = 10;
    player.speed = 20;

    LOG("Player's current location and speed:\n");
    LOG(player.x);
    LOG(player.y);
    LOG(player.speed);

    // move the player, changes x, y position
    // Move(player, 15, 20);
    player.Move(15, 20);

    LOG("Player's new location and speed:\n");
    LOG(player.x);
    LOG(player.y);
    LOG(player.speed);

    return 0;
}