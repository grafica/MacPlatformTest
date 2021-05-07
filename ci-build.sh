#!/bin/sh
set -v
set -e

xcodebuild -scheme $SCHEME build -destination "$DESTINATION" -showBuildTimingSummary