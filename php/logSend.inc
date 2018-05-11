<?php
require_once('rabbit/path.inc');
require_once('rabbit/get_host_info.inc');
require_once('rabbit/rabbitMQLib.inc');
function errorSend($task, $level, $message)
{
  $client             = new rabbitMQClient("rabbit/logMQ.ini", "testServer");
  $bt                 = debug_backtrace();
  $caller             = array_shift($bt);
  $request            = array();
  $request['type']    = "error";
  $request['server']  = gethostname();
  $request['task']    = $task;
  $request['file']    = $caller['file'];
  $request['line']    = $caller['line'];
  $request['level']   = $level;
  $request['message'] = $message;
  $response           = $client->send_request($request);
  //end of data to send
}
