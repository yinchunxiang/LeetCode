#!/usr/bin/env bash

bazel build --cxxopt='-std=c++17' "$@"
