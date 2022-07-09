#include <Controllers/SignalingController.hpp>
#include <Controllers/UserController.hpp>
#include <Controllers/UsersController.hpp>
#include <Controllers/UsersControllerHandlers/IUsersControllerHandlersFactory.hpp>
#include <Controllers/UsersControllerHandlers/UsersControllerHandlersFactory.hpp>
#include <UsersManager.hpp>
#include <drogon/drogon.h>

int main()
{
    auto pUsersManager = Hawk::UsersManager::Create();
    auto pUserController = Hawk::UserController::Create(pUsersManager);
    auto pUsersControllerHandlersFactory = Hawk::UsersControllerHandlersFactory::Create();
    auto pUsersController = Hawk::UsersController::Create(pUsersManager, std::move(pUsersControllerHandlersFactory));
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
