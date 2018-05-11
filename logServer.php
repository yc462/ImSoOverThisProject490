#!/usr/bin/php
<?php

require_once('rabbit/path.inc');
require_once('rabbit/get_host_info.inc');
require_once('rabbit/rabbitMQLib.inc');

require_once('php/logRec.inc');

function requestProcessor($request)
{
  switch ($request['type']) {
    case "error":
      echo "-Error Recieved-" . PHP_EOL;
      logMe($request);
      break;
  }
}

$server = new rabbitMQServer("rabbit/logMQ.ini", "testServer");
$server->process_requests('requestProcessor');
exit();
?>
