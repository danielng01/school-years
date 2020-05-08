<html>
	<head>
		<title>Sample Wikipedia Page</title>
		<link rel="stylesheet" type="text/css" href="1.SampleWiki.css"/>
	</head>
	<body>
		<div id="wrapper">
			<h1 id="firstHeading">Most Liked News</h1>
			<div id="wrapperContent">
				<div id="rightbar">
					<div id="bgname"><strong>Login</strong></div>
					<div class="inrightbar">		
						<div id="form-validation"></div>
						<form action="login.php" method="post">
							<table>
								<tbody>			
									<tr>
										<td>Username</td>
										<td><input type="text" name="user" id="user" /></td>
									</tr>			
									<tr>
										<td>Password</td>
										<td><input type="password" name="pass" id="pass1" /></td>
									</tr>
								</tbody>
							</table>	
							<div style="margin:0 0 0 150px"><input value="Login" type="submit" /></div>
						</form>
						<form method="post" action="logout.php">
								<?php 
									require("DatabaseConfiguration.php");
									$result = mysql_query("SELECT username FROM test WHERE logged = 'yes'");  
									while($record = mysql_fetch_assoc($result)){ 
										echo $record['username'];
										echo /*$user.*/ '<br />';
									}
								?>
								<div style="margin:0 0 0 150px"><input value="Logout" type="submit" /></div>
						</form>	
						<hr width="275px"/>
						<form action="bd.php" method="post">
							<div id="bgname"><strong>Registration</strong></div>
							<table>
								<tbody>			
									<tr>
										<td>Username</td>
										<td><input type="text" name="username" id="user" /></td>
									</tr>			
									<tr>
										<td>Password</td>
										<td><input type="password" name="password" id="pass1" /></td>
									</tr>
									<tr>
										<td>Password again</td>
										<td><input type="password" name="password2" id="pass2" /></td>
									</tr>
									<tr>
										<td>Email </td>
										<td><input type="text" name="email" id="email1"/></td>
									</tr>
									<tr>
										<td>Email again</td>
										<td><input type="text" name="email2" id="email2" /></td>
									</tr>			
								</tbody>
							</table>
							<div style="margin:0 0 0 150px"><input value="Registration" type="submit" /></div>
							<br />
							<script type="text/javascript">
								$("form").submit(function(event) {
									$("#form-validation").html("");
									var isValid = true;
		
									if ( $("#user").val().indexOf(" ") != -1 ) {
										isValid = false;
										$("#form-validation").append("<p>Ima interval v username</p>");
									}
		
									if ( $("#pass1").val() != $("#pass2").val() ) {
										isValid = false;
										$("#form-validation").append("<p>pass1 i pass2 sa razlichni</p>");
									}
		
									if ( $("#email1").val() != $("#email2").val() ) {
										isValid = false;
										$("#form-validation").append("<p>email1 i email2 sa razlichni</p>");
									}
				
									if (!isValid) {
										event.preventDefault();
										$("form").addClass("invalid");
										$("#form-validation").prepend("<h2>Ima greshki vav formite</h2>");
									} 
								});
							</script>
						</form>
					</div>
					</div>
				</div>
				<p>Роден е на 3 януари 1969 г. в квартал Хермюлхайм на град Хюрт, Германия. Бащата на Михаел е наемател на карт-пистата в Керпен, която е открита от загиналия през 1961 пилот във Формула 1 Граф Берге фон Трипс. Така че Михаел има възможност от рано да се занимава с моторни спортове. В карт-състезания се среща с някои от бъдещите си съперници като Хайнц-Харалд Френцен и Ник Хайдфелд от Мьонхенгладбах и финландците Мика Хакинен и Мика Сало.</p>
				<p>Кариерата му в моторните спортове започва през 1987 във Формула Кьониг. 1988 става вицешампион във Формула Форд и се включва в тима на Вили Вебер от Формула 3. През 1989 завършва шампионата на второ място при равен брой точки с Френцен зад шампиона Карл Вендлингер. Михаел Шумахер има брат Ралф Шумахер, който също е пилот във Формула 1. Ралф се състезава последно през 2007 година за тима на Тойота, след което се отказа от спорта.</p>
				
				<p id="Zaglavie"><b>Blog</b></p>
				
				<form method="post" action="blog.php">
					<textarea type="text" name="comments" cols="60" rows="6" value="Enter your comments here..." title="comments" 
						onfocus="if (this.value == 'Enter your comments here...') this.value = '';"					
						onblur=  "if (!this.value){ this.value = 'Enter your comments here...'; }" class="bar">Enter your comments here...</textarea>
					<br />
					<div style="margin:0 0 0 400px"><input value="Post The Topic" type="submit" /></div>
				</form>
				<?php
					$result = mysql_query("SELECT id, username, password, email FROM test");  
					while($record = mysql_fetch_assoc($result)){ 
						echo  $record['id'] . " --- > "; 
						echo  $record['username'] . " --- > "; 
						echo  $record['password'] . " --- > "; 
						echo  $record['email'] . "<br />"; 
					}
				?>
				<?php	
					$result = mysql_query("SELECT user, comments FROM blog WHERE likes = '1'");  
					while($record = mysql_fetch_assoc($result)){ 
						echo "<h4>".$record['user']."</h4>";
						echo $record['comments'];						
						echo '<hr align/>';
					}
				?>
				<p id="Zaglavie"><b>Завръщане</b></p>
				<p>В своя сайт, Шумахер съобщава, че ще замени контузения Фелипе Маса в отбора на Ферари за Гран При на Европа във Валенсия на 23 август 2009 г. Една седмица по късно на 10 август 2009 Шуми официално обяви, че няма да може да направи своето завръщане във Ф1 поради болки във врата. През месец февруари 2009г той се контузи тежко при падане с мотор и от тогава има болки във врата.</p>
				
				<p id="Zaglavie"><b>След оттеглянето</b></p>
				<p>От 2007 е консултант на Ферари и отговаря за търсенето на млади пилоти. На 5 септември 2007 е отличен за постиженията си и грабна престижната награда Принцът на Астурия</p>
			</div>			
		</div>
	</body>
</html>