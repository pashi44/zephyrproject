


#include "BlueOne.hpp"

#include <stdio.h>
#include  <zephyr/kernel.h>
#include <cstdio>
#include     <zephyr/logging/log.h>
LOG_MODULE_REGISTER(blue, LOG_LEVEL_DBG);



using namespace std;
using namespace  app::drivers::blue;


BlueOne::BlueOne(){}
BlueOne::~BlueOne(){}

void BlueOne::getSomething(){

printk("thi  sum mebr gonnahurt kuke am");
}
