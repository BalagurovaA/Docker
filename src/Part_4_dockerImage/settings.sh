# установка настроек 
apt-get -y update
apt-get -y install nginx
apt-get install -y libfcgi-dev libfcgi0ldbl spawn-fcgi gcc
apt install net-tools

# компиляция сервера
gcc -o serv  serv.c -lfcgi

# запуск на 8080 порту
spawn-fcgi -p 8080 ./serv