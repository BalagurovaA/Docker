FROM nginx

# - serv.c - код сервера
# - settings.sh - bash-скрипт, чтобы установить все настройки и не вводить вручную
# - nginx.conf -  конфигурационный файл 

# создала группу пользователей добавила туда пользователя nginx-user
RUN groupadd -r nginx-user && useradd -r -g nginx-user nginx-user


COPY ./serv.c ./
COPY  ./settings.sh ./
COPY  ./nginx.conf /etc/nginx/nginx.conf

RUN find /usr/bin usr/sbin/ -type f -exec chmod a-s {} +


# дала права пользователю nginx-user права для папок, связанных с nginx
# Команда chown дает файлу нового владельца
RUN chmod +x settings.sh && sh settings.sh && chown -R nginx-user:nginx-user /etc/nginx /var/cache/nginx /var/log/nginx

USER nginx-user
RUN sh settings.sh 

CMD sh -c "./settings.sh && nginx -g 'daemon off;'"


# Инструкция Dockerfile, которая позволяет определить, как Docker должен проверять, что контейнер работает корректно. 
# Она полезна для автоматического мониторинга состояния контейнера и автоматического восстановления .
HEALTHCHECK --interval=5m --timeout=3s \
CMD curl -f http://localhost:80 || exit 1
