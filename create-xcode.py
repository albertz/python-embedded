#!/usr/bin/env python

import sys, os
os.chdir(os.path.dirname(__file__))

import compile
compile.iOS = False
reload(compile)

sys.path += ["mod-pbxproj"]
from mod_pbxproj import *

proj = XcodeProject.Load("Xcode-Python-empty.xcodeproj/project.pbxproj")

proj.add_header_search_paths(paths=[
	"$PROJECT_DIR/pylib",
	"$PROJECT_DIR/CPython/Include",
	], recursive=False)

proj.add_other_cflags(flags=[
	"-DWITH_THREAD",
	"-DPLATFORM=\\\"darwin\\\"",
	])

proj.add_other_ldflags(flags=[
	"-lssl", "-lz", "-lcrypto", "-lsasl2"])

def add_file(fn, group):
	#print fn
	proj.add_file(fn, parent=group)

src = proj.get_or_create_group("src")

for l in ["baseFiles", "extraFiles", "modFiles", "objFiles", "parserFiles"]:
	group = proj.get_or_create_group(l, parent=src)
	
	for fn in list(getattr(compile, l)):
		add_file(fn, group=group)

proj.saveFormat3_2(file_name="Xcode-Python.xcodeproj/project.pbxproj")

