echo A && echo B || echo C && echo D ; echo prints ABD
(echo A && echo B) || (echo C && echo D) ; echo prints AB
([ -d src] && echo src is a directory) && ([-f src/CommandBase.cc] && echo CommandBase.cc is a file)
echo skip || (echo didnt skip && echo not skipped) ; echo skipped
ls && ([ -d src] && echo src is a directory)
exit
