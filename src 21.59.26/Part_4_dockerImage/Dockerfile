FROM nginx
# - serv.c - код сервера
# - settings.sh - bash-скрипт, чтобы установить все настройки и не вводить вручную
# - nginx.conf -  конфигурационный файл 

COPY ./serv.c ./
COPY  ./settings.sh ./
COPY  ./nginx.conf /etc/nginx/nginx.conf

RUN chmod +x settings.sh && sh settings.sh

CMD sh -c "./settings.sh && nginx -g 'daemon off;'"