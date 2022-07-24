//
// Created by admin on 7/12/2022.
//
#pragma once
#include "Hawk/User.hpp"
#include "IUsersPubSubService.hpp"
#include <drogon/PubSubService.h>

namespace Hawk
{
    class UsersPubSubService;
    using UsersPubSubServicePtr = std::shared_ptr<UsersPubSubService>;

    class UsersPubSubService final : public IUsersPubSubService
    {
    public:
        static UsersPubSubServicePtr Create();
        UsersPubSubService();
        ~UsersPubSubService() override;

        /**
         *
         * @param topic
         * @param callback
         * @return
         */
        [[nodiscard]] SubscriberId Subscribe(std::string topic, IUsersPubSubService::SubscribeCallback callback) override;

        /**
         *
         * @param topic
         * @param subscriberId
         */
        void Unsubscribe(std::string topic, SubscriberId subscriberId) override;

        /**
         *
         * @param topic
         * @param message
         */
        void Publish(std::string topic, std::string message) override;
    private:
        drogon::PubSubService<std::string> m_usersPubSubService;
    };
}