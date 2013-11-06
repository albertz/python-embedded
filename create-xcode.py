#!/usr/bin/env python

import sys, os
os.chdir(os.path.dirname(__file__))

# Sorry a bit about the inconsistency.
# This Xcode project file is currently designed for desktop MacOSX apps. The compile script is for a static iOS lib.

import compile
compile.iOS = False
reload(compile)

from mod_pbxproj import *

proj = XcodeProject.Load("Xcode-Python-empty.xcodeproj/project.pbxproj")

proj.add_header_search_paths(paths=[
	"$PROJECT_DIR/pylib",
	"$PROJECT_DIR/CPython/Include",
	], recursive=False)

proj.add_other_cflags(flags=[
	"-DWITH_THREAD",
	"-DPLATFORM=\\\"darwin\\\"",
	"-DHAVE_DYNAMIC_LOADING",
	"-DUSE_DYLD_GLOBAL_NAMESPACE", # needed for e.g. pyobjc
	])

proj.add_other_ldflags(flags=[
	"-lssl", "-lz", "-lcrypto", "-lsasl2"])

def add_file(fn, group, **kwargs):
	#print fn
	proj.add_file(fn, parent=group, **kwargs)

src = proj.get_or_create_group("src")

for l in ["baseFiles", "extraFiles", "modFiles", "objFiles", "parserFiles"]:
	group = proj.get_or_create_group(l, parent=src)
	
	for fn in list(getattr(compile, l)):
		add_file(fn, group=group)

def sqlite():
	import subprocess
	if subprocess.check_output("nm -g /usr/local/opt/sqlite/lib/libsqlite3.dylib | grep __strlcat_chk || true", shell=True):
		print "Error: sqlite is compiled for >=MacOSX 10.9 (has ref to __strlcat_chk)"
		print "Try:"
		print "  export SDKROOT=/Developer/SDKs/MacOSX10.6.sdk"
		print "  brew install sqlite --env=std --with-fts"
		sys.exit(-1)

	l = "sqlite"
	group = proj.get_or_create_group(l, parent=src)
	C = compile.Sqlite
	for fn in C.files:
		add_file(fn, group=group, compiler_flags=C.options)
	proj.add_header_search_paths("/usr/local/opt/sqlite/include", recursive=False)
	proj.add_library_search_paths("/usr/local/opt/sqlite/lib", recursive=False)
	proj.add_other_ldflags("/usr/local/opt/sqlite/lib/libsqlite3.a")
sqlite()

proj.saveFormat3_2(file_name="Xcode-Python.xcodeproj/project.pbxproj")

