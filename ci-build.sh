#!/bin/bash

xcodebuild -scheme $SCHEME build -destination "$DESTINATION" -showBuildTimingSummary
