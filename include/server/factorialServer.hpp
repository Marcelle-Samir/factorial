#include <grpcpp/grpcpp.h>
#include "factorial.grpc.pb.h"

class FactorialServer final : public factorial::FactorialService::Service {

    public:
        void run();
        grpc::Status sendRequest(grpc::ServerContext* context, const factorial::FactorialRequest* request, factorial::FactorialReply* reply) override;

    private:
        std::string address = "0.0.0.0:5000";
};