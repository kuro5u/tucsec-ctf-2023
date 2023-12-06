#!/bin/bash
docker stop vvsa
docker build --tag=vvsa .
docker run -d -p 1337:1337 --rm --name=vvsa vvsa
