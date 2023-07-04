# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/IDF/Espressif/frameworks/esp-idf-v5.0.2/components/bootloader/subproject"
  "E:/Projects/Summer-2023-Embedded-Syaytems-Choosed/web_Server_Simple_Task/build/bootloader"
  "E:/Projects/Summer-2023-Embedded-Syaytems-Choosed/web_Server_Simple_Task/build/bootloader-prefix"
  "E:/Projects/Summer-2023-Embedded-Syaytems-Choosed/web_Server_Simple_Task/build/bootloader-prefix/tmp"
  "E:/Projects/Summer-2023-Embedded-Syaytems-Choosed/web_Server_Simple_Task/build/bootloader-prefix/src/bootloader-stamp"
  "E:/Projects/Summer-2023-Embedded-Syaytems-Choosed/web_Server_Simple_Task/build/bootloader-prefix/src"
  "E:/Projects/Summer-2023-Embedded-Syaytems-Choosed/web_Server_Simple_Task/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Projects/Summer-2023-Embedded-Syaytems-Choosed/web_Server_Simple_Task/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Projects/Summer-2023-Embedded-Syaytems-Choosed/web_Server_Simple_Task/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
