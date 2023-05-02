# Nothing-better-than-C

This is a simple web server built from scratch using UNIX sockets and pure C language.

## Requirements

To build and run this project, you need to have the following tools installed:

- GCC compiler
- Make

## Build and Run

To build the project, run the following command:
```
make
```
This will compile the source code and generate an executable file named `server` under the `bin` directory.

To run the server, execute the following command:
```
./bin/server
```

This will start the server and it will be accessible at `http://localhost:8080`.

## Endpoints

The server supports two endpoints:

### /

This endpoint returns a simple HTML page with the message "Hello, world!".

### /about

This endpoint returns a simple HTML page with some information about the server.

## Contributions

Contributions are welcome! If you find a bug or want to add a new feature, please create a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.



