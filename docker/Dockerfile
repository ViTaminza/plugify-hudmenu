FROM registry.gitlab.steamos.cloud/steamrt/sniper/sdk:latest
RUN apt-get update -qq && V=1:10.5.23-0+deb11u1 \
 && apt-get install -y -qq --allow-downgrades mariadb-common=$V libmariadb3=$V libmariadb-dev=$V ninja-build >/dev/null \
 && rm -rf /var/lib/apt/lists/*
