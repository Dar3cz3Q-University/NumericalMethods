#!/bin/bash

pushd ..
Vendor/Binaries/Premake/Linux/premake5 --cc=clang --file=premake5.lua gmake2
popd
