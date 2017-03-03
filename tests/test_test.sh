echo tests/exit.sh ; [tests/exit.sh] ; echo exists
echo tests/exit.sh ; [-f tests/exit.sh] ; echo is a file
echo tests/exit.sh ; [-d tests/exit.sh] ; echo is not a directory
echo tests/bad.sh ; [tests/bad.sh] ; echo doesnt exists
echo tests/bad.sh ; [-f tests/bad.sh] ; echo is not a file
echo tests/bad.sh ; [-d tests/bad.sh] ; echo is not not a directory
echo tests ; [tests] ; echo exists
echo tests ; [-f tests] ; echo is not a file
echo tests ; [-d tests] ; echo is a directory
