#include <thread>
#include <iostream>
#include "factorialServer.hpp"
#include "factorialClient.hpp"

void FactorialClientrun() {

    std::string address("0.0.0.0:5000");
    FactorialClient client(grpc::CreateChannel(address, grpc::InsecureChannelCredentials()));

    int response;

    int a = 5;

    response = client.sendRequest(a);
    if (response > 0) {
    std::cout << "Answer received: factorial of " << a <<  " = " << response << std::endl;
    }

    a = 10;

    response = client.sendRequest(a);
    if (response > 0) {
    std::cout << "Answer received: factorial of " << a <<  " = " << response << std::endl;
    }

    a = -2;

    response = client.sendRequest(a);
    if (response > 0) {
    std::cout << "Answer received: factorial of " << a <<  " = " << response << std::endl;
    }

}

int main(int argc, char** argv) {

    FactorialServer server;

    // Threads for server and client
    std::thread serverThread([&server]() {server.run();});
    std::thread clientThread(FactorialClientrun);

    // Wait for threads to complete
    serverThread.join();
    clientThread.join();

    std::cout << "Server and client have completed execution." << std::endl;
    return 0;
}
