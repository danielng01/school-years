<?php
    require("DatabaseConfiguration.php");
	
	$username  = htmlspecialchars($_POST['username']);
	$password  = htmlspecialchars($_POST['password']);
	$password2 = htmlspecialchars($_POST['password2']);
	$email 	   = htmlspecialchars($_POST['email']);
	$email2    = htmlspecialchars($_POST['email2']);
	$checked = false;	
	$exist = false;
	
	if (($password === $password2) && ($email === $email2) && ($username != '') && ($password != '') && ($email != '') && ($username != ' ')){
		$checked = true;
	}
	$result = mysql_query("SELECT id FROM test WHERE username = '$username'");  
	while($record = mysql_fetch_assoc($result)){ 
		$exist = true;			
	}		
	if (($checked === true) && ($exist === false)){
		mysql_query("INSERT INTO `project`.`test` (`id`, `username`, `password`, `email`, `logged`) VALUES (NULL, '$username', '$password', '$email', 'no');");
	}
	if (($exist === true) && ($checked === true)){
		echo('Sorry, such an user exist! <br />');
	}
	elseif ($checked === true){
		echo('Congratulations you have succsessfuly registered! <br />');
	}
	if ($checked === false){
		echo('You have entered unvalid information');
	}
	
	
//  mysql_query("DELETE FROM `project`.`test` WHERE `test`.`username` = '$username';");
//	}	
//	foreach('username' as $k => $value)
//	{
//		echo $k. '-->' .$value. '<br />';
//	}	
//	$result = mysql_query("SELECT id, username, password, email FROM test");  
//	while($record = mysql_fetch_assoc($result)){ 
//		echo  $record['id'] . " --- > "; 
//		echo  $record['username'] . " --- > "; 
//		echo  $record['password'] . " --- > "; 
//		echo  $record['email'] . "<br />"; 
//	}
	header('Location: 1.SampleWiki.php');
//	echo("Ready<br />");
?>
