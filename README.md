# Simple TCP Client in C (HTTP Port 80)

This project demonstrates how to create a simple **TCP client** in C that connects to a remote server (in this case, Google’s IP on port 80) and sends an HTTP request.  
It’s a minimal yet powerful example of **socket programming in C**, showing how to build, connect, send, and receive data over a TCP connection.

--------------------------------------------------------------------

## What This Project Does

This program:
1. Creates a TCP socket using the `socket()` system call.  
2. Connects to a specified IP address (`142.250.182.164`, which belongs to **www.google.com**) on port `80` (HTTP).  
3. Sends a simple HTTP **HEAD** request to the server:
   HEAD / HTTP/1.0\r\n\r\n
   This asks the server for the HTTP headers of the homepage without downloading the actual HTML body.
4. Receives the server’s response and displays the HTTP headers (like server type, content length, etc.) on the terminal.

---------------------------------------------------------------------

## How It Works (Step-by-Step)

1. **SOCKET CREATION**

  int s = socket(AF_INET, SOCK_STREAM, 0);    

. AF_INET: Specifies IPv4.
. SOCK_STREAM: Specifies a TCP connection.
. 0: Default protocol for TCP.   

2. **SERVER ADDRESS SETUP**
  
   struct sockaddr_in sock;
   sock.sin_family = AF_INET;
   sock.sin_port = htons(PORT);
   sock.sin_addr.s_addr = inet_addr(IP);

. Converts the given IP and port into a format the system can use for connections.
3. **CONNECTION**

   connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr_in));
. Establishes the TCP connection with the server.

4. **SENDING DATA**

   write(s, data, strlen(data));
. Sends the HTTP request over the socket.

5. **RECEIVING DATA**

   read(s, buff, 511);
. Reads up to 511 bytes from the server response into buff.

6. **CLOSING THE CONNECTION**

   close(s).
. Closes the socket cleanly.


--------------Why This Project Is Useful----------------------

Helps beginners understand core networking concepts like:
.   IP addressing
.   TCP handshakes
.   Basic HTTP communication
.   System calls in C

Acts as a foundation for:
.   Writing custom HTTP clients
.   Network monitoring tools
.   Building servers or proxies
.   Learning raw socket programming

--------------------------------------------------------------
# Getting Started

1. Prerequisites
 -A Linux/Unix-based environment (e.g., Ubuntu, Arch, macOS) 
 -A C compiler like gcc

2. How to Compile
 In the term:inal,type: gcc tcp_client.c -o output && ./output

3. Output will look similar to this:
  
   HTTP/1.0 200 OK
   Content-Type: text/html; charset=ISO-8859-1
   Content-Security-Policy-Report-Only: object-src 'none';base-uri 'self';script-src 'nonce-pKLmVDBLscCaHcZ48mb9bQ' 'strict-dynamic' 'report-sample' 'unsafe-eval' 'unsa   fe-inline' https: http:;report-uri https://csp.withgoogle.com/csp/gws/other-hp
   P3P: CP="This is not a P3P policy! See g.co/p3phelp for more info."
   Date: Wed, 22 Oct 2025 13:53:21 GMT
   Server: gws
   X-XSS-Protection: 0
   X-Frame-Options: SAMEORIGIN
   Expires: Wed, 22 Oct 2025 13:53:21 

# Getting Help

If you encounter issues:

-Ensure you have internet connectivity.
-Check your system’s firewall (it may block outgoing connections).
-Try changing the IP or port to test other servers.

You can also:
-Open a GitHub Issue in this repository.
-Ask networking-related questions on:stack overflow

# Contributing

If you’d like to improve or extend this project (e.g., add HTTPS support, error handling, or command-line arguments), feel free to:
.  Fork the repo
.  Create a new branch
.  Submit a pull request

------Contributions are welcome! ----------


# License
This project is licensed under the MIT License — feel free to use, modify, and share it.

# Author
Name  - AKASH VISHWAKARMA
Gmail - akashdevil82@gmail.com

Date  - 17 October 2025
--Learning low-level networking and system programming with C 





........................................ Don’t forget to star this repo if you find it helpful!.................................................................
