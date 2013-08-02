
#include "Python.h"
#include "osdefs.h"
#include <sys/types.h>
#include <string.h>

extern char *Py_GetProgramName(void);

static int pathCalculated = 0; 
static char progPath[MAXPATHLEN+1];
static char pylibPath[MAXPATHLEN+1];
static char modulePathes[4*MAXPATHLEN+1];
static char execPrefixPath[2*MAXPATHLEN+1];

static char* removeLastDir(char* dir, char* p) {
	while(--p > dir) {
		if(*p == '/') {
			*p = 0;
			break;
		}
	}
	return p;
}

static void calcPathes() {
	if(pathCalculated) return;

	char* p = stpcpy(progPath, Py_GetProgramName());
	p = removeLastDir(progPath, p);
	
#ifdef __APPLE__
#include "TargetConditionals.h"
#ifdef TARGET_OS_MAC
	// the binary is in its own dir (Contents/MacOS),
	// but we want (Contents/Resources).
	p = removeLastDir(progPath, p);
	strcat(progPath, "/Resources");
#endif
#endif
	
	strcpy(pylibPath, progPath);
	strcat(pylibPath, "/pylib");	
	strcpy(modulePathes, pylibPath);
	strcat(modulePathes, "/pylib.zip");
	strcat(modulePathes, pylibPath);
	strcat(modulePathes, "/otherlibs");
	strcpy(execPrefixPath, pylibPath);
	strcat(execPrefixPath, "/exec");
	
	pathCalculated = 1;
}

/* External interface */

char *
Py_GetPath(void)
{
	calcPathes();
	return modulePathes;
}

char *
Py_GetPrefix(void)
{
	calcPathes();
	// TODO: not sure if this is good / correct / makes sense
	return pylibPath;
}

char *
Py_GetExecPrefix(void)
{
	calcPathes();
	return execPrefixPath;
}

char *
Py_GetProgramFullPath(void)
{
	calcPathes();
	return progPath;
}
