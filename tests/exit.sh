#!/bin/sh
echo testing exit
ls || exit
(echo avoid exit || exit) ; echo exit avoided
ls && exit
