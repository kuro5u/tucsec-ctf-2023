#!/bin/bash
docker stop mr_ropot 2>/dev/null
docker build --tag=mr_ropot .
docker run -d -p 1337:1337 --rm --name=mr_ropot mr_ropot
