<?php
	//header("Content-Type:text/html;charset=utf-8");
	$server = "localhost:3306";
	$username = "bgpravop_user";
	$password = "41244124";
	$db_name = "bgpravop_bgpravopis";

	$connect = mysql_connect($server, $username, $password);
	mysql_select_db($db_name);
	
	mysql_query("SET NAMES 'cp1251'");
?>
