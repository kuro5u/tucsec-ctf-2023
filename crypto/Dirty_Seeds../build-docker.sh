#!/bin/bash
docker stop dirty_seeds 2>/dev/null
docker build --tag=dirty_seeds .
docker run -d -p 1337:1337 --rm --name=dirty_seeds dirty_seeds
