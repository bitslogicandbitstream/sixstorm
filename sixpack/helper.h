#pragma once

#include <set>
#include <tuple>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdint>
#include <cassert>

#include <stdio.h>
#include <stdarg.h>

#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCTION__
#endif

extern int log_level;
#define log(...) fprintf(stderr, __VA_ARGS__);
#define info(...) do { if (log_level > 0) fprintf(stderr, __VA_ARGS__); } while (0)
#define debug(...) do { if (log_level > 1) fprintf(stderr, __VA_ARGS__); } while (0)
#define error(...) do { fprintf(stderr, "Error: " __VA_ARGS__); exit(1); } while (0)
#define panic(fmt, ...) do { fprintf(stderr, "Internal Error at %s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__); abort(); } while (0)

static inline std::string vstringf(const char *fmt, va_list ap)
{
	std::string string;
	char *str = NULL;

#ifdef _WIN32
	int sz = 64, rc;
	while (1) {
		va_list apc;
		va_copy(apc, ap);
		str = (char*)realloc(str, sz);
		rc = vsnprintf(str, sz, fmt, apc);
		va_end(apc);
		if (rc >= 0 && rc < sz)
			break;
		sz *= 2;
	}
#else
	if (vasprintf(&str, fmt, ap) < 0)
		str = NULL;
#endif

	if (str != NULL) {
		string = str;
		free(str);
	}

	return string;
}

static inline std::string stringf(const char *fmt, ...)
{
	std::string string;
	va_list ap;

	va_start(ap, fmt);
	string = vstringf(fmt, ap);
	va_end(ap);

	return string;
}
