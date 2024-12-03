#include <thread>
#include <iostream>

// Declare the server and client main functions
int serverMain(int argc, char** argv);
int clientMain(int argc, char** argv);

int main(int argc, char** argv) {
    // Threads for server and client
    std::thread serverThread(serverMain, argc, argv);
    std::thread clientThread(clientMain, argc, argv);

    // Wait for threads to complete
    serverThread.join();
    clientThread.join();

    std::cout << "Server and client have completed execution." << std::endl;
    return 0;
}
