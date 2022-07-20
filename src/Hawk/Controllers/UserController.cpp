//
// Created by admin on 7/5/2022.
//

#include "Hawk/Controllers/UserController.hpp"

namespace Hawk
{
    std::shared_ptr<UserController> UserController::Create(UsersManagerPtr pUsersManager)
    {
        return std::make_shared<UserController>(pUsersManager);
    }

    UserController::UserController(UsersManagerPtr pUsersManager)
        : m_pUsersManager{std::move(pUsersManager)}
    {}

    void UserController::SignIn(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback)
    {
        const auto& parameters = req->getBody();
        Json::Value requestBody{};
        JSONCPP_STRING error;
        const Json::CharReaderBuilder builder;
        const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

        if(!reader->parse(parameters.data(), parameters.data() + parameters.length(), &requestBody, &error)) {
            ReportError(std::move(callback), drogon::HttpStatusCode::k400BadRequest, error);
            return;
        }

        auto result = m_pUsersManager->RegisterUser(requestBody);
        if(!result) {
            ReportError(std::move(callback), drogon::HttpStatusCode::k401Unauthorized, "Failed to register user");
            return;
        }

        Json::Value responseBody{};
        responseBody["error"] = false;
        auto response = drogon::HttpResponse::newHttpJsonResponse(responseBody);
        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        callback(response);
    }

    void UserController::SignOut(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback)
    {
        Json::Value responseBody{};
        responseBody["error"] = false;

        auto response = drogon::HttpResponse::newHttpJsonResponse(responseBody);
        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        callback(response);
    }

    void UserController::ReportError(std::function<void(const drogon::HttpResponsePtr&)>&& callback,
                                     drogon::HttpStatusCode httpStatusCode,
                                     JSONCPP_STRING error)
    {
        Json::Value responseBody{};
        responseBody["error"] = true;
        responseBody["message"] = error.data();
        auto response = drogon::HttpResponse::newHttpJsonResponse(responseBody);
        response->setStatusCode(httpStatusCode);
        callback(response);
    }
}