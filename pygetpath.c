
#include "Python.h"
#include "osdefs.h"
#include <sys/types.h>
#include <string.h>

extern char *Py_GetProgramName(void);

static int pathCalculated = 0; 
static char progPath[MAXPATHLEN+1];
static char modulePathes[4*MAXPATHLEN+1];
static char execPrefixPath[2*MAXPATHLEN+1];

static void calcPathes() {
	if(pathCalculated) return;

	char* p = stpcpy(progPath, Py_GetProgramName());
	while(--p > progPath) {
		if(*p == '/') {
			*p = 0;
			break;
		}
	}
	
	strcpy(modulePathes, progPath);
	strcat(modulePathes, "/pylib/pylib.zip");
	strcat(modulePathes, progPath);
	strcat(modulePathes, "/pylib/otherlibs");
	strcpy(execPrefixPath, progPath);
	strcat(execPrefixPath, "/pylib/exec");
	
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
	return progPath;
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
