<?php
	
	require("DatabaseConfiguration.php");
	
	$correctWord  = htmlspecialchars($_POST['correctWord']);
	$wrongWord  = htmlspecialchars($_POST['wrongWord']);
	$exist = false;
	$checked = false;
	
	if ($correctWord === $wrongWord){
		$checked = true;
	}
	$result = mysql_query("SELECT id FROM dictionary WHERE correctWord = '$correctWord'");  
	while($record = mysql_fetch_assoc($result)){ 
		$exist = true;
	}
	if (($exist === false) && ($checked === false)){
		mysql_query("INSERT INTO  `bgpravopis`.`dictionary` (`id` ,`correctWord` ,`wrongWord`) VALUES (NULL ,  '$correctWord',  '$wrongWord');");
	}
	
	header('Location: Inviting.html');
?>