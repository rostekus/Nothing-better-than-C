FROM gcc:latest

WORKDIR /app

COPY Makefile .
COPY include/ ./include/
COPY src/ ./src/

RUN make

CMD ["./bin/server"]