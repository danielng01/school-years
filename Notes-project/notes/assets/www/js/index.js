
function getUrlVars() {
    var vars = {};
    var parts = window.location.href.replace(/[?&]+([^=&]+)=([^&]*)/gi, function(m,key,value) {
        vars[key] = value;
    });
    return vars;
}

      //Set your global init settings here
      //This is the setting you are looking for!      
  $.mobile.defaultPageTransition = 'none';
  $.mobile.buttonMarkup.hoverDelay = 0;
function SubmitNote() {
	var title = document.getElementById("title");
	var content = document.getElementById("noteContent");
	var noteObject = { 'title' : title.value, 'content': content.value};
	localStorage.setItem(localStorage.length, JSON.stringify(noteObject));
	
}
var tpl = new Array();

function load_templates() {
    // Extend this array if you have more templates
    var templates = ['index2','note'];

    $.each( templates, function( i, e ) {
        $.ajax({
            url: 'tpl/' + e + '.tpl',
            success: function( data ) {
                tpl[ e ] = data;
            },
            async: false,
            dataType: 'html'
            });
    });
}

$('#page').on('pagecreate', function(event) {
    // Load the templates
	load_templates();
	//alert(window.location.pathname);
	if(window.location.pathname=="/assets/www/" ||
		window.location.pathname=="/assets/www/index.html" ||
		window.location.pathname=="/android_asset/www/index.html"||
		window.location.pathname=="/android_asset/www/"||
		window.location.pathname=="/"||
		window.location.pathname=="/index.html" ){
	    
	    for (i = 0; i < localStorage.length; i++) {
	    	if(window.localStorage.getItem(i)=="dani e bog tova nikoi nqma da go napishe")
	    		continue;
	    	var data = JSON.parse(window.localStorage.getItem(i));
		    var renderedHtml = Mustache.to_html( tpl['index2'], data );
		    $('#notes').append(renderedHtml );
	
	    }
	}
	if(window.location.pathname=="/assets/www/note.html"||
			window.location.pathname=="/android_asset/www/note.html"||
			window.location.pathname=="/note.html"
	   ){
		var noteID = getUrlVars()["noteID"];
	    var data = JSON.parse(window.localStorage.getItem(noteID));
	   	var renderedHtml = Mustache.to_html( tpl['note'], data );
	    $('#note').append(renderedHtml );
	}
});

$("#delete-all-notes").bind('vclick', function(){
	localStorage.clear();
	document.location = "index.html";
});
$("#delete-all-notes").bind('click', function(){
	localStorage.clear();
	alert("Deleted...");
	document.location = "index.html";
});

$(document).ready(function() {
$('.note').on('click', function(event) {
    load_templates();
	var noteID;
	note=$(this).find("h2").html();
	//alert(note);
	for(i = 0; i < localStorage.length; i++) {
		if(window.localStorage.getItem(i)=="dani e bog tova nikoi nqma da go napishe")
    		continue;
		var obj = JSON.parse(window.localStorage.getItem(i));
		if(obj.title == note){
			noteID = i;
			//alert(noteID);
			break;
		}
	}
   	var data = JSON.parse(window.localStorage.getItem(noteID));
   	var renderedHtml = Mustache.to_html( tpl['index2'], data ); 
	window.location.href = "note.html?noteID="+noteID; 
	
	   
	
});
});


	$('#notes li').on('click', function() {
	    alert("Works"); // id of clicked li by directly accessing DOMElement property
	});
	$(document).ready(function() {
		  // Handler for .ready() called.
		if (typeof getUrlVars()["theme"] === 'undefined') {
			var theme = 'a';
		    // variable is undefined
		}else{
		  var theme = getUrlVars()["theme"];
		    //set your new theme letter
		    

		    //reset all the buttons widgets
		    $.mobile.activePage.find('.ui-btn')
		                       .removeClass('ui-btn-up-a ui-btn-up-b ui-btn-up-c ui-btn-up-d ui-btn-up-e ui-btn-hover-a ui-btn-hover-b ui-btn-hover-c ui-btn-hover-d ui-btn-hover-e')
		                       .addClass('ui-btn-up-' + theme)
		                       .attr('data-theme', theme);

		    //reset the header/footer widgets
		    $.mobile.activePage.find('.ui-header, .ui-footer')
		                       .removeClass('ui-bar-a ui-bar-b ui-bar-c ui-bar-d ui-bar-e')
		                       .addClass('ui-bar-' + theme)
		                       .attr('data-theme', theme);

		    //reset the page widget
		    $.mobile.activePage.removeClass('ui-body-a ui-body-b ui-body-c ui-body-d ui-body-e')
		                       .addClass('ui-body-' + theme)
		                       .attr('data-theme', theme);
		}
		 });
