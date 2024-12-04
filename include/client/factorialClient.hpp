#include <grpcpp/grpcpp.h>
#include "factorial.grpc.pb.h"

class FactorialClient {
    public:
        FactorialClient(std::shared_ptr<grpc::Channel> channel);
        int sendRequest(int a);
        void run ();

    private:
        std::unique_ptr<factorial::FactorialService::Stub> stub_;
};