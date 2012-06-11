#!/usr/bin/python

from glob import glob as pyglob
import os, sys
from pprint import pprint
os.chdir(os.path.dirname(__file__) or os.getcwd())
try: os.mkdir("build")
except: pass

PythonDir = "Python-2.7.3"

def glob(pattern):
	def glob_(baseDir, patternList):
		if not patternList:
			yield baseDir
			return
		head = patternList[0]
		if head == "**":
			for f in glob_(baseDir, patternList[1:]): yield f
			for d in pyglob(baseDir + "/*/"):
				for f in glob_(d, patternList): yield f
			return
		for m in pyglob(baseDir + "/" + head):
			for f in glob_(m, patternList[1:]): yield f
	parts = pattern.split("/")
	if not parts: return
	if parts[0] == "": # start in root
		for f in glob_("/", parts[1:]): yield os.path.normpath(f)
		return
	for f in glob_(".", parts): yield os.path.normpath(f)

baseFiles = \
	set(glob(PythonDir + "/Python/*.c")) - \
	set(glob(PythonDir + "/Python/dynload_*.c"))
baseFiles |= \
	set(glob(PythonDir + "/Python/dynload_stub.c")) | \
	set(glob("pyimportconfig.c"))

# via blacklist
modFiles = \
	set(glob(PythonDir + "/Modules/**/*.c")) - \
	set(glob(PythonDir + "/Modules/**/testsuite/**/*.c")) - \
	set(glob(PythonDir + "/Modules/_sqlite/**/*.c")) - \
	set(glob(PythonDir + "/Modules/_bsddb.c")) - \
	set(glob(PythonDir + "/Modules/expat/**/*.c")) - \
	set(glob(PythonDir + "/Modules/imgfile.c")) - \
	set(glob(PythonDir + "/Modules/_ctypes/**/*.c")) - \
	set(glob(PythonDir + "/Modules/glmodule.c"))
	# ...
	
# via whitelist
modFiles = \
	set(map(lambda f: PythonDir + "/Modules/" + f,
		[
			"main.c",
			"python.c",
			"getpath.c",
			"getbuildinfo.c",
			"arraymodule.c",
			"gcmodule.c",
			"_csv.c",
			"_collectionsmodule.c",
			"itertoolsmodule.c",
			"operator.c"
			])) | \
	set(glob(PythonDir + "/Modules/_io/*.c"))

# remove main.c/python.c if we dont want an executable
#- \
	#[PythonDir + "/Modules/main.c"]
#pprint(modFiles)

objFiels = \
	set(glob(PythonDir + "/Objects/*.c"))

parserFiles = \
	set(glob(PythonDir + "/Parser/*.c")) - \
	set(glob(PythonDir + "/Parser/*pgen*.c"))

compileOpts = [
	"-I.",
	"-I" + PythonDir + "/Include",
]

def compile():
	ofiles = []
	for f in list(baseFiles) + list(modFiles) + list(objFiels) + list(parserFiles):
		ofile = os.path.splitext(os.path.basename(f))[0] + ".o"
		ofiles += [ofile]
		try:
			if os.stat(f).st_mtime < os.stat("build/" + ofile).st_mtime:
				continue
		except: pass
		if os.system("gcc " + " ".join(compileOpts) + " -c " + f + " -o build/" + ofile) != 0:
			sys.exit(1)
	
	os.system("gcc " + " ".join(map(lambda f: "build/" + f, ofiles)) + " -o python")
	
if __name__ == '__main__':
	compile()

