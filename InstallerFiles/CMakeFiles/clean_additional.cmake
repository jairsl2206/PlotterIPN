# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\IPNPlotter_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\IPNPlotter_autogen.dir\\ParseCache.txt"
  "IPNPlotter_autogen"
  )
endif()
