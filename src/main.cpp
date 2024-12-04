#include <thread>
#include <iostream>
#include "factorialServer.hpp"
#include "factorialClient.hpp"

void FactorialClientrun() {

    std::string address("0.0.0.0:5000");
    FactorialClient client(grpc::CreateChannel(address, grpc::InsecureChannelCredentials()));
    int response;

    while (true) {

        std::string input;
        std::cout << "Enter a number to compute it's factorial:     ";
        std::getline(std::cin, input); // Read the entire line as a string

        response = client.sendRequest(input);
        if (response > 0) {

            std::cout << "Answer received = " << response << std::endl;

        }

    }

}

int main(int argc, char** argv) {

    FactorialServer server("0.0.0.0:5000");

    // Threads for server and client
    std::thread serverThread([&server]() {server.run();});
    std::thread clientThread(FactorialClientrun);

    // Wait for threads to complete
    serverThread.join();
    clientThread.join();

    std::cout << "Server and client have completed execution." << std::endl;
    return 0;
}
