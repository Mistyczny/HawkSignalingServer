//
// Created by admin on 7/6/2022.
//
#pragma once
#include <drogon/PubSubService.h>
#include <drogon/drogon.h>
#include <string>

namespace Hawk
{
    struct User
    {
        std::string name;
        drogon::SubscriberID subscriberId;
    };
}
