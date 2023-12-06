#!/bin/bash
docker stop oneorzero 2>/dev/null
docker build --tag=oneorzero .
docker run -d -p 1337:1337 --rm --name=oneorzero oneorzero
