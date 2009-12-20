/*
   +----------------------------------------------------------------------+
   | PHP Version 5 / aware                                                |
   +----------------------------------------------------------------------+
   | Copyright (c) 2009 Mikko Koppanen                                    |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Mikko Kopppanen <mkoppanen@php.net>                          |
   +----------------------------------------------------------------------+
*/

#ifndef _PHP_AWARE_PRIVATE_H_
# define _PHP_AWARE_PRIVATE_H_

#include "php_aware.h"
#include "php_aware_storage.h"
#include "php_aware_request.h"
#include "php_aware_uuid.h"
#include "php_aware_cache.h"

/* for HAVE_GETTIMEOFDAY */
#ifdef PHP_WIN32
# include "win32/time.h"
#else
# include "main/php_config.h"
#endif

void php_aware_capture_error_ex(zval *event, int type, const char *error_filename, const uint error_lineno, zend_bool free_event, const char *format, va_list args);

void php_aware_invoke_handler(int type TSRMLS_DC, const char *error_filename, const uint error_lineno, const char *format, ...);

#ifndef Z_ADDREF_PP
# define Z_ADDREF_PP(ppz) (*ppz)->refcount++;
#endif


ZEND_BEGIN_MODULE_GLOBALS(aware_private)
	zend_bool enabled;			/* is the module enabled */
	
ZEND_END_MODULE_GLOBALS(aware_private)

ZEND_EXTERN_MODULE_GLOBALS(aware_private)

#ifdef ZTS
# define AWARE_PRIVATE_G(v) TSRMG(aware_private_globals_id, zend_aware_private_globals *, v)
#else
# define AWARE_PRIVATE_G(v) (aware_private_globals.v)
#endif


#endif
