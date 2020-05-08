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
<body>
	<div id="form">
		<form method=POST>
			<div>
				<table>
					<tr>
						<td>Вярна дума:</td>
						<td><input type="text" id="correctWord" name="correctWord"/></td>
					</tr>
					<tr>
						<td>Грешна дума:</td>
						<td><input type="test" id="wrongWord" name="wrongWord"/></td>
					</tr>
				</table>
				<div style="margin:0 0 0 180px"><input type="submit" name="submit" value="Изпращане"  /></div>
			</div>
		</form>
	</div>
<?php 
	if (isset($_POST['correctWord']) && isset($_POST['wrongWord'])){
		if (($_POST['correctWord'] != null && $_POST['wrongWord'] != null) && ($_POST['correctWord'] != $_POST['wrongWord'])){
			$exist = false;
			$correctWord = htmlspecialchars($_POST['correctWord']);
			$wrongWord = htmlspecialchars($_POST['wrongWord']);
			$result = mysql_query("SELECT * FROM invitedWords WHERE correctWord = '{$correctWord}' AND wrongWord = '{$wrongWord}'");  
			while($record = mysql_fetch_assoc($result)){ 
				$exist = true;			
			}
			if ($exist == false){
				mysql_query("INSERT INTO  `bgpravop_bgpravopis`.`invitedWords` ( `id` ,`correctWord` ,`wrongWord`) VALUES (NULL , '{$correctWord}','{$wrongWord}')");
			}
			unset($_POST['correctWord']); unset($_POST['wrongWord']);
		}	
	}
?>
</body>
</html>