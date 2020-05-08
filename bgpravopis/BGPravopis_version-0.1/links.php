<?php 
	for ($i=0;$i<32;$i++){ 
		if(chr(192+$i) == "?"){ 
			continue; 
		} 
		if(chr(192+$i) == "?"){ 
			continue; 
		} 
		echo('<a href="dictionary.php?word='.chr(192 + $i).'">'.chr(192 + $i).'</a>||'); 
	} 
?> 