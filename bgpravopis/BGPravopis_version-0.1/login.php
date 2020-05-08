<?php
	ob_start();
?>
<?php //    require("ConnectToDatabase.php");
//	 
//	$username  = htmlspecialchars($_POST['user']);
//	$password  = htmlspecialchars($_POST['pass']);
//	$exist = false;
//	
//	$result = mysql_query("SELECT * FROM test WHERE username = '$username' AND password = '$password'");  
//	while($record = mysql_fetch_assoc($result)){ 
//		$exist = true;			
//	}
//	if ($exist){
//		echo('Congratulations you have succsessfuly logged in! <br />');
//		mysql_query("UPDATE  `project`.`test` SET  `logged` =  'yes' WHERE  `test`.`username` = '$username';");
//		define($user, $username);
//	}
//	else{
//		echo('Wrong username or password! <br />');
//	}
//	echo($GLOBALS["logged"]);
//	header('Location: 1.SampleWiki.php');
?>
<html>
<head>
	<?php
	include("include/head.html");
	if(isset($_POST['submit'])){
			require("ValidateLogin.php");  //to make
	}
	?>
	<meta http-equiv="Content-type" content="text/html" charset="windows-1251" />
	<script type="text/javascript" src="js/jquery-1.6.2.min.js"></script>
	<script type="text/javascript" charset="windows-1251" src="register.js"></script>
	<link type="text/css" rel="stylesheet" href="register.css" />
	<link type="text/css" rel="stylesheet" href="menu.css" />
</head>
<body>
<?php
	require("include/menu.php");
	function BackToForm($value){
		if (!isset($hasError)){
			echo $value;
		}
	}
	function TryBackToForm($value){
		if(isset($_POST[$value])){
			BackToForm($_POST[$value]);
		}
	}
	
?>

	<div id="form">
	<form method=POST>
		<div>
		<table>
			<tr>
				<td>Потребителско име:</td>
				<td><input type="text" id="username" name="username" value="<?php TryBackToForm('username');?>" /></td>
			</tr>
			<tr>
				<td>Парола:</td>
				<td><input type="password" id="password" name="password"/></td>
			</tr>
		</table>
		<div style="margin:0 0 0 180px"><input type="submit" name="submit" value="Изпращане"  /></div>
		</div>
	</form>
	<div id="formErrors">
		
	</div>
	</div>
<?php 

?>
</body>
</html>
<?php 
	ob_flush();
?>