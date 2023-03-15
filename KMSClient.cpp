#define _CRT_SECURE_NO_WARNINGS

#include "KMSClient.h"
#include "Log.h"

bool get_process_elevated() noexcept {
    LOG(TRACE) << "Checking process elevation\n";
    bool elevated = false;
    HANDLE token = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token)) {
        TOKEN_ELEVATION elevation;
        DWORD sz = sizeof(TOKEN_ELEVATION);
        if (GetTokenInformation(token, TokenElevation, &elevation, sizeof(elevation), &sz)) {
            elevated = elevation.TokenIsElevated;
        }
        CloseHandle(token);
    }
    LOG(TRACE) << "Process elevation = " << elevated << "\n";
    return elevated;
}


void KMSClient::set_kms_server(const std::wstring& server, uint16_t port) {
    if (!get_process_elevated())
        throw KMSError{ "Process not elevated", 0x1 };

    std::wostringstream command_buffer;
    command_buffer << "cscript //nologo " << getenv("systemroot") << "\\System32\\slmgr.vbs -skms " << server << ":" << port << " >nul 2>nul";
    std::wstring command = command_buffer.str();
    LOG(TRACE) << command << "\n";

    int status = _wsystem(command.c_str());
    if (status)
        throw KMSError{ "Set KMS server error", status };
}

void KMSClient::set_gvlk_key(const std::wstring& key) {
    if (!get_process_elevated())
        throw KMSError{ "Process not elevated", 0x1 };

    std::wostringstream command_buffer;
    command_buffer << "cscript //nologo " << getenv("systemroot") << "\\System32\\slmgr.vbs -ipk " << key << " >nul 2>nul";
    std::wstring command = command_buffer.str();
    LOG(TRACE) << command << "\n";

    int status = _wsystem(command.c_str());
    if (status)
        throw KMSError{ "Set product key error", status };
}

void KMSClient::request_activation() {
    if (!get_process_elevated())
        throw KMSError{ "Process not elevated", 0x1 };

    std::wostringstream command_buffer;
    command_buffer << "cscript //nologo " << getenv("systemroot") << "\\System32\\slmgr.vbs -ato >nul 2>nul";
    std::wstring command = command_buffer.str();
    LOG(TRACE) << command << "\n";

    int status = _wsystem(command.c_str());
    if (status)
        throw KMSError{ "Activation error", status };
}