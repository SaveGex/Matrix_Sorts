# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_7Z "OFF")
set(CPACK_BINARY_IFW "OFF")
set(CPACK_BINARY_INNOSETUP "OFF")
set(CPACK_BINARY_NSIS "ON")
set(CPACK_BINARY_NUGET "OFF")
set(CPACK_BINARY_WIX "OFF")
set(CPACK_BINARY_ZIP "OFF")
set(CPACK_BUILD_SOURCE_DIRS "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/src/v3.2.1-eacc4e4c85.clean;C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/x64-windows-rel")
set(CPACK_CMAKE_GENERATOR "Ninja")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_COMPRESSION_TYPE "xz")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6-dev")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "cxxopt developers")
set(CPACK_DEBIAN_PACKAGE_NAME "libcxxopts-dev")
set(CPACK_DEBIAN_PACKAGE_SUGGESTS "cmake, pkg-config, pkg-conf")
set(CPACK_DEB_COMPONENT_INSTALL "ON")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.30/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "cxxopts built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "NSIS")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/x64-windows-rel;cxxopts;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/pkgs/cxxopts_x64-windows")
set(CPACK_MODULE_PATH "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/src/v3.2.1-eacc4e4c85.clean/cmake/")
set(CPACK_NSIS_COMPONENT_INSTALL "ON")
set(CPACK_NSIS_DISPLAY_NAME "cxxopts 3.2.1")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "cxxopts 3.2.1")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/x64-windows-rel/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION "")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.30/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "cxxopts built using CMake")
set(CPACK_PACKAGE_FILE_NAME "cxxopts-3.2.1-win64")
set(CPACK_PACKAGE_HOMEPAGE_URL "")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "cxxopts 3.2.1")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "cxxopts 3.2.1")
set(CPACK_PACKAGE_MAINTAINER "cxxopt developers")
set(CPACK_PACKAGE_NAME "cxxopts")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "cxxopt developers")
set(CPACK_PACKAGE_VERSION "3.2.1")
set(CPACK_PACKAGE_VERSION_MAJOR "3")
set(CPACK_PACKAGE_VERSION_MINOR "2")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_RESOURCE_FILE_LICENSE "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/src/v3.2.1-eacc4e4c85.clean/LICENSE")
set(CPACK_RESOURCE_FILE_README "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/src/v3.2.1-eacc4e4c85.clean/README.md")
set(CPACK_RESOURCE_FILE_WELCOME "C:/Program Files/CMake/share/cmake-3.30/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_COMPONENT_INSTALL "ON")
set(CPACK_RPM_PACKAGE_NAME "libcxxopts-devel")
set(CPACK_RPM_PACKAGE_SUGGESTS "cmake, pkg-config, pkg-conf")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/x64-windows-rel/CPackSourceConfig.cmake")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "C:/Users/Opsik/source/repos/Matrix_Sorts/vcpkg_installed/vcpkg/blds/cxxopts/x64-windows-rel/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
