FROM ubuntu:22.04

# Unminimize system to use man
RUN yes | unminimize

# Install dependencies
RUN apt-get update && apt-get install socat man-db manpages less -y

# Clean up
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

# Set the MANPAGER and PAGER environment variables to less for better pager support
ENV MANPAGER="less"
ENV MANLESS=" "

# Set a terminal for better support
ENV TERM="xterm"

# Create ctf user
RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf

# Challenge files
COPY --chown=ctf challenge/ /home/ctf/

# Set some proper permissions
RUN chown -R root:ctf /home/ctf
RUN chmod 440 /home/ctf/flag.txt

# Set ctf as the default user
USER ctf

# Set starting workdir
WORKDIR /

# Expose port 1337
EXPOSE 1337

# Command to run when connecting
CMD ["socat", "-T", "15", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:'/usr/bin/man man',ptmx,stderr"]
