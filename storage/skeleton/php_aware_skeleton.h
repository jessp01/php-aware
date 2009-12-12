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

#ifndef _PHP_AWARE_SKELETON_H_
# define _PHP_AWARE_SKELETON_H_

#define PHP_AWARE_SKELETON_EXTVER "0.0.1-dev"

#include "php.h"
#include "php_ini.h"

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef ZTS
# include "TSRM.h"
#endif

#include <ext/aware/php_aware.h>
#include <ext/aware/php_aware_storage.h>

ZEND_BEGIN_MODULE_GLOBALS(aware_skeleton)
	char *foobar;
	zend_bool enabled;
ZEND_END_MODULE_GLOBALS(aware_skeleton)

ZEND_EXTERN_MODULE_GLOBALS(aware_skeleton)

#ifdef ZTS
# define AWARE_SKELETON_G(v) TSRMG(aware_skeleton_globals_id, zend_aware_skeleton_globals *, v)
#else
# define AWARE_SKELETON_G(v) (aware_skeleton_globals.v)
#endif

/* Hook into aware module */
extern php_aware_storage_module php_aware_storage_module_skeleton;
#define php_aware_storage_module_skeleton_ptr &php_aware_storage_module_skeleton

/* Normal PHP entry */
extern zend_module_entry aware_skeleton_module_entry;
#define phpext_aware_skeleton_ptr &aware_skeleton_module_entry

PHP_AWARE_STORAGE_FUNCS(skeleton);

#endif