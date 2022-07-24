//
// Created by admin on 7/8/2022.
//
#pragma once
#include "IUsersControllerHandler.hpp"
#include <memory>

namespace Hawk
{
    class UsersControllerTextHandler;
    using UsersControllerTextHandlerPtr = std::shared_ptr<UsersControllerTextHandler>;

    class UsersControllerTextHandler : public IUsersControllerHandler
    {
    public:
        static UsersControllerTextHandlerPtr Create();

        UsersControllerTextHandler();
        ~UsersControllerTextHandler() override;

        void HandleMessage(std::string&& message) override;
    private:

    };
}