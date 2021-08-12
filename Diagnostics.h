#ifndef EMBEDDED_DIAGNOSTICS_H
#define EMBEDDED_DIAGNOSTICS_H

#include "DiagnosticsFlags.h"

#ifdef TRACE_ENABLED
#include "AVRPlatform.h"

// use __FUNCTION__ or __func__ instead to reduce
// memory consumption by cutting off member's signature
#define traceme trace(__PRETTY_FUNCTION__);

inline AVRPlatform platform{};
inline void trace(const char c[])
{
    platform.print("TRACE: ");
    platform.println(c);
}
#else
#define traceme
#endif // end of TRACE_ENABLED
#endif // end of EMBEDDED_DIAGNOSTICS_H
