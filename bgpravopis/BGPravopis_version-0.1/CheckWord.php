<?php
	ob_start();
	session_start();
	header("Content-Type: text/html; charset=windows-1251");
	require("proposals.php");
	$word = $_POST['word'];
	if ($word != null){
		$query = mysql_query("SELECT * FROM words WHERE word='{$_POST['word']}'");
		if(mysql_num_rows($query) > 0){
			header("location: index.php?check=correct");
		}else{
			header("location: index.php?check=incorrect");
			$s = proposals($word);
			$_SESSION['incorrect'] = $s;
		}
		unset($word);
	}else{
		header("location: index.php");
	}
	ob_flush();
?>
