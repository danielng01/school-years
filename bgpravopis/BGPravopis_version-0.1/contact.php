<?php 
session_start();
?>
<html>
<head>
	<?php
		include("include/head.html");
	?>
</head>
<body>
	<?php
		include("include/menu.php");
	?>
<!-- Contact form-->
	
<!-- save message -->
	<form name="contact" action="/action/contact" method="POST" onsubmit="return validateContactForm();">
		<table id="contactFormTable" summary="Used for layout reasons">
			<tr>
			<td colspan="2"><h1 class="title">�������, ���������� � ���������</h1></td>
			</tr>
			<tr>
			<td>���:</td>
			<td>&nbsp;</td>
			</tr>
			<tr>
			<td><input type="text" name="name" id="name" size="25" maxlength="100" onkeypress="return processKey(event, this);"/></td>
			<td>&nbsp;</td>
			</tr>
			<tr>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			</tr>
			<tr>
			<td>�-����:</td>
			<td>&nbsp;</td>
			</tr>
			<tr>
			<td><input type="text" name="email" id="email" size="25" maxlength="100" onkeypress="return processKey(event, this);"/></td>
			<td>&nbsp;</td>
			</tr>
			<tr>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			</tr>
			<tr>
			<td>���������:</td>
			</tr>
			<tr>
			<td colspan="2"><textarea name="comment" id="comment" cols="50" rows="10" onkeypress="return processKey(event, this);"></textarea></td>
			</tr>
			<tr>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			</tr>
			<tr>
			<td>&nbsp;</td>
			<td class="right"><button type="submit" name="submit" value="submit">���������</button></td>
			</tr>
			<tr>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			</tr>
			<tr>
			<td class="description" colspan="2">
			������ "���������" � ������������. ��� ������ �� �������� ������� �� �����������,
			������ �� �������� � ����� �� �-����. ����� � ������ �� �-���� ���� �� �����
			���������� �� ������� ����� ���� ����� �� ������� �� ������� ��.
			</td>
			</tr>
			<tr>
			<td colspan="2">
				<div class="social-description">BGPravopis  � ���������� �����:</div>
			</td>
			</tr>
			<tr>
			<td colspan="2">
				<div class="social-media">
				<ul>
					<li class="hover-one"><a href="http://www.facebook.com/" target="_blank" rel="nofollow"><img src="images/facebook.png" alt="Facebook"/> </a></li>
					<li class="hover-two"><a href="http://www.linkedin.com/" target="_blank" rel="nofollow"><img src="images/linked-in.png" alt="Linkedin"/> </a></li>
					<li class="hover-three"><a  href="https://plus.google.com/" target="_blank" rel="nofollow"><img src="images/google.png" alt="Google Plus" /> </a></li>
					<li  class="hover-four"><a href="http://bg.netlog.com/" target="_blank" rel="nofollow"><img src="images/netlog.png" alt="" /> </a></li>
				</ul>    
				</div>
			</td>
			</tr>
		</table>
	</form>
</body>
</html>