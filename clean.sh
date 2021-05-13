#!/bin/zsh

find . -type f -perm +ugo+x | xargs rm
find . -type d -name "*dSYM*" | xargs rm -r
