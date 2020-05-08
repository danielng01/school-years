<?php 
session_start();
ob_start();
?>
<!DOCTYPE html>
<html lang="bg">
    <head>
		<?php
		include("include/head.html");
	?>

	</head>
<!--/header-->

<nav>
<div class="center">
        <a href="index.php" class="current" >Начало</a>
        <a href="Inviting.php" >Добавете дума</a>
        <a href="" >Тестове</a>
        <a href="contact.php" >Контакти</a>
    </div>
</nav>
<div id="content">
<section>
	<img id="logo" src="pravopis.png" />
	<form id='checkWord' method=POST action="CheckWord.php">
		<input id='writeWord'type="text" name="word" />
		<input id='checkButton'type="submit" value="Провери дума" />
	</form>
	<?php
		if(isset($_GET['check'])){
			if($_GET['check']=="correct"){
				echo "<div id='correct' class='check'>Написана правилно</div>";
			}else{
				if(isset($_SESSION['incorrect'])){
					$s = $_SESSION['incorrect'];
					echo "<div id='incorrect' class='check'>";
					if (!count($s)){
						echo 'Написана НЕправилно';
					}else{
						echo 'Може би имахте предвид:<br/>';
						echo "<div id='correct' class='check'>";
						foreach($s as $word){
							echo "$word<br>";
						}
						echo "</div>";
					}
					echo '</div>'; 
				}
			}
		}
	?>
</section>
<?php 
	require("aside.php");
?>
</div>
<?php 
		ob_flush();
?>