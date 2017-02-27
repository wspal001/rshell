#!/bin/sh
touch $1.cc
cat William_861219874.txt > $1.cc
echo "#include \“$1.hh\”
$1::$1()
{

}
$1::~$1()
{

}" >> $1.cc

touch $1.hh
cat William_861219874.txt > $1.hh
echo "#ifndef $1_hh
#define $1_hh
#include \"$2.hh\"
class $1 : public $2
{
public:
$1();
~$1();
private:
};
#endif" >> $1.hh

