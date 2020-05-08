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
			$("#formErrors").append("<p>Трябва да попълните всички полета</p>");
		}else{
			if ($("#firstName").val().indexOf(" ") != -1){
				var isValid=false;
				$("#formErrors").append("<p>Има интервал в името</p>");
			}
			if ($("#lastName").val().indexOf(" ") != -1){
				var isValid=false;
				$("#formErrors").append("<p>Има интервал в фамилята</p>");
			}
			/*if ($("#mail").val().indexOf("@") == -1){
				var isValid=false;
				$("#formErrors").append("<p>Невалидна поща</p>");
			}*/
			if ($("#password").val() != $("#passwordAgain").val()){
				var isValid=false;
				$("#formErrors").append("<p>Паролите не съвпадат</p>");
			}
			if ($("#sex").val() == 0){
				var isValid=false;
				$("#formErrors").append("<p>Не се избрали пол</p>");
			}
			if (($("#birthday_day").val() == -1) || ($("#birtday_month").val() == -1) || ($("#birthday_year").val() == -1)){
				var isValid=false;
				$("#formErrors").append("<p>Невалидна дата на раждане</p>");
			}
		}
		if (! isValid){
			event.preventDefault();
			$("#formErrors").prepend("<h3>Грешки:</h3>");
			$("#formErrors").show();
		}
	});
});