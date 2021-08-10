#ifndef EMBEDDED_DIAGNOSTICS_H
#define EMBEDDED_DIAGNOSTICS_H

#include "DiagnosticsFlags.h"

#ifdef TRACE_ENABLED
#include "AVRPlatform.h"
#define traceme trace(__PRETTY_FUNCTION__);

inline AVRPlatform platform{};
inline void trace(const char c[])
{
    // platform.print("TRACE: ");
    platform.print(c);
}
#else
#define traceme
#endif // end of TRACE_ENABLED
#endif // end of EMBEDDED_DIAGNOSTICS_H
