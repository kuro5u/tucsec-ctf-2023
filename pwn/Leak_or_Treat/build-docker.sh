#!/bin/bash
docker stop leak_or_treat
docker build --tag=leak_or_treat .
docker run -d -p 1337:1337 --rm --name=leak_or_treat leak_or_treat
