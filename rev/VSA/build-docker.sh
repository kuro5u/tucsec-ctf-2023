#!/bin/bash
docker stop vsa
docker build --tag=vsa .
docker run -d -p 1337:1337 --rm --name=vsa vsa
