#!/bin/bash

set -e

cd $(dirname $0)

rm pylib/pylib.zip

pushd CPython/Lib
zip -9 ../../pylib/pylib.zip \
	-x test\* \
	-x unittest\* \
	-x lib2to3\* \
	-x lib-tk\* \
	-x distutils/tests\* \
	-x distutils/command/\*.exe \
	-x ctypes/test\* \
	-x email/test\* \
	-x json/tests\* \
	-x sqlite3/test\* \
	-x bsddb\* \
	-x idlelib\* \
	-r *
popd

zip -9 pylib/pylib.zip _sysconfigdata.py

pushd setuptools
zip -9 ../pylib/pylib.zip pkg_resources.py
popd

