//
//  main.cpp
//  PlatformTest
//
//  Created by Robert Sayre on 5/7/21.
//

#include <iostream>
#include <sys/sysctl.h>

int processIsTranslated() {
   int ret = 0;
   size_t size = sizeof(ret);
   if (sysctlbyname("sysctl.proc_translated", &ret, &size, NULL, 0) == -1)
   {
      if (errno == ENOENT)
         return 0;
      return -1;
   }
   return ret;
}

int main(int argc, const char * argv[]) {
    int translated = processIsTranslated();
    if (translated == 0) {
        std::cout << "The process is native\n";
    } else if (translated == 1) {
        std::cout << "Theh process is translated by Rosetta\n";
    } else {
        std::cout << "There was an error.\n";
    }
    return 0;
}
