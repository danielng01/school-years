<?php 
require("ConnectToDatabase.php");
$sql =
"SELECT * FROM users 
WHERE
	users.username='{$_POST['username']}' and users.password='{$_POST['password']}'";
$result = mysql_query($sql);
if(mysql_num_rows($result))
{
	echo "ima takuv potr";
	$_SESSION['login']=true;
	$user = mysql_fetch_assoc($result);
	$_SESSION['username'] = $user['username'];
	header("location:index.php");
}
else
{
	echo "nqma takuv potrebitel";
	$_SESSION['login']=false;
}