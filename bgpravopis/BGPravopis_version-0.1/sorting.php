<?php
	require("DatabaseConfiguration.php");
	
	$i = 1;
	$result = mysql_query("SELECT views FROM words WHERE wrongWord > 0");  
	while ($record = mysql_fetch_assoc($result)){	
		$array[$i] = $record['views'];
		$correct[$i] = $record['correctWord'];
		$correct[$i] = $record['wrongWord'];
		++$i;
	}
	$swapped = 1;
	while ($swapped){
		$swapped=0;
		for ($k=1; $k<=$i; $k++){
			if ($array[$k] > $array[$k+1]){
				$varContainer = $array[$k];
				$array[$k] = $array[$k+1];
				array[k+1] = $varContainer;
				$swapped = 1;
			}
		}
		$n = $n - 1;
	}
	mysql_query("UPDATE  `bgpravopis`.`words` SET `id` = {$i}, `wrongWord` =  'a' WHERE  `words`.`id` =1;");
?>