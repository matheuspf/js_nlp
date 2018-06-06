#!/bin/sh

git submodule init
git submodule sync --recursive
git submodule foreach --recursive "(git checkout master; git pull)"
cd ..