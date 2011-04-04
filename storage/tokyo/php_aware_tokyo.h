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

#ifndef _PHP_AWARE_TOKYO_H_
# define _PHP_AWARE_TOKYO_H_

#define PHP_AWARE_TOKYO_EXTVER "0.0.1-dev"

#include "php.h"
#include "php_ini.h"

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "../../php_aware.h"
#include "../../php_aware_storage.h"

#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "php_aware_tokyo_cabinet.h"
#include "php_aware_tokyo_tyrant.h"

typedef enum _AwareTokyoBackend {
	AwareTokyoBackendNotSet,
	AwareTokyoBackendCabinet,
	AwareTokyoBackendTyrant
} AwareTokyoBackend;

ZEND_BEGIN_MODULE_GLOBALS(aware_tokyo)
	AwareTokyoBackend backend;
	
	char *backend_str;
	
	char *tyrant_host;
	long tyrant_port;
	
	char *cabinet_file;
	zend_bool cabinet_block;
	
	/* cabinet handle */
	TCTDB *cabinet;
	
	/* tyrant connection */
	TCRDB *tyrant;
	
	zend_bool enabled;

ZEND_END_MODULE_GLOBALS(aware_tokyo)

ZEND_EXTERN_MODULE_GLOBALS(aware_tokyo)

#ifdef ZTS
# define AWARE_TOKYO_G(v) TSRMG(aware_tokyo_globals_id, zend_aware_tokyo_globals *, v)
#else
# define AWARE_TOKYO_G(v) (aware_tokyo_globals.v)
#endif

/* Hook into aware module */
extern php_aware_storage_module php_aware_storage_module_tokyo;
#define php_aware_storage_module_tokyo_ptr &php_aware_storage_module_tokyo

/* Normal PHP entry */
extern zend_module_entry aware_tokyo_module_entry;
#define phpext_aware_tokyo_ptr &aware_tokyo_module_entry

PHP_AWARE_STORAGE_FUNCS(tokyo);

#endif
