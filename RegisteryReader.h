#pragma once
#include <string>
#include <Windows.h>
#include "RegistryError.h"
#include "Log.h"

class RegistryReader {
public:
    RegistryReader(const std::wstring& key, const std::wstring& location) : m_key(key), m_location(location) {}
    std::wstring read_wstr() {
        LSTATUS status = 0;
        DWORD buffer_sz = 0;
        std::wstring buffer;
        // Calculate size
        if (status = RegGetValueW(HKEY_LOCAL_MACHINE, this->m_location.c_str(), this->m_key.c_str(), RRF_RT_REG_SZ, nullptr, nullptr, &buffer_sz) != ERROR_SUCCESS)
            throw RegistryError{ "Reading registry key failed (preallocation)", status };
        LOG(TRACE) << "Allocating block size " << buffer_sz << "\n";
        // Reserve buffer, convert bytes to WCHARs, omit NUL
        buffer.resize((buffer_sz / sizeof(wchar_t)) - sizeof(wchar_t));
        // Read to buffer
        LOG(TRACE) << "Reading to buffer (" << buffer_sz << ")\n";
        if (status = RegGetValueW(HKEY_LOCAL_MACHINE, this->m_location.c_str(), this->m_key.c_str(), RRF_RT_REG_SZ, nullptr, &buffer[0], &buffer_sz) != ERROR_SUCCESS)
            throw RegistryError{ "Reading registry key failed (write)", status };
        buffer.shrink_to_fit();
        return buffer;
    }
private:
    const std::wstring& m_key;
    const std::wstring& m_location;
};