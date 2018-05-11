#!/usr/bin/php
<?php

require_once('rabbit/path.inc');
require_once('rabbit/get_host_info.inc');
require_once('rabbit/rabbitMQLib.inc');

require_once('php/logSend.inc');
require_once('php/authQuery.inc');


function requestProcessor($request)
{
  switch ($request['type']) {
    case "login": #user login request
      echo "-Login Request-" . PHP_EOL;
      return checkPassword($request['user'], $request['pass']);
      break;


    case "reg": #user registration
      echo "-Register Request-" . PHP_EOL;
      return adduser($request['first'], $request['last'], $request['email'], $request['user'], $request['pass']);
      break;
  }
}


$server = new rabbitMQServer("rabbit/authMQ.ini", "testServer");
$server->process_requests('requestProcessor');
exit();
?>
