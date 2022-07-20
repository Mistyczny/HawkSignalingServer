//
// Created by admin on 7/12/2022.
//

#include <Hawk/UsersPubSubService.hpp>
#include <iostream>

namespace Hawk
{
    UsersPubSubServicePtr UsersPubSubService::Create()
    {
        return std::make_shared<UsersPubSubService>();
    }

    UsersPubSubService::UsersPubSubService()
    {
        std::cout << "UsersPubSubService::UsersPubSubService" << std::endl;
    }

    UsersPubSubService::~UsersPubSubService()
    {
        std::cout << "UsersPubSubService::~UsersPubSubService" << std::endl;
    }

    IUsersPubSubService::SubscriberId UsersPubSubService::Subscribe(std::string topic, IUsersPubSubService::SubscribeCallback callback)
    {
        return m_usersPubSubService.subscribe(topic, callback);
    }

    void UsersPubSubService::Unsubscribe(std::string topic, IUsersPubSubService::SubscriberId subscriberId)
    {
        m_usersPubSubService.unsubscribe(topic, subscriberId);
    }

    void UsersPubSubService::Publish(std::string topic, std::string message)
    {
        m_usersPubSubService.publish(topic, message);
    }
}
