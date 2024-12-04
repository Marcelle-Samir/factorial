#include <iostream>
#include <string>
#include <grpcpp/grpcpp.h>
#include "factorial.grpc.pb.h"
#include "factorialServer.hpp"

int factorialCalc (int n) {

    int returnVal = 1;
    if (n < 0) {
        std::cout << "Error! Factorial of a negative number doesn't exist." << std::endl;;
        returnVal = 0;
    } else {
        for(int i = 1; i <= n; ++i) {
            returnVal *= i;
        }  
    }
    return returnVal;
}

grpc::Status FactorialServer::sendRequest(grpc::ServerContext* context, const factorial::FactorialRequest* request, factorial::FactorialReply* reply) {

        int a = request->a();
        reply->set_result(factorialCalc(a));
        return grpc::Status::OK;

}

void FactorialServer::run() {

    grpc::ServerBuilder builder;

    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(this);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on port: " << address << std::endl;

    server->Wait();    

}