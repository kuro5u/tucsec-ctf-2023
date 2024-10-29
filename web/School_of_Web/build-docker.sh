#!/bin/bash
docker stop school_of_web
docker build --tag=school_of_web .
docker run -d -p 80:80 --rm --name=school_of_web school_of_web
