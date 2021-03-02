FROM debian

RUN apt-get update && apt-get install -y apache2 && apt-get clean

CMD ["apachectl", "-D", "FOREGROUND"] 
