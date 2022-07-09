//
// Created by admin on 7/8/2022.
//
#pragma once
#include <Controllers/UsersControllerHandlers/IUsersControllerHandler.hpp>
#include <memory>

namespace Hawk
{
    class UsersControllerPongHandler;
    using UsersControllerPongHandlerPtr = std::shared_ptr<UsersControllerPongHandler>;

    class UsersControllerPongHandler : public IUsersControllerHandler
    {
    public:
        static UsersControllerPongHandlerPtr Create();

        UsersControllerPongHandler();
        ~UsersControllerPongHandler() override;

        void HandleMessage(std::string message) override;
    private:

    };
}