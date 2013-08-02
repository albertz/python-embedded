#!/usr/bin/env python

import sys, os
os.chdir(os.path.dirname(__file__))

sys.path += ["mod-pbxproj"]

from mod_pbxproj import *

proj = XcodeProject.Load("Xcode-Python-empty.xcodeproj/project.pbxproj")

proj.add_header_search_paths(paths=[
	"$PROJECT_DIR/pylib",
	"$PROJECT_DIR/CPython/Include",
	], recursive=False)

proj.add_other_ldflags(flags=[
	"-lssl", "-lz", "-lcrypto", "-lsasl2"])

src = proj.get_or_create_group('src')

import compile
def add_file(fn):
	#print fn
	proj.add_file(fn, parent=src)

for fn in list(compile.baseFiles) + list(compile.modFiles) + list(compile.objFiels) + list(compile.parserFiles):
	add_file(fn)

proj.saveFormat3_2(file_name="Xcode-Python.xcodeproj/project.pbxproj")

