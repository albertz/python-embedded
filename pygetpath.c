/* External interface */

char *
Py_GetPath(void)
{
//    return module_search_path;
	return "pylib/lib";
}

char *
Py_GetPrefix(void)
{
	return "BLA1";
//    return prefix;
}

char *
Py_GetExecPrefix(void)
{
//    return exec_prefix;
	return "pylib/exec";
}

char *
Py_GetProgramFullPath(void)
{
//    return progpath;
	return ".";
}
