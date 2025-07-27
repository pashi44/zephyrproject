#include <iostream>
#include <chrono>
#include <thread>
#include "BlueOne.hpp"
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);


#include <zephyr/kernel.h>
using namespace std;
using namespace app::drivers::blue;
void cpp_main() {
    BlueOne bk;
    bk.getSomething();

    while (true) {
k_sleep(K_SECONDS(2));

}


}

extern "C"   int main(void) {
    cpp_main();  // Call from C-compatible entry point



}
