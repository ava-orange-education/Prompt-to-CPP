#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#ifdef ENABLE_DEBUG_TRACE

#define TRACE(msg)                                                                                                     \
    do                                                                                                                 \
    {                                                                                                                  \
        std::cerr << "[TRACE] " << __FILE__ << ":" << __LINE__ << " (" << __func__ << "): " << msg << '\n';            \
    } while (0)

class TraceScope
{
  public:
    TraceScope(const char *file, int line, const char *func) : m_file(file), m_line(line), m_func(func)
    {
        std::cerr << "[TRACE] ENTER " << m_file << ":" << m_line << " (" << m_func << ")\n";
    }

    ~TraceScope()
    {
        std::cerr << "[TRACE] EXIT  " << m_file << ":" << m_line << " (" << m_func << ")\n";
    }

  private:
    const char *m_file;
    int m_line;
    const char *m_func;
};

#define TRACE_SCOPE TraceScope traceScopeInstance(__FILE__, __LINE__, __func__)

#else

#define TRACE(msg)                                                                                                     \
    do                                                                                                                 \
    {                                                                                                                  \
    } while (0)
#define TRACE_SCOPE

#endif

#endif
