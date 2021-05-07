#!/bin/bash

xcodebuild -scheme $SCHEME build -destination "$DESTINATION" -showBuildTimingSummary
x=$( xcodebuild -showBuildSettings -project MacPlatformTest.xcodeproj | grep ' BUILD_DIR =' | sed -e 's/.*= *//' )

DYLD_FRAMEWORK_PATH=$x/Debug DYLD_LIBRARY_PATH=$x/Debug $x/Debug/MacPlatformTest