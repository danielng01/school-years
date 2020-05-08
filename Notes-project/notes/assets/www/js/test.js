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
test( "delete-all-notes", function() {
   localStorage.clear();	
  ok( localStorage.length <= 1, "Passed!" );
});
test( "submit", function() {
   var title = "title";
	var content = "content";
	var noteObject = { 'title' : title.value, 'content': content.value};
	localStorage.setItem(localStorage.length, JSON.stringify(noteObject));
	
   ok( localStorage.length >= 0, "Passed!" );
});
test("new-note-page", function() {
	localStorage.clear();
	var noteObject = { 'title' : 'dsa', 'content': 'asd'};
	localStorage.setItem(0, noteObject);
	var note = window.localStorage.getItem(0);

	
	var value = "hello";
	  equal( note, noteObject, "Ok" );
});
