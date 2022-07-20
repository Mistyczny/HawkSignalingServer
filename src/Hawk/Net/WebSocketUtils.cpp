//
// Created by admin on 7/14/2022.
//

#include <Hawk/Net/WebSocketUtils.hpp>

namespace Hawk::Net
{
    CloseCode TranslateCloseCode(drogon::CloseCode closeCode)
    {
        switch (closeCode)
        {
            case drogon::CloseCode::kNormalClosure:
                return CloseCode::kNormalClosure;
            case drogon::CloseCode::kEndpointGone:
                return CloseCode::kEndpointGone;
            case drogon::CloseCode::kProtocolError:
                return CloseCode::kProtocolError;
            case drogon::CloseCode::kInvalidMessage:
                return CloseCode::kInvalidMessage;
            case drogon::CloseCode::kNone:
                return CloseCode::kNone;
            case drogon::CloseCode::kAbnormally:
                return CloseCode::kAbnormally;
            case drogon::CloseCode::kWrongMessageContent:
                return CloseCode::kWrongMessageContent;
            case drogon::CloseCode::kViolation:
                return CloseCode::kViolation;
            case drogon::CloseCode::kMessageTooBig:
                return CloseCode::kMessageTooBig;
            case drogon::CloseCode::kNeedMoreExtensions:
                return CloseCode::kNeedMoreExtensions;
            case drogon::CloseCode::kUnexpectedCondition:
                return CloseCode::kUnexpectedCondition;
            case drogon::CloseCode::kTLSFailed:
                return CloseCode::kTLSFailed;
            default:
                break;
        }
        return CloseCode::kNone;
    }

    drogon::CloseCode TranslateCloseCode(CloseCode closeCode)
    {
        switch (closeCode)
        {
            case CloseCode::kNormalClosure:
                return drogon::CloseCode::kNormalClosure;
            case CloseCode::kEndpointGone:
                return drogon::CloseCode::kEndpointGone;
            case CloseCode::kProtocolError:
                return drogon::CloseCode::kProtocolError;
            case CloseCode::kInvalidMessage:
                return drogon::CloseCode::kInvalidMessage;
            case CloseCode::kNone:
                return drogon::CloseCode::kNone;
            case CloseCode::kAbnormally:
                return drogon::CloseCode::kAbnormally;
            case CloseCode::kWrongMessageContent:
                return drogon::CloseCode::kWrongMessageContent;
            case CloseCode::kViolation:
                return drogon::CloseCode::kViolation;
            case CloseCode::kMessageTooBig:
                return drogon::CloseCode::kMessageTooBig;
            case CloseCode::kNeedMoreExtensions:
                return drogon::CloseCode::kNeedMoreExtensions;
            case CloseCode::kUnexpectedCondition:
                return drogon::CloseCode::kUnexpectedCondition;
            case CloseCode::kTLSFailed:
                return drogon::CloseCode::kTLSFailed;
            default:
                break;
        }
        return drogon::CloseCode::kNone;
    }
}
