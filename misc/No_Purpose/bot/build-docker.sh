#!/bin/bash
docker stop bot 2>/dev/null
docker build --tag=bot .
docker run -d -p 1337:1337 --rm --name=bot bot
