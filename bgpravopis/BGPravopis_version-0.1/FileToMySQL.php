<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php
set_time_limit(0);
header("Content-Type:text/html;charset=utf-8");
mysql_connect("localhost","root","");
mysql_select_db("bgpravopis");
mysql_query("SET NAMES 'cp1251'");
$lines=file("proba2.txt");
//foreach($lines as $line){
//	
//	$sql = "INSERT INTO `bgpravopis`.`words` (`id`, `word`) VALUES (NULL, '{$line}')";
//	mysql_query($sql);
//}
mysql_query("LOAD DATA LOCAL INFILE 'proba2.txt' INTO TABLE words CHARACTER SET cp1251 LINES TERMINATED BY '\r\n'");