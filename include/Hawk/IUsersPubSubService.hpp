//
// Created by admin on 7/12/2022.
//
#pragma once
#include <cstdint>
#include <string>
#include <functional>

namespace Hawk
{
    class IUsersPubSubService
    {
    public:
        using SubscriberId = uint64_t;
        using SubscribeCallback = std::function<void(const std::string&, const std::string&)>;

        virtual ~IUsersPubSubService() = default;

        /**
         *
         * @param topic
         * @param callback
         * @return
         */
        virtual SubscriberId Subscribe(std::string topic, SubscribeCallback callback) = 0;

        /**
         *
         * @param topic
         * @param subscriberId
         */
        virtual void Unsubscribe(std::string topic, SubscriberId subscriberId) = 0;

        /**
         *
         * @param topic
         * @param message
         */
        virtual void Publish(std::string topic, std::string message) = 0;
    };
}