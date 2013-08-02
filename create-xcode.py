#!/usr/bin/env python3

import sys
sys.path += ["mod-pbxproj"]

from mod_pbxproj3 import *

proj = XcodeProject()
proj.save()


