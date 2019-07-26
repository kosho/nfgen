# NetFlow Traffic Generator

`nfgen` is created to run a performance testing on NetFlow receivers.

Usage: `nfgen [-t num_threads (3)] [-p port (9995)] target_ip`

- `-t num_threads`: Number of threads to generate the traffic (default 3)
- `-p port`: Target port number (default 9995)
- `target_ip` Receiver's IP address

Downloads

- [nfgen (linux-x86_64)](https://github.com/kosho/esperf/releases/download/0.1.0/nfgen/nfgen-0.1.0-linux-x86_64.gz)
- [nfgen (darwin-x86_64)](https://github.com/kosho/esperf/releases/download/0.1.0/nfgen/nfgen-0.1.0-darwin-x86_64.gz)