#!/bin/bash
docker stop tucstore
docker build --tag=tucstore .
docker run -d -p 1337:1337 --rm --name=tucstore tucstore
