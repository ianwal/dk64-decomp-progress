FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    binutils-mips-linux-gnu \
    build-essential \
    gcc-mips-linux-gnu \
    libglib2.0 \
    python3 \
    python3-pip \
    python-is-python3 \
    python3-venv \
    unzip \
    wget \
    libssl-dev \
    vbindiff \
    git \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir /dk64
WORKDIR /dk64

RUN python -m venv /opt/venv
# Enable venv
ENV PATH="/opt/venv/bin:$PATH"

COPY requirements.txt /dk64/
RUN python3 -m pip install -r /dk64/requirements.txt

CMD echo 'Usage: docker run --rm -v ${PWD}:/dk64 --user $UID:$GID dk64 make\n' \
         'See https://gitlab.com/dk64_decomp/dk64 for more information'
