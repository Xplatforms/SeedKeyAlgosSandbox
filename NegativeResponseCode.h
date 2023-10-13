#include <array>
#include <string>
#include <vector>
#include <stdexcept>
#include <string_view>

// Wrapper class around std::string to make it usable in a constexpr context
class NegativeResponseCode {
public:
    constexpr NegativeResponseCode(int code, const char* description) : code(code), description(description) {}
    constexpr const char* getDescription() const { return description; }
    constexpr int getCode() const { return code; }

private:
    int code;
    const char* description;
};

class NegativeUdsResponseCodes {
public:
    static constexpr NegativeResponseCode NRC_SERVICE_NOT_SUPPORTED = NegativeResponseCode(0x11, "Service Not Supported");
    static constexpr NegativeResponseCode NRC_SUBFUNCTION_NOT_SUPPORTED = NegativeResponseCode(0x12, "Subfunction Not Supported");
    static constexpr NegativeResponseCode NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT = NegativeResponseCode(0x13, "Incorrect Message Length Or Invalid Format");
    static constexpr NegativeResponseCode NRC_BUSY_REPEAT_REQUEST = NegativeResponseCode(0x21, "Busy Repeat Request");
    static constexpr NegativeResponseCode NRC_CONDITION_NOT_CORRECT = NegativeResponseCode(0x22, "Condition Not Correct");
    static constexpr NegativeResponseCode NRC_ROUTINE_NOT_COMPLETE = NegativeResponseCode(0x23, "Routine Not Complete");
    static constexpr NegativeResponseCode NRC_REQUEST_SEQUENCE_ERROR = NegativeResponseCode(0x24, "Request Sequence Error");
    static constexpr NegativeResponseCode NRC_REQUEST_OUT_OF_RANGE = NegativeResponseCode(0x31, "Request Out Of Range");
    static constexpr NegativeResponseCode NRC_SECURITY_ACCESS_DENIED = NegativeResponseCode(0x33, "Security Access Denied");
    static constexpr NegativeResponseCode NRC_INVALID_KEY = NegativeResponseCode(0x35, "Invalid Key");
    static constexpr NegativeResponseCode NRC_EXCEED_NUMBER_OF_ATTEMPTS = NegativeResponseCode(0x36, "Exceed Number Of Attempts");
    static constexpr NegativeResponseCode NRC_REQUIRED_TIME_DELAY_NOT_EXPIRED = NegativeResponseCode(0x37, "Required Time Delay Not Expired");
    static constexpr NegativeResponseCode NRC_DOWNLOAD_NOT_ACCEPTED = NegativeResponseCode(0x40, "Download Not Accepted");
    static constexpr NegativeResponseCode NRC_UPLOAD_NOT_ACCEPTED = NegativeResponseCode(0x50, "Upload Not Accepted");
    static constexpr NegativeResponseCode NRC_UPLOAD_DOWNLOAD_NOT_ACCEPTED = NegativeResponseCode(0x70, "Upload Download Not Accepted");
    static constexpr NegativeResponseCode NRC_TRANSFER_SUSPENDED = NegativeResponseCode(0x71, "Transfer Suspended");
    static constexpr NegativeResponseCode NRC_GENARAL_PROGRAMMING_FAILURE = NegativeResponseCode(0x72, "General Programming Failure");
    static constexpr NegativeResponseCode NRC_WRONG_BLOCK_SEQUENCE_COUNTER = NegativeResponseCode(0x73, "Wrong Block Sequence Counter");
    static constexpr NegativeResponseCode NRC_RESPONSE_PENDING = NegativeResponseCode(0x78, "Request Correctly Received-Response Pending");
    static constexpr NegativeResponseCode NRC_SUB_FUNCTION_NOT_SUPPORTED_IN_ACTIVE_DIAGNOSTIC_SESSION = NegativeResponseCode(0x7E, "Sub Function Not Supported In Active Diagnostic Session");
    static constexpr NegativeResponseCode NRC_SERVICE_NOT_SUPPORTED_IN_ACTIVE_DIAGNOSTIC_SESSION = NegativeResponseCode(0x7F, "Service Not Supported In Active Diagnostic Session");
    static constexpr NegativeResponseCode NRC_VOLTAGE_TOO_HIGH = NegativeResponseCode(0x92, "Voltage Too High");
    static constexpr NegativeResponseCode NRC_VOLATAGE_TOO_LOW = NegativeResponseCode(0x93, "Voltage Too Low");
    
    static std::string getNrcDescription(int code){
        for (const auto& nrc : codes_) {
            if (nrc.getCode() == code) {
                return nrc.getDescription();
            }
        }
        return "";
    }

private:
    static const std::vector<NegativeResponseCode> codes_;
};

const std::vector<NegativeResponseCode> NegativeUdsResponseCodes::codes_ = {
    NRC_SERVICE_NOT_SUPPORTED,
    NRC_SUBFUNCTION_NOT_SUPPORTED,
    NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT,
    NRC_BUSY_REPEAT_REQUEST,
    NRC_CONDITION_NOT_CORRECT,
    NRC_ROUTINE_NOT_COMPLETE,
    NRC_REQUEST_SEQUENCE_ERROR,
    NRC_REQUEST_OUT_OF_RANGE,
    NRC_SECURITY_ACCESS_DENIED,
    NRC_INVALID_KEY,
    NRC_EXCEED_NUMBER_OF_ATTEMPTS,
    NRC_REQUIRED_TIME_DELAY_NOT_EXPIRED,
    NRC_DOWNLOAD_NOT_ACCEPTED,
    NRC_UPLOAD_NOT_ACCEPTED,
    NRC_UPLOAD_DOWNLOAD_NOT_ACCEPTED,
    NRC_TRANSFER_SUSPENDED,
    NRC_GENARAL_PROGRAMMING_FAILURE,
    NRC_WRONG_BLOCK_SEQUENCE_COUNTER,
    NRC_RESPONSE_PENDING,
    NRC_SUB_FUNCTION_NOT_SUPPORTED_IN_ACTIVE_DIAGNOSTIC_SESSION,
    NRC_SERVICE_NOT_SUPPORTED_IN_ACTIVE_DIAGNOSTIC_SESSION,
    NRC_VOLTAGE_TOO_HIGH,
    NRC_VOLATAGE_TOO_LOW
};