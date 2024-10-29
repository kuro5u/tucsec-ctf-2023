#!/bin/bash
docker stop matrix
docker build --tag=matrix .
docker run -d -p 1337:1337 --rm --name=matrix matrix
