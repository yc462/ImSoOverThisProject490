# Project490
PHP Project Kehoe Class




Web application allowing a system where users will be able to login, with their unique credentials, and utilize our music tracking system. Users will be able to store their favorites and other personalize information. Our database will be structured so that users will get a comprehensive view of their music (genre, artist, etc), and will be given recommendations based on what they like.

The Installation Steps

Steps for installing on a four server architecture: Web Server (192.168.0.1)

Complete List of all Dependencies to Install

sudo apt-get install apache2 php7.0 git sudo apt-get install php7.0 php-amqp rabbitmq-server git sudo apt-get install php7.0 php-amqp php7.0-mysql mysql-server git sudo apt-get install php7.0 php-amqp curl php-curl git sudo apt-get install -y vim sudo apt-get install -y aptitude sudo apt-get install -y syslog-ng-core sudo apt-get install -y syslog-ng-mod-amqp sudo apt-get install -y php7.0-mbstring sudo apt-get install -y php-amqp

Configure Apache

Create symlink from project to apache www directory

sudo ln -s ~/Project490/public /var/www

Change apache DocumentRoot to /var/www/public

sudo vim /etc/apache2/sites-available/000-default.conf

Create symlink to php amqp.ini for Apache enabling

sudo ln -s /etc/php/mods-available/amqp.ini /etc/php/7.0/apache2/conf.d/

Restart apache server

sudo service apache2 restart

RabbitMQ Server (192.168.0.2)

sudo apt-get install php7.0 php-amqp php7.0-mysql mysql-server git

rabbitmqadmin -q import ~/Project490/Extras/rabbitMQ_Config.json

sudo ln -s /etc/php/mods-available/amqp.ini /etc/php/7.0/cli/conf.d

sudo service rabbitmq-server restart

Run php logServer.php

Database Server (192.168.0.3)

sudo apt-get install php7.0 php-amqp php7.0-mysql mysql-server git

sudo ln -s /etc/php/mods-available/amqp.ini /etc/php/7.0/cli/conf.d

ln -s /etc/php/mods-available/amqp.ini /etc/php/7.0/cli/conf.d

MySQL Configuration

Create User: root Password: root
Create Database: Music490
Run ~/Project490/Extras/Backup.sql

Run php dataServer.php

Run php authServer.php

DMZ/API Server (192.168.0.4)

apt-get install php7.0 php-amqp curl php-curl git

sudo ln -s /etc/php/mods-available/amqp.ini /etc/php/7.0/cli/conf.d

Run php apiServer.php

Last Step!

"IF" all 4 PHP server files are running, type in http://192.168.0.1 and login, have fun!

Added Bonus Tips:

** INITIAL RabbitMQ access is LOCALHOST SERVICE ONLY!! while in guest mode **

Open a browser, in dialog box type "localhost:15672" Rabbitmq login page username = guest login = guest [Admin] tab, this is where a new user or Virtual Host can be added.

git clone https://github.com/yc462/Project490.git ~/

Creators

Yvens Cajuste - RabbitMQ, PHP, HTML, CSS
Jonah Silicieux - RabbitMQ
Irena Muskaj - MySQL Database
Micah Nagee - Discorgs API, PHP

