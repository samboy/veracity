# - Find GNOMEKEYRING
# Find the native GNOMEKEYRING includes and library
#
#  GNOMEKEYRING_INCLUDE_DIR - where to find zlib.h, etc.
#  GNOMEKEYRING_LIBRARIES   - List of libraries when using zlib.
#  GNOMEKEYRING_FOUND       - True if zlib found.


IF (GNOMEKEYRING_INCLUDE_DIR)
  # Already in cache, be silent
  SET(GNOMEKEYRING_FIND_QUIETLY TRUE)
ENDIF (GNOMEKEYRING_INCLUDE_DIR)

FIND_PATH(GNOMEKEYRING_INCLUDE_DIR gnome-keyring.h
		PATH_SUFFIXES gnome-keyring-1
	)

SET(GNOMEKEYRING_NAMES gnome-keyring)
FIND_LIBRARY(GNOMEKEYRING_LIBRARY NAMES ${GNOMEKEYRING_NAMES} )

# handle the QUIETLY and REQUIRED arguments and set GNOMEKEYRING_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GNOMEKEYRING DEFAULT_MSG GNOMEKEYRING_LIBRARY GNOMEKEYRING_INCLUDE_DIR)

IF(GNOMEKEYRING_FOUND)
  SET( GNOMEKEYRING_LIBRARIES ${GNOMEKEYRING_LIBRARY} )
ELSE(GNOMEKEYRING_FOUND)
  SET( GNOMEKEYRING_LIBRARIES )
ENDIF(GNOMEKEYRING_FOUND)

MARK_AS_ADVANCED( GNOMEKEYRING_LIBRARY GNOMEKEYRING_INCLUDE_DIR )
