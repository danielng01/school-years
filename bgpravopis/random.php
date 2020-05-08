<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
	<meta http-equiv="Content-Language" content="bg"/>
</head>
</html>
<?php
	
	require("DatabaseConfiguration.php");
	$i = 0;
	$b = 0;
	
	$result = mysql_query("SELECT id FROM dictionary");  
	while($record = mysql_fetch_assoc($result)){ 
			$i = $record['id'];
			if ($b === 0){
				$b = $i;
			}
	}
	$c = rand($b, $i);
	
	$result = mysql_query("SELECT correctWord, wrongWord FROM dictionary WHERE id = $c");  
	while($record = mysql_fetch_assoc($result)){ 
			$correctWord = $record['correctWord'];
			echo "$correctWord".'<br/>';	
			echo $record['wrongWord'].'<br/>';
	}
?>
<html>
	<body>
		<form method="post">
			<input type="text" name="answer" id="answer" />
			<div><input value="Answer" type="submit" /></div>			
		</form>		
	</body>
</html>
<?php	
	$answer  = htmlspecialchars($_POST['answer']);
	
	if ($answer == $correctWord){
		echo 'Bravo!';
		echo "$c";
	}
?>