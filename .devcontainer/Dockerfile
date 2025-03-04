FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu

RUN apt-get update && apt-get install -y --no-install-recommends \
    xauth \
    libxext-dev \
    libbsd-dev \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Clone libft repository
RUN git clone https://github.com/yuzu-juice/libft /workspaces/libft
