#include "Python.h"

extern void _PyWarnings_Init(void);
extern void PyMarshal_Init(void);
extern void initarray(void);
extern void initimp(void);
extern void init_io(void);

struct _inittab _PyImport_Inittab[] = {
	
    {"array", initarray},
/*
    {"_ast", init_ast},
	{"binascii", initbinascii},
    {"cmath", initcmath},
    {"errno", initerrno},
    {"future_builtins", initfuture_builtins},
    {"gc", initgc},
    {"math", initmath},
    {"_md5", init_md5},
    {"operator", initoperator},
    {"signal", initsignal},
    {"_sha", init_sha},
    {"_sha256", init_sha256},
    {"_sha512", init_sha512},
    {"strop", initstrop},
    {"time", inittime},
#ifdef WITH_THREAD
    {"thread", initthread},
#endif
    {"cStringIO", initcStringIO},
    {"cPickle", initcPickle},
    {"_subprocess", init_subprocess},
	
    {"_codecs", init_codecs},
    {"_weakref", init_weakref},
    {"_hotshot", init_hotshot},
    {"_random", init_random},
    {"_bisect", init_bisect},
    {"_heapq", init_heapq},
    {"_lsprof", init_lsprof},
    {"itertools", inititertools},
    {"_collections", init_collections},
    {"_symtable", init_symtable},
    {"mmap", initmmap},
    {"_csv", init_csv},
    {"_sre", init_sre},
    {"parser", initparser},
    {"_winreg", init_winreg},
    {"_struct", init_struct},
    {"datetime", initdatetime},
    {"_functools", init_functools},
    {"_json", init_json},
	
    {"xxsubtype", initxxsubtype},
    {"zipimport", initzipimport},
    {"zlib", initzlib},
	
    {"_multibytecodec", init_multibytecodec},
    {"_codecs_cn", init_codecs_cn},
    {"_codecs_hk", init_codecs_hk},
    {"_codecs_iso2022", init_codecs_iso2022},
    {"_codecs_jp", init_codecs_jp},
    {"_codecs_kr", init_codecs_kr},
    {"_codecs_tw", init_codecs_tw},
*/
	
    /* This module "lives in" with marshal.c */
    {"marshal", PyMarshal_Init},
	
    /* This lives it with import.c */
    {"imp", initimp},
	
    /* These entries are here for sys.builtin_module_names */
    {"__main__", NULL},
    {"__builtin__", NULL},
    {"sys", NULL},
    {"exceptions", NULL},
    {"_warnings", _PyWarnings_Init},
	
    {"_io", init_io},
	
    /* Sentinel */
    {0, 0}
};
