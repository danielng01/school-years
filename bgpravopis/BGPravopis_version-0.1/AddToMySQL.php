<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php
	set_time_limit(0);
	header("Content-Type:text/html;charset=utf-8");
	
	$server = "localhost";
	$username = "root";
	$password = "";
	$db_name = "bgpravopis";

	$connect = mysql_connect($server, $username, $password) or die (mysql_error());
	mysql_select_db($db_name) or die(mysql_error());
	
	mysql_query("SET NAMES 'cp1251'");
	$lines=file("proba2.txt");
	foreach($lines as $line){
		$sql = "INSERT INTO `bgpravopis`.`words` (`id`, `word`) VALUES (NULL, '{$line}')";
		mysql_query($sql);
	}
?>
