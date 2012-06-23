This is from http://code.google.com/p/ios-static-libraries/

HEADER_SEARCH_PATHS[sdk=iphoneos4.3][arch=armv7] = ${SRCROOT}/../iPhoneOS-V7-4.3/include
HEADER_SEARCH_PATHS[sdk=iphoneos4.3][arch=armv6] = ${SRCROOT}/../iPhoneOS-V6-4.3/include
HEADER_SEARCH_PATHS[sdk=iphonesimulator4.3][arch=*] = ${SRCROOT}/../iPhoneSimulator-4.3/include
LIBRARY_SEARCH_PATHS[sdk=iphoneos4.3][arch=armv7] = ${SRCROOT}/../iPhoneOS-V7-4.3/lib
LIBRARY_SEARCH_PATHS[sdk=iphoneos4.3][arch=armv6] = ${SRCROOT}/../iPhoneOS-V6-4.3/lib
LIBRARY_SEARCH_PATHS[sdk=iphonesimulator4.3][arch=*] = ${SRCROOT}/../iPhoneSimulator-4.3/lib
OTHER_LDFLAGS = -Wl,-search_paths_first -lz -lcrypto -liconv -lssl -lsasl2 -letpan -lgcrypt -lgpg-error -lssh2 -lcurl

