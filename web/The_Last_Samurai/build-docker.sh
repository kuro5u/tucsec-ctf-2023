#!/bin/bash
docker stop the_last_samurai
docker build --tag=the_last_samurai .
docker run -d -p 5000:5000 --rm --name=the_last_samurai the_last_samurai
