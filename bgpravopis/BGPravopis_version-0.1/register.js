$(function(){
	$("#formErrors").html("");
	$("#formErrors").hide();
	$("form").submit(function(){
		var isValid=true;
		$("#formErrors").html("");
		if (($("#firstName").val().length ==0)||
			($("#lastName").val().length == 0)||
			($("#username").val().length == 0)||
			($("#passwordAgain").val().length == 0)||
			($("#password").val().length == 0)){
			var isValid=false;
			$("#formErrors").append("<p>������ �� ��������� ������ ������</p>");
		}else{
			if ($("#firstName").val().indexOf(" ") != -1){
				var isValid=false;
				$("#formErrors").append("<p>��� �������� � �����</p>");
			}
			if ($("#lastName").val().indexOf(" ") != -1){
				var isValid=false;
				$("#formErrors").append("<p>��� �������� � ��������</p>");
			}
			/*if ($("#mail").val().indexOf("@") == -1){
				var isValid=false;
				$("#formErrors").append("<p>��������� ����</p>");
			}*/
			if ($("#password").val() != $("#passwordAgain").val()){
				var isValid=false;
				$("#formErrors").append("<p>�������� �� ��������</p>");
			}
			if ($("#sex").val() == 0){
				var isValid=false;
				$("#formErrors").append("<p>�� �� ������� ���</p>");
			}
			if (($("#birthday_day").val() == -1) || ($("#birtday_month").val() == -1) || ($("#birthday_year").val() == -1)){
				var isValid=false;
				$("#formErrors").append("<p>��������� ���� �� �������</p>");
			}
		}
		if (! isValid){
			event.preventDefault();
			$("#formErrors").prepend("<h3>������:</h3>");
			$("#formErrors").show();
		}
	});
});