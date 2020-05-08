
function noteClick(note){
	//alert(note.name);
	document.body.innerHTML = "";
	var noteID;
	for(i = 0; i < localStorage.length; i++) {
		var obj = JSON.parse(window.localStorage.getItem(i));
		if(obj.title == note.name){
			noteID = i;
			break;
		}
	}

	var obj = JSON.parse(window.localStorage.getItem(noteID));
	var divForNote  = document.createElement('div');
	//div.innerHTML += " " + window.localStorage.getItem(i);
	var newTitle = document.createElement('h1');
	var newContent = document.createElement('p');
	newTitle.innerHTML = "<a name='"+obj.title+"'>"+obj.title+" samo</a>";
	newContent.innerHTML = obj.content;
	divForNote.appendChild(newTitle);
	divForNote.appendChild(newContent);
	var allLinks = document.createElement('p');
	allLinks.innerHTML = "<a href='index2.html'>View all notes</a>";
	divForNote.appendChild(allLinks);
	document.body.appendChild(divForNote);

}