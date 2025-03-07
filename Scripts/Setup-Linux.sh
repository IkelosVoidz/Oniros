#!/bin/bash

pushd ..
vendor/binaries/premake/Linux/premake5 --cc=clang --file=Build.lua gmake2
popd
