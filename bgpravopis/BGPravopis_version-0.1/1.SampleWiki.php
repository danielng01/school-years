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
				<p>����� � �� 3 ������ 1969 �. � ������� ���������� �� ���� ����, ��������. ������ �� ������ � �������� �� ����-������� � ������, ����� � ������� �� ��������� ���� 1961 ����� ��� ������� 1 ���� ����� ��� �����. ���� �� ������ ��� ���������� �� ���� �� �� �������� � ������� ��������. � ����-���������� �� ����� � ����� �� �������� �� ��������� ���� �����-������ ������� � ��� �������� �� �������������� � ����������� ���� ������� � ���� ����.</p>
				<p>��������� �� � ��������� �������� ������� ���� 1987 ��� ������� ������. 1988 ����� ����������� ��� ������� ���� � �� ������� � ���� �� ���� ����� �� ������� 3. ���� 1989 �������� ���������� �� ����� ����� ��� ����� ���� ����� � ������� ��� �������� ���� ����������. ������ ������� ��� ���� ���� �������, ����� ���� � ����� ��� ������� 1. ���� �� ��������� �������� ���� 2007 ������ �� ���� �� ������, ���� ����� �� ������ �� ������.</p>
				
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
				<p id="Zaglavie"><b>���������</b></p>
				<p>� ���� ����, ������� ��������, �� �� ������ ���������� ������ ���� � ������ �� ������ �� ���� ��� �� ������ ��� �������� �� 23 ������ 2009 �. ���� ������� �� ����� �� 10 ������ 2009 ���� ��������� �����, �� ���� �� ���� �� ������� ������ ��������� ��� �1 ������ ����� ��� �����. ���� ����� �������� 2009� ��� �� ������� ����� ��� ������ � ����� � �� ������ ��� ����� ��� �����.</p>
				
				<p id="Zaglavie"><b>���� �����������</b></p>
				<p>�� 2007 � ���������� �� ������ � �������� �� ��������� �� ����� ������. �� 5 ��������� 2007 � ������� �� ������������ �� � ������ ����������� ������� ������� �� �������</p>
			</div>			
		</div>
	</body>
</html>