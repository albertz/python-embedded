#!/bin/bash

cd $(dirname $0)

pushd CPython/Lib || exit 1 
rm pylib/pylib.zip
zip -9 ../../pylib/pylib.zip -x test\* -x plat\* -x unittest -r *

popd
