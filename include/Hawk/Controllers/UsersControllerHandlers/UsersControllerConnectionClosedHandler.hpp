//
// Created by admin on 7/8/2022.
//
#pragma once
#include "IUsersControllerHandler.hpp"

namespace Hawk
{
    class UsersControllerConnectionClosedHandler;
    using UsersControllerConnectionClosedHandlerPtr = std::shared_ptr<UsersControllerConnectionClosedHandler>;

    class UsersControllerConnectionClosedHandler : public IUsersControllerHandler
    {
    public:
        static UsersControllerConnectionClosedHandlerPtr Create();
        UsersControllerConnectionClosedHandler();
        ~UsersControllerConnectionClosedHandler() override;

        void HandleMessage(const Context& context) override;
    private:

    };
}
