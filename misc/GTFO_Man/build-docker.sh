#!/bin/bash
docker stop gtfo_man
docker build --tag=gtfo_man .
docker run -d -p 1337:1337 --rm --name=gtfo_man gtfo_man
