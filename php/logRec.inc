<?php
function logMe($request)
{
  switch ($request['level']) {
    case 1:
      $log_file = '../logs/log_1.txt';
      break;   
  }
  if (!is_file($log_file)) {
    //Some simple example content.
    $contents = 'Time - Server - Task - File - Line - Message' . PHP_EOL;
    //Save our content to the file.
    file_put_contents($log_file, $contents);
  }
  $handle = fopen($log_file, 'a') or die('Cannot open file:  ' . $log_file);
  $msgout = date("m/d/Y h:i:s A") . " - " . $request['server'] . " - " . $request['task'] . " - " . $request['file'] . " - " . $request['line'] . " - " . $request['message'] . PHP_EOL;
  fwrite($handle, $msgout);
}

?>
