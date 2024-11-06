# Install script for directory: D:/CodingSpace/JUCE

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/CodingSpace/JUCE/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/CodingSpace/JUCE/out/build/x64-Debug/modules/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/CodingSpace/JUCE/out/build/x64-Debug/extras/Build/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3" TYPE FILE FILES
    "D:/CodingSpace/JUCE/out/build/x64-Debug/JUCEConfigVersion.cmake"
    "D:/CodingSpace/JUCE/out/build/x64-Debug/JUCEConfig.cmake"
    "D:/CodingSpace/JUCE/extras/Build/CMake/JUCECheckAtomic.cmake"
    "D:/CodingSpace/JUCE/extras/Build/CMake/JUCEHelperTargets.cmake"
    "D:/CodingSpace/JUCE/extras/Build/CMake/JUCEModuleSupport.cmake"
    "D:/CodingSpace/JUCE/extras/Build/CMake/JUCEUtils.cmake"
    "D:/CodingSpace/JUCE/extras/Build/CMake/JuceLV2Defines.h.in"
    "D:/CodingSpace/JUCE/extras/Build/CMake/LaunchScreen.storyboard"
    "D:/CodingSpace/JUCE/extras/Build/CMake/PIPAudioProcessor.cpp.in"
    "D:/CodingSpace/JUCE/extras/Build/CMake/PIPAudioProcessorWithARA.cpp.in"
    "D:/CodingSpace/JUCE/extras/Build/CMake/PIPComponent.cpp.in"
    "D:/CodingSpace/JUCE/extras/Build/CMake/PIPConsole.cpp.in"
    "D:/CodingSpace/JUCE/extras/Build/CMake/RecentFilesMenuTemplate.nib"
    "D:/CodingSpace/JUCE/extras/Build/CMake/UnityPluginGUIScript.cs.in"
    "D:/CodingSpace/JUCE/extras/Build/CMake/checkBundleSigning.cmake"
    "D:/CodingSpace/JUCE/extras/Build/CMake/copyDir.cmake"
    "D:/CodingSpace/JUCE/extras/Build/CMake/juce_runtime_arch_detection.cpp"
    "D:/CodingSpace/JUCE/extras/Build/CMake/juce_LinuxSubprocessHelper.cpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/JUCE-8.0.3" TYPE EXECUTABLE FILES "D:/CodingSpace/JUCE/out/build/x64-Debug/juce_lv2_helper.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("D:/CodingSpace/JUCE/out/build/x64-Debug/CMakeFiles/juce_lv2_helper.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3/LV2_HELPER.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3/LV2_HELPER.cmake"
         "D:/CodingSpace/JUCE/out/build/x64-Debug/CMakeFiles/Export/1ac93432313da1970243e25e5dc5dd41/LV2_HELPER.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3/LV2_HELPER-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3/LV2_HELPER.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3" TYPE FILE FILES "D:/CodingSpace/JUCE/out/build/x64-Debug/CMakeFiles/Export/1ac93432313da1970243e25e5dc5dd41/LV2_HELPER.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3" TYPE FILE FILES "D:/CodingSpace/JUCE/out/build/x64-Debug/CMakeFiles/Export/1ac93432313da1970243e25e5dc5dd41/LV2_HELPER-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/JUCE-8.0.3" TYPE EXECUTABLE FILES "D:/CodingSpace/JUCE/out/build/x64-Debug/juce_vst3_helper.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("D:/CodingSpace/JUCE/out/build/x64-Debug/CMakeFiles/juce_vst3_helper.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3/VST3_HELPER.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3/VST3_HELPER.cmake"
         "D:/CodingSpace/JUCE/out/build/x64-Debug/CMakeFiles/Export/1ac93432313da1970243e25e5dc5dd41/VST3_HELPER.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3/VST3_HELPER-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3/VST3_HELPER.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3" TYPE FILE FILES "D:/CodingSpace/JUCE/out/build/x64-Debug/CMakeFiles/Export/1ac93432313da1970243e25e5dc5dd41/VST3_HELPER.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.3" TYPE FILE FILES "D:/CodingSpace/JUCE/out/build/x64-Debug/CMakeFiles/Export/1ac93432313da1970243e25e5dc5dd41/VST3_HELPER-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/CodingSpace/JUCE/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
