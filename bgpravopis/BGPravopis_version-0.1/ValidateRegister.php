<?php
if (isset($_POST['submit'])){
	if ($_POST['firstName']==''){
		$hasError=true;
	}
	if ($_POST['lastName']==''){
		$hasError=true;
	}
	if ($_POST['username']==''){
		$hasError=true;
	}
	if ($_POST['password']==''){
		$hasError=true;
	}	
	if ($_POST['passwordAgain']==''){
		$hasError=true;
	}	
	if ($_POST['sex']=='0'){
		$hasError=true;
	}	
	if ($_POST['birthday_day']=='-1'){
		$hasError=true;
	}
	if ($_POST['birthday_month']=='-1'){
		$hasError=true;
	}
	if ($_POST['birthday_year']=='-1'){
		$hasError=true;
	}
	if ($_POST['passwordAgain']!=$_POST['password']){
		$hasError=true;
	}
}
if (isset($_POST['reset'])){
	$_POST=NULL;
}
?>
<?php
	if (isset($hasError)){
?>
	<p class="error">Please check if you've filled all the fields with valid information. Thank you.</p>
<?php
	}else{
		if (isset($_POST['submit'])){
			require("ConnectToDatabase.php");
			$sql = "SELECT * FROM users
					WHERE
					username = '{$_POST['username']}'";
			$result = mysql_query($sql);
			if(mysql_num_rows($result)==0){
		
				$birthday=$_POST['birthday_day'].".".$_POST['birthday_month'].".".$_POST['birthday_year'];
				
				$sql="INSERT INTO {$db_name}.`users`
				(`uid`, `firstName`, `lastName`, `username`, `password`, `sex`, `birthday`)
				VALUES
				(NULL, '{$_POST['firstName']}', '{$_POST['lastName']}', '{$_POST['username']}', '{$_POST['password']}', '{$_POST['sex']}', '{$birthday}');";
				$result = mysql_query($sql);
				if(!$result)
				{
					echo "greshka v zaqvkata!";
				}
				else
				{
					header("location:index.php");
				}
			}else{
			?><script type='text/javascript'>
			$(function(){
				$("#formErrors").append("Не се избралиdasdasdas пол");
			})</script><?php 
			}
		}
	}?>
<?php 
/*	function BackToForm($value){
		if (!isset($hasError)){
			echo $value;
		}
	}*/
?>
