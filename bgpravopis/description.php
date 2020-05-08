<meta http-equiv="content-type" content="text/html; charset=windows-1251"> 
<?php 	
	$server = "localhost";
	$username = "root";
	$password = "";
	$db_name = "project";

	$connect = mysql_connect($server, $username, $password) or die (mysql_error());
	mysql_select_db($db_name) or die(mysql_error());

	mysql_query("SET NAMES utf8");

	$query = "select word, body from dictionary"; 
	$result = mysql_query($query) or die (mysql_error()); 

	while($row = mysql_fetch_array($result)){ 
		$string[] = $row['word'];
		$body[] = $row['body']; 
	}
	$arr = array_combine($string, $body); 

	foreach($arr as $v=>$b){ 
		switch($_GET['word']){ 
		case "$v": 
			if(count($arr) == 0){ 
				echo "Nishto ne e namereno"; 
			} 
			else{ 
				echo $b."<br />";
			} 
			break; 
		} 
	} 
?> 