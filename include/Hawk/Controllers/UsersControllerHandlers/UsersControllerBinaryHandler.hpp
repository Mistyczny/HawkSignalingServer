//
// Created by admin on 7/8/2022.
//
#pragma once
#include "IUsersControllerHandler.hpp"

namespace Hawk
{
    class UsersControllerBinaryHandler;
    using UsersControllerBinaryHandlerPtr = std::shared_ptr<UsersControllerBinaryHandler>;

    class UsersControllerBinaryHandler : public IUsersControllerHandler
    {
    public:
        static UsersControllerBinaryHandlerPtr Create();
        UsersControllerBinaryHandler();
        ~UsersControllerBinaryHandler() override;

        void HandleMessage(std::string&& message) override;
    private:

    };
}
