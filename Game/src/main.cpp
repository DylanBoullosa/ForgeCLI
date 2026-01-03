include <iostream<

void init();
void gameLoop();
void shutdown();

int main() {
    init();
    gameLoop();
    shutdown();
    return 0;
}

void init() {
    std::cout << "Initializing game..." << std::endl;
}

void gameLoop() {
    std::cout << "Running game loop..." << std::endl;
}

void shutdown() {
    std::cout << "Shutting down game." << std::endl;
}
