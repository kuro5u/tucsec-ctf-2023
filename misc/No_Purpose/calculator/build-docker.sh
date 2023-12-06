#!/bin/bash
docker stop calculator 2>/dev/null
docker build --tag=calculator .
docker run -d -p 1338:1338 --rm --name=calculator calculator
