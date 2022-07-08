#include <Controllers/SignalingController.hpp>
#include <Controllers/UserController.hpp>
#include <UsersManager.hpp>
#include <drogon/drogon.h>

int main()
{
    auto pUsersManager = Hawk::UsersManager::Create();
    auto pUserController = Hawk::UserController::Create(pUsersManager);
    auto pSignalingController = Hawk::SignalingController::Create(pUsersManager);

    drogon::app()
        .setLogLevel(trantor::Logger::kDebug)
        .registerController(pUserController)
        .registerController(pSignalingController)
        .addListener("127.0.0.1", 8080)
        .setThreadNum(4)
        .run();

    return 0;
}
