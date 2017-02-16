#!/bin/sh
echo Testing multiple commands
echo A; echo B; echo C;
echo A && echo B
echo A || echo B
echo A && echo B && echo C
echo A && echo B || echo C
echo A || echo B && echo C
echo A; echo B && echo C
echo A; echo B || echo C
ls; ls; ls;
echo A
echo ls ;ls
echo A            && echo B
echo A   &&    echo B
echo A  && echo B
exit