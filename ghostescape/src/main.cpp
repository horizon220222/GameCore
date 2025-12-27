//
// Created by 18201 on 2025/12/3.
//

#include "core/game.h"

int main()
{
    Game& game = Game::GetInstance();
    game.init("GHOSTESCAPE", 1280, 720);
    game.run();
}
