apt-get update
apt-get install -y libfcgi-dev libfcgi0ldbl spawn-fcgi gcc
apt install net-tools
gcc --version spawn-fcgi -v
gcc -o serv  serv.c -lfcgi
