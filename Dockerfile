FROM ubuntu:21.04 as build

RUN apt-get update

RUN apt-get install -y \
    binutils-mips-linux-gnu \
    build-essential \
    gcc-mips-linux-gnu \
    less \
    libglib2.0 \
    python3 \
    python3-pip \
    unzip \
    wget \
    libssl-dev

RUN python3 -m pip install \
    capstone pylibyaml pyyaml pycparser \
    colorama ansiwrap watchdog python-Levenshtein cxxfilt \
    python-ranges \
    pypng anybadge

RUN mkdir /donkeykong64
WORKDIR /donkeykong64
