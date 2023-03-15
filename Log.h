#pragma once
#include <iostream>

enum LOGGER__INTERNAL_LOG_LEVEL {
	TRACE = 0,
	RAW = 1,
	INFO = 2,
	WARN = 3,
	FATAL = 4,
};

template <LOGGER__INTERNAL_LOG_LEVEL l>
constexpr const char* const LOGGER__INTERNAL_LOG_LEVEL_STR()
{
	static_assert(l >= TRACE && l <= FATAL);
	switch (l) {
	case 0:
		return "TRACE";
	case 1:
		return "RAW";
	case 2:
		return "INFO";
	case 3:
		return "WARN";
	case 4:
		return "FATAL";
	}
	__assume(0);
}

template <LOGGER__INTERNAL_LOG_LEVEL l>
class LOGGER__INTERNAL_LOG {
public:
	LOGGER__INTERNAL_LOG(const char* const file, const char* const func, int line, std::wostream& os) : os(os)
	{
#ifndef _DEBUG
		if (l > 2) {
			os << LOGGER__INTERNAL_LOG_LEVEL_STR<l>() << " :: ";
		}
#else
		os << "log#" << LOGGER__INTERNAL_LOG_LEVEL_STR<l>() << " " << file << ":" << line << "@" << func << ": ";
#endif
	}
	LOGGER__INTERNAL_LOG& operator<<(std::wostream& (*f)(std::wostream&)) {
#ifndef _DEBUG
		if (l)
#endif
		f(os);
		return *this;
	}

	template<typename T>
	LOGGER__INTERNAL_LOG& operator<<(const T& t)
	{
#ifndef _DEBUG
		if (l)
#endif
		os << t;
		return *this;
	}
	~LOGGER__INTERNAL_LOG()
	{
	
	}
private:
	std::wostream& os;
};

//#ifdef ELOG_ENABLED
#define LOG(level) LOGGER__INTERNAL_LOG<level>(__FILE__, __func__, __LINE__, std::wcout)
//#else
//#define LOG(level) if (0) std::wcerr // noop
//#endif