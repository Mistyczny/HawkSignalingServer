//
// Created by admin on 7/8/2022.
//
#pragma once
#include "IUsersControllerHandler.hpp"
#include <Hawk/IUsersPubSubService.hpp>
#include <memory>

namespace Hawk
{
    class UsersControllerTextHandler;
    using UsersControllerTextHandlerPtr = std::shared_ptr<UsersControllerTextHandler>;

    class UsersControllerTextHandler : public IUsersControllerHandler
    {
    public:
        static UsersControllerTextHandlerPtr Create(IUsersPubSubServicePtr pUsersPubSubService);

        UsersControllerTextHandler(IUsersPubSubServicePtr pUsersPubSubService);
        ~UsersControllerTextHandler() override;

        void HandleMessage(const Context& context) override;

    private:
        IUsersPubSubServicePtr m_pUsersPubSubService;
    };
}