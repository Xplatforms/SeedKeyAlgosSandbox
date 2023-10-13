#include <array>

class UdsDiagServices
{
public:
    static constexpr std::array<std::uint8_t, 2> START_DIAGNOSTIC_SESSION_DEFAULT_SESSION = {0x10, 0x01};
    static constexpr std::array<std::uint8_t, 2> START_DIAGNOSTIC_SESSION_PROGRAMMING_SESSION = {0x10, 0x02};
    static constexpr std::array<std::uint8_t, 2> START_DIAGNOSTIC_SESSION_EXTENDED_SESSION = {0x10, 0x03};
    static constexpr std::array<std::uint8_t, 2> CONTROL_DTC_SETTINGS_DTC_SETTINGS_TYPE_ON = {0x85, 0x01};
    static constexpr std::array<std::uint8_t, 2> CONTROL_DTC_SETTINGS_DTC_SETTINGS_TYPE_OFF = {0x85, 0x02};
    static constexpr std::array<std::uint8_t, 2> COMMUNICATION_CONTROL_ENABLE_RX_TX = {0x28, 0x01};
    static constexpr std::array<std::uint8_t, 3> COMMUNICATION_CONTROL_ENABLE_RX_DISABLE_TX = {0x28, 0x01, 0x01};
    static constexpr std::array<std::uint8_t, 3> ROUTINE_CONTROL_ERASE_MEMORY = {0x31, 0x01, 0xFF};
    static constexpr std::array<std::uint8_t, 4> ROUTINE_CONTROL_CHECK_MEMORY_REV_F = {0x31, 0x01, 0xFF, 0x04};
    static constexpr std::array<std::uint8_t, 4> ROUTINE_CONTROL_CHECK_MEMORY_REV_B = {0x31, 0x01, 0xFF, 0x01};
    static constexpr std::array<std::uint8_t, 4> ROUTINE_CONTROL_CONTROL_FAIL_SAFE_REACTION_START = {0x31, 0x01, 0xFF, 0x05};
    static constexpr std::array<std::uint8_t, 4> ROUTINE_CONTROL_CONTROL_FAIL_SAFE_REACTION_STOP = {0x31, 0x02, 0xFF, 0x05};
    static constexpr std::array<std::uint8_t, 4> ROUTINE_CONTROL_CHECK_COMPATIBILITY_DEPENDENCIES{0x31, 0x01, 0xFF, 0x06};
    static constexpr std::array<std::uint8_t, 3> WRITE_DATA_BY_IDENTIFIER_WRITE_FINGERPRINT{0x2E, 0xF1, 0x5A};
    static constexpr std::array<std::uint8_t, 3> WRITE_DATA_BY_IDENTIFIER_ADJUST_ISO_15765_2_PARAMETER_BLOCKSIZE_AND_STMIN{0x2E, 0x01, 0x0B};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_DIAGNOSTIC_SPECIFICATION_INFORMATION{0x22, 0xF1, 0x0D};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_DIAGNOSTIC_SPECIFICATION_VERSION_INFORMATION{0x22, 0xF1, 0x9C};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_ADJUST_PARAMETER_BLOCKSIZE_AND_STMIN{0x22, 0x01, 0x0B};
    static constexpr std::array<std::uint8_t, 2> READ_DATA_BY_IDENTIFIER_READ_ACTIVE_DIAGNOSTIC_INFORMATION{0x22, 0xF1};
    static constexpr std::array<std::uint8_t, 2> READ_DATA_BY_IDENTIFIER_READ_PROGRAMMING_ATTEMPT_COUNTER{0x22, 0x01};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_READ_FINGERPRINT{0x22, 0xF1, 0x5B};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_READ_HARDWARE_PARTNUMBER{0x22, 0xF1, 0x11};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_READ_SOFTWARE_PART_NUMBER{0x22, 0xF1, 0x21};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_READ_HARDWARE_VERSION_INFORMATION{0x22, 0xF1, 0x50};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_READ_SOFTWARE_VERSION_INFORMATION{0x22, 0xF1, 0x51};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_READ_BOOT_SOFTWARE_VERSION_INFORMATION = {0x22, 0xF1, 0x53};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_READ_HARDWARE_SUPPLIER_IDENTIFICATION = {0x22, 0xF1, 0x54};
    static constexpr std::array<std::uint8_t, 3> READ_DATA_BY_IDENTIFIER_READ_SOFTWARE_SUPPLIER_IDENTIFICATION = {0x22, 0xF1, 0x55};
    static constexpr std::array<std::uint8_t, 2> SECURITY_ACCESS_REQUEST_SEED_LEVEL_5{0x27, 0x05};
    static constexpr std::array<std::uint8_t, 2> SECURITY_ACCESS_REQUEST_SEED_LEVEL_11{0x27, 0x11};
    static constexpr std::array<std::uint8_t, 2> SECURITY_ACCESS_SEND_KEY_LEVEL_6{0x27, 0x06};
    static constexpr std::array<std::uint8_t, 2> SECURITY_ACCESS_SEND_KEY_LEVEL_12{0x27, 0x12};
    static constexpr std::array<std::uint8_t, 2> ECU_RESET_HARD_RESET{0x11, 0x01};
    static constexpr std::array<std::uint8_t, 2> ECU_RESET_SOFT_RESET{0x11, 0x03};
    static constexpr std::uint8_t REQUEST_DOWNLOAD = 0x34;
    static constexpr std::uint8_t REQUEST_UPLOAD = 0x35;
    static constexpr std::uint8_t TRANSFER_DATA = 0x36;
    static constexpr std::uint8_t REQUEST_TRANSFER_EXIT = 0x37;
    static constexpr std::uint8_t TESTER_PRESENT = 0x3E;
};
