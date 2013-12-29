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
extern void init_codecs(void);
extern void initcStringIO(void);
extern void inittime(void);
extern void initdatetime(void);
extern void init_sha(void);
extern void init_sha256(void);
extern void init_sha512(void);
extern void init_md5(void);
extern void init_json(void);
extern void initzlib(void);
extern void init_struct(void);
extern void init_functools(void);
#ifdef WITH_THREAD
extern void initthread(void);
#endif
extern void initbinascii(void);
extern void init_random(void);
extern void init_socket(void);
extern void init_ssl(void);
extern void initzlib(void);
extern void initselect(void);
extern void initsignal(void);
extern void initfcntl(void);
extern void initzipimport(void);
extern void initpyexpat(void);
extern void init_sqlite3(void);
extern void init_ctypes(void);
extern void inittermios(void);
extern void init_scproxy(void);
extern void init_multiprocessing(void);
extern void initcPickle(void);

#ifdef WITH_PYCRYPTO
extern void init_PyCrypto(void);
#endif

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
    {"_codecs", init_codecs},
    {"cStringIO", initcStringIO},
    {"time", inittime},
    {"datetime", initdatetime},
    {"_sha", init_sha},
    {"_sha256", init_sha256},
    {"_sha512", init_sha512},
    {"_md5", init_md5},
    {"_json", init_json},
    {"_struct", init_struct},
    {"_functools", init_functools},
#ifdef WITH_THREAD
    {"thread", initthread},
#endif
	{"binascii", initbinascii},
	{"_random", init_random},
	{"_socket", init_socket},
	{"_ssl", init_ssl},
	{"zlib", initzlib},
	{"select", initselect},
	{"signal", initsignal},
	{"fcntl", initfcntl},
    {"zipimport", initzipimport},
	{"pyexpat", initpyexpat},
	{"_sqlite3", init_sqlite3},
	{"_ctypes", init_ctypes},
	{"termios", inittermios},
	{"_scproxy", init_scproxy},
	{"_multiprocessing", init_multiprocessing},
    {"cPickle", initcPickle},
	
/*
    {"_ast", init_ast},
    {"cmath", initcmath},
    {"future_builtins", initfuture_builtins},
    {"strop", initstrop},
    {"_subprocess", init_subprocess},
	
    {"_hotshot", init_hotshot},
    {"_bisect", init_bisect},
    {"_heapq", init_heapq},
    {"_lsprof", init_lsprof},
    {"_symtable", init_symtable},
    {"mmap", initmmap},
    {"parser", initparser},
    {"_winreg", init_winreg},
	
    {"xxsubtype", initxxsubtype},
	
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

#ifdef WITH_PYCRYPTO
	{"Crypto", init_PyCrypto},
#endif
	
    /* Sentinel */
    {0, 0}
};
