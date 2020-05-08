<html>
<head>
	<?php
		include("include/head.html");
		require("include/menu.php");
		require("ConnectToDatabase.php");
	?>
	<meta http-equiv="Content-type" content="text/html" charset="windows-1251" />
	<script type="text/javascript" src="js/jquery-1.6.2.min.js"></script>
	<script type="text/javascript" charset="windows-1251" src="register.js"></script>
	<link type="text/css" rel="stylesheet" href="register.css" />
	<link type="text/css" rel="stylesheet" href="menu.css" />
</head>
<?php
	$testQuestions = htmlspecialchars($_POST['testQuestions']);
	$result1 = mysql_query("SELECT * FROM invitedWords WHERE correctWord != '' ORDER BY RAND( ) LIMIT {$testQuestions}");
	if($result1){
		while($record1 = mysql_fetch_assoc($result1)){
			$chosen = $record1['id'];
			echo "$chosen <br />";					
			echo $record1['correctWord']."<br />";
			echo $record1['wrongWord']."<br />";
			
			Echo "<html>";
			echo "<input type=\"text\" name=\"answer\" id=\"answer\" />";
			echo "<input type=\"submit\" name=\"submit\" value=\"Отговорете\" />";
			echo "<br /><br />";
			echo "</html>";
		}
	}
?>
</html>
