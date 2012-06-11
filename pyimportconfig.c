#include "Python.h"

extern void _PyWarnings_Init(void);
extern void PyMarshal_Init(void);
extern void initarray(void);
extern void initimp(void);
extern void init_io(void);
extern void init_csv(void);
extern void inititertools(void);
extern void init_collections(void);
extern void initoperator(void);
extern void initmath(void);
extern void initerrno(void);
extern void initgc(void);
extern void initposix(void);
extern void init_weakref(void);
extern void init_sre(void);

struct _inittab _PyImport_Inittab[] = {
	
    {"array", initarray},
    {"_csv", init_csv},
    {"itertools", inititertools},
    {"_collections", init_collections},
    {"operator", initoperator},
    {"math", initmath},
    {"errno", initerrno},
    {"gc", initgc},
	{"posix", initposix},
    {"_weakref", init_weakref},
    {"_sre", init_sre},
/*
    {"_ast", init_ast},
	{"binascii", initbinascii},
    {"cmath", initcmath},
    {"future_builtins", initfuture_builtins},
    {"_md5", init_md5},
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
    {"_hotshot", init_hotshot},
    {"_random", init_random},
    {"_bisect", init_bisect},
    {"_heapq", init_heapq},
    {"_lsprof", init_lsprof},
    {"_symtable", init_symtable},
    {"mmap", initmmap},
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
