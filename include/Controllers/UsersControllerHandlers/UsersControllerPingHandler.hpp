//
// Created by admin on 7/8/2022.
//
#pragma once
#include <Controllers/UsersControllerHandlers/IUsersControllerHandler.hpp>

namespace Hawk
{
    class UsersControllerPingHandler;
    using UsersControllerPingHandlerPtr = std::shared_ptr<UsersControllerPingHandler>;

    class UsersControllerPingHandler : public IUsersControllerHandler
    {
    public:
        static UsersControllerPingHandlerPtr Create();
        UsersControllerPingHandler();
        ~UsersControllerPingHandler() override;

        void HandleMessage(std::string message) override;
    private:

    };
}
