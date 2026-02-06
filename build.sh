#!/bin/sh
set -e

mkdir -p priv

ERL_INCLUDE=$(erl -noshell -eval \
  'io:format("~s", [filename:join([code:root_dir(), "erts-" ++ erlang:system_info(version), "include"])])' \
  -s init stop)

gcc -fPIC -shared native/raylib_nif.c \
  -I"$ERL_INCLUDE" \
  $(pkg-config --cflags raylib) \
  $(pkg-config --libs raylib) \
  -o priv/libraylib_nif.so
