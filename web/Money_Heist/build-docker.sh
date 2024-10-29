#!/bin/bash
docker stop money_heist
docker build --tag=money_heist .
docker run -d -p 80:80 --rm --name=money_heist money_heist
