//
// Created by admin on 7/5/2022.
//

#include "Hawk/Controllers/SignalingController.hpp"
#include <utility>

namespace Hawk
{
    std::shared_ptr<SignalingController> SignalingController::Create(UsersManagerPtr pUsersManager)
    {
        return std::make_shared<SignalingController>(pUsersManager);
    }

    SignalingController::SignalingController(UsersManagerPtr pUsersManager)
        : m_pUsersManager{std::move(pUsersManager)}
    {}

    void SignalingController::PeerMessage(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback)
    {
        Json::Value responseBody{};
        auto response = drogon::HttpResponse::newHttpJsonResponse(responseBody);
        response->setStatusCode(drogon::HttpStatusCode::k200OK);

        callback(response);
    }
}