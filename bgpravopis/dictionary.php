<meta http-equiv="content-type" content="text/html; charset=windows-1251"> 
<?php 
	$server = "localhost";
	$username = "root";
	$password = "";
	$db_name = "project";

	$connect = mysql_connect($server, $username, $password) or die (mysql_error());
	mysql_select_db($db_name) or die(mysql_error());

	mysql_query("SET NAMES utf8");

	$cyr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while($row = mysql_fetch_array($result)){ 
		$string[] = $row['word'];
	} 
	if(count($string) == 0){ 
		echo "nqma nishto v bazata danni"; 
	} 
	else{ 
		for($i = 0; $i < 25; $i++){ 
			foreach($string as $v){ 
				if(trim($v{0}) == trim($cyr{$i})){ 
					${arr.$i}[] = $v; 
				} 
			} 
		} 
	} 
	for($j = 0; $j < 25; $j++){ 
		switch($_GET['word']){ 
			case $cyr{$j}:
				if(count(${arr.$j}) == 0){ 
					echo "Nishto ne e namereno"; 
				} 
				else{ 
					foreach(${arr.$j} as $c){ 
						echo "<a href='description.php?word=$c'>$c</a><br />"; 
					} 
				} 
				break; 
		} 
	}
?> 