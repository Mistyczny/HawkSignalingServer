FROM ubuntu:21.10 AS HawkSignalingServerBuilder
ENV DEBIAN_FRONTEND=nonintercative

RUN apt-get update && apt-get install -y \
    wget \
    git \
    make \
    cmake \
    gcc \
    g++ \
    python3 \
    python3-pip

RUN pip install conan