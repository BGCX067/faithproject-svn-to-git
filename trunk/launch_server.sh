#!/bin/sh

rm faith.sqlite
./build/faith_server --http-address 127.0.0.1 --http-port 8080 --docroot .
