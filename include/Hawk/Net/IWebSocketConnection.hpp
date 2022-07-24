//
// Created by admin on 7/13/2022.
//
#pragma once
#include <memory>
#include <string>

namespace Hawk::Net
{
    enum class CloseCode
    {
        kNormalClosure = 1000,
        kEndpointGone = 1001,
        kProtocolError = 1002,
        kInvalidMessage = 1003,
        kNone = 1005,
        kAbnormally = 1006,
        kWrongMessageContent = 1007,
        kViolation = 1008,
        kMessageTooBig = 1009,
        kNeedMoreExtensions = 1010,
        kUnexpectedCondition = 1011,
        kTLSFailed = 1015
    };

    class IWebSocketConnection
    {
    public:
        virtual ~IWebSocketConnection() = default;

        /**
         *
         * @param message
         */
        virtual bool Send(std::string message) = 0;

        /**
         *
         * @param pContext
         * @return
         */
        virtual bool SetContext(std::shared_ptr<void> pContext) = 0;

        /**
         * @brief Check if has context assigned
         * 
         * @return Success, if has context. False otherwise
         */
        virtual bool HasContext() = 0;

        /**
         * @brief Get the Context object
         * 
         * @return void* 
         */
        virtual std::shared_ptr<void*> GetContext() = 0;

        /**
         * @brief 
         * 
         * @param closeCode 
         * @param message 
         */
        virtual void Shutdown(CloseCode closeCode, std::string message) = 0;
    };

    using IWebSocketConnectionPtr = std::shared_ptr<IWebSocketConnection>;
}