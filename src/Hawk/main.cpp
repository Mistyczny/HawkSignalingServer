#include "Hawk/PubSubServices/UsersPubSubService.hpp"
#include <Hawk/Controllers/SignalingController.hpp>
#include <Hawk/Controllers/UserController.hpp>
#include <Hawk/Controllers/UsersController.hpp>
#include <Hawk/Controllers/UsersControllerHandlers/UsersControllerHandlersFactory.hpp>
#include <Hawk/UsersManager.hpp>
#include <drogon/drogon.h>

int main()
{
    auto pUsersManager = Hawk::UsersManager::Create();
    auto pUsersPubSubService = Hawk::UsersPubSubService::Create();
    auto pUserController = Hawk::UserController::Create(pUsersManager, pUsersPubSubService);
    auto pUsersControllerHandlersFactory = Hawk::UsersControllerHandlersFactory::Create(pUsersManager, pUsersPubSubService);
    auto pUsersController = Hawk::UsersController::Create(pUsersManager, pUsersPubSubService, std::move(pUsersControllerHandlersFactory));
    auto pSignalingController = Hawk::SignalingController::Create(pUsersManager);

    drogon::app()
        .setLogLevel(trantor::Logger::kDebug)
        .registerController(pUserController)
        .registerController(pUsersController)
        .registerController(pSignalingController)
        .addListener("127.0.0.1", 8080)
        .setThreadNum(4)
        .run();

    return 0;
}
