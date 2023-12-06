#!/bin/bash
docker stop activate_windows
docker build --tag=activate_windows .
docker run -d -p 1337:1337 --rm --name=activate_windows activate_windows
