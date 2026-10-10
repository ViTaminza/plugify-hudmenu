#!/bin/bash
# Builds the plugin in the Steam Runtime 3 (sniper) SDK image and packages it into build/package.
# Usage: ./build.sh
set -euo pipefail
ROOT=$(cd "$(dirname "$0")" && pwd)
docker build -q -t plugify-plugin-builder "$ROOT/docker" >/dev/null
docker run --rm -u "$(id -u):$(id -g)" -v "$ROOT":/src -w /src --entrypoint bash plugify-plugin-builder -c '
set -e
cmake -S /src -B /src/build -G Ninja -DCMAKE_C_COMPILER=gcc-14 -DCMAKE_CXX_COMPILER=g++-14 \
      -DCMAKE_BUILD_TYPE=Release -DPLUGIFY_PORT_TESTS=OFF >/dev/null
ninja -C /src/build'
for p in "$ROOT"/plugins/*/package.sh; do bash "$p"; done
