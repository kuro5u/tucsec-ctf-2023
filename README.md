# TUCsec CTF 2023

### Challenge Structure
The general tree structure for each challenge is the following:

```
├── challenge/
├── source/
├── solution/
├── Dockerfile
├── README.md
└── build_docker.sh
```
Notice that not all challenges include all of the above folders and files.

### Folder and File Overview
* `challenge/`: Contains the files provided during the CTF for that particular challenge.
* `source/`: Contains source files that are not visible to the player during the CTF, but are needed so that you can setup the challenges locally and try them out.
* `solution/`: Contains a solver for the challenge.
* `Dockerfile`: Contains the build instructions to build the challenge image locally.
* `README.md`: Contains the description, difficulty and author of the challenge.
* `build_docker.sh`: Bash script that automates the building and deployment of the docker for the challenge.

### How to Play
If you want to try out a challenge properly without getting spoiled you should start by reading the `README.md` of that challenge. You can use everything included in the `challenge` directory. If the challenge contains a `Dockerfile`, you have to set up the docker locally. For this purpose there is a `build_docker.sh` script which should automate that process. When the docker is up and running, try to exploit the app running on the docker to retrieve the **flag** from inside. G00d 1uck!

![TUCsec CTF 2023](https://www.ece.tuc.gr/fileadmin/_processed_/d/f/csm_ctf-2023-poster_fc1da4ef69.png)
