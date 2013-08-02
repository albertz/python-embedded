#!/usr/bin/env python

import sys, os
os.chdir(os.path.dirname(__file__))

sys.path += ["mod-pbxproj"]

from mod_pbxproj import *

proj = XcodeProject.Load("Xcode-Python-empty.xcodeproj/project.pbxproj")
proj.saveFormat3_2(file_name="Xcode-Python.xcodeproj/project.pbxproj")

