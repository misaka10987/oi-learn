#!/bin/bash
set -e
mkdir -p ./target
echo "=> compile $1.cc"
g++ -Wall "./src/$1.cc" -o "./target/$1"
echo "=> run $1"
"./target/$1"
