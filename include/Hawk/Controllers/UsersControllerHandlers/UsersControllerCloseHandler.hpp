//
// Created by admin on 7/8/2022.
//
#pragma once
#include "IUsersControllerHandler.hpp"

namespace Hawk
{
    class UsersControllerCloseHandler;
    using UsersControllerCloseHandlerPtr = std::shared_ptr<UsersControllerCloseHandler>;

    class UsersControllerCloseHandler : public IUsersControllerHandler
    {
    public:
        static UsersControllerCloseHandlerPtr Create();
        UsersControllerCloseHandler();
        ~UsersControllerCloseHandler() override;

        void HandleMessage(std::string&& message) override;
    private:

    };
}
