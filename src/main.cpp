#include "Game.h"

int main() {
    Game game{};
    game.loadContent();
    while (game.isRunning) {
        game.update();
        game.draw();
    }
}