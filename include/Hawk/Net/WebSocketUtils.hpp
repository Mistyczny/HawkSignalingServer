//
// Created by admin on 7/14/2022.
//
#pragma once
#include <Hawk/Net/IWebSocketConnection.hpp>
#include <drogon/WebSocketConnection.h>

namespace Hawk::Net
{
    CloseCode TranslateCloseCode(drogon::CloseCode closeCode);
    drogon::CloseCode TranslateCloseCode(CloseCode closeCode);


}
