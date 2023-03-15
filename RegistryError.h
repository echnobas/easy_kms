#pragma once
#include <stdexcept>
#include <Windows.h>

class RegistryError : public std::runtime_error {
public:
    RegistryError(const std::string& message, LONG error_code) : std::runtime_error{ message }, m_error_code{ error_code } {}
    LONG error_code() const noexcept { return m_error_code; }
private:
    LONG m_error_code;
};
