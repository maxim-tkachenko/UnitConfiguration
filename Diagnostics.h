#ifndef EMBEDDED_DIAGNOSTICS_H
#define EMBEDDED_DIAGNOSTICS_H

#include "DiagnosticsFlags.h"

#ifdef TRACE_ENABLED
#include "PlatformFeatures.h"

// use __FUNCTION__ or __func__ instead to reduce
// memory consumption by cutting off member's signature
#ifdef TRACE_VERBOSITY_DETAILED_ENABLED
#define TRACE_VERBOSITY __PRETTY_FUNCTION__
#else
#define TRACE_VERBOSITY __FUNCTION__
#endif

#define traceme trace(TRACE_VERBOSITY);

inline void trace(const char c[])
{
    PlatformFeatures::print("TRACE: ");
    PlatformFeatures::println(c);
}
#else
#define traceme
#endif // end of TRACE_ENABLED
#endif // end of EMBEDDED_DIAGNOSTICS_H
