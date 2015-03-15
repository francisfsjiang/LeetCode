#!/bin/bash
name=""
for param in "$@"
do
    name="$name""$param""_"
done

name="${name%_*}"
mkdir $name
cp main.cpp $name/
