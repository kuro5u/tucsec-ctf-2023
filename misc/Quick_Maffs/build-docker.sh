#!/bin/bash
docker stop quick_maffs 2>/dev/null
docker build --tag=quick_maffs .
docker run -d -p 1337:1337 --rm --name=quick_maffs quick_maffs
