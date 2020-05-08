<?php
	$server = "localhost";
	$username = "root";
	$password = "";
	$db_name = "bgpravopis";

	$connect = mysql_connect($server, $username, $password) or die (mysql_error());
	mysql_select_db($db_name) or die(mysql_error());

	mysql_query("SET NAMES utf8");
?>