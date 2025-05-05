# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Charifas_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Charifas_autogen.dir\\ParseCache.txt"
  "Charifas_autogen"
  )
endif()
