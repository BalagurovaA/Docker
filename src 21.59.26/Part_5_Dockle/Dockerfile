FROM nginx

# - serv.c - код сервера
# - settings.sh - bash-скрипт, чтобы установить все настройки и не вводить вручную
# - nginx.conf -  конфигурационный файл 

COPY ./serv.c ./
COPY  ./settings.sh ./
COPY  ./nginx.conf /etc/nginx/nginx.conf

RUN chmod u-s /usr/bin/su \ 
    /usr/bin/mount \
    /usr/bin/newgrp \
    /usr/bin/chsh \
    /usr/bin/chfn \
    /usr/bin/gpasswd \
    /usr/bin/passwd \
    /usr/bin/umount && \
    chmod 255 /usr/sbin/unix_chkpwd \
    /usr/bin/chage \
    /usr/bin/expiry

RUN touch /var/run/nginx.pid \
    && chown -R nginx:nginx /etc/nginx/nginx.conf /var/cache/nginx /home \
    && chown -R nginx:nginx /var/run/nginx.pid \
    && rm -rf /var/lib/apt/lists/*

RUN chmod +x settings.sh && sh settings.sh
RUN sh settings.sh 

HEALTHCHECK --interval=5m --timeout=3s \
CMD curl -f http://localhost:80 || exit 1

USER nginx

CMD sh -c "./settings.sh && nginx -g 'daemon off;'"