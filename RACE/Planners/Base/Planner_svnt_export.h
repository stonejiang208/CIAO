
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl PLANNER_SVNT
// ------------------------------
#ifndef PLANNER_SVNT_EXPORT_H
#define PLANNER_SVNT_EXPORT_H

#include "ace/config-all.h"

#if !defined (PLANNER_SVNT_HAS_DLL)
#  define PLANNER_SVNT_HAS_DLL 1
#endif /* ! PLANNER_SVNT_HAS_DLL */

#if defined (PLANNER_SVNT_HAS_DLL) && (PLANNER_SVNT_HAS_DLL == 1)
#  if defined (PLANNER_SVNT_BUILD_DLL)
#    define PLANNER_SVNT_Export ACE_Proper_Export_Flag
#    define PLANNER_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define PLANNER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* PLANNER_SVNT_BUILD_DLL */
#    define PLANNER_SVNT_Export ACE_Proper_Import_Flag
#    define PLANNER_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define PLANNER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* PLANNER_SVNT_BUILD_DLL */
#else /* PLANNER_SVNT_HAS_DLL == 1 */
#  define PLANNER_SVNT_Export
#  define PLANNER_SVNT_SINGLETON_DECLARATION(T)
#  define PLANNER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* PLANNER_SVNT_HAS_DLL == 1 */

// Set PLANNER_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (PLANNER_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define PLANNER_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define PLANNER_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !PLANNER_SVNT_NTRACE */

#if (PLANNER_SVNT_NTRACE == 1)
#  define PLANNER_SVNT_TRACE(X)
#else /* (PLANNER_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define PLANNER_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (PLANNER_SVNT_NTRACE == 1) */

#endif /* PLANNER_SVNT_EXPORT_H */

// End of auto generated file.
