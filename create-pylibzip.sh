#!/bin/bash

cd $(dirname $0)

pushd CPython/Lib || exit 1 
rm pylib/pylib.zip
zip -9 ../../pylib/pylib.zip \
	-x test\* \
	-x plat\* \
	-x unittest\* \
	-x lib2to3\* \
	-x lib-tk\* \
	-x distutils\* \
	-x ctypes/test\* \
	-x email/test\* \
	-x json/tests\* \
	-x sqlite3/test\* \
	-x bsddb\* \
	-x idlelib\* \
	-r *

popd
