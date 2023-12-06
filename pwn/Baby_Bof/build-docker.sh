#!/bin/bash
docker stop baby_bof
docker build --tag=baby_bof .
docker run -d -p 1337:1337 --rm --name=baby_bof baby_bof
