//Enter total number of questions:
var totalquestions=30

//Enter the solutions corresponding to each question:
var correctchoices=new Array()
correctchoices[1]='d' //question 1 solution
correctchoices[2]='c' //question 2 solution, and so on.
correctchoices[3]='d'
correctchoices[4]='d'
correctchoices[5]='a'
correctchoices[6]='b'
correctchoices[7]='b'
correctchoices[8]='c'
correctchoices[9]='a'
correctchoices[10]='d'
correctchoices[11]='c'
correctchoices[12]='c'
correctchoices[13]='a'
correctchoices[14]='b'
correctchoices[15]='c'
correctchoices[16]='b'
correctchoices[17]='b'
correctchoices[18]='b'
correctchoices[19]='a'
correctchoices[20]='b'
correctchoices[21]='b'
correctchoices[22]='d'
correctchoices[23]='d'
correctchoices[24]='b'
correctchoices[25]='b'
correctchoices[26]='a'
correctchoices[27]='c'
correctchoices[28]='c'
correctchoices[29]='c'
correctchoices[30]='b'

/////Don't edit beyond here//////////////////////////

function gradeit(){
var incorrect=null
for (q=1;q<=totalquestions;q++){
	var thequestion=eval("document.myquiz.question"+q)
	for (c=0;c<thequestion.length;c++){
		if (thequestion[c].checked==true)
		actualchoices[q]=thequestion[c].value
		}
		
	if (actualchoices[q]!=correctchoices[q]){ //process an incorrect choice
		if (incorrect==null)
		incorrect=q
		else
		incorrect+="/"+q
		}
	}

if (incorrect==null)
incorrect="a/b"
document.cookie='q='+incorrect
if (document.cookie=='')
alert("Your browser does not accept cookies. Please adjust your browser settings.")
else
window.location="11results_HSm2.html"
}


function showsolution(){
var win2=window.open("","win2","width=200,height=350, scrollbars")
win2.focus()
win2.document.open()
win2.document.write('<title>Solution</title>')
win2.document.write('<body bgcolor="#FFFFFF">')
win2.document.write('<center><font face="Arial">')
for (i=1;i<=totalquestions;i++){
for (temp=0;temp<incorrect.length;temp++){
if (i==incorrect[temp])
wrong=1
}
if (wrong==1){
win2.document.write("Question "+i+"="+correctchoices[i].fontcolor("red")+"<br>")
wrong=0
}
else
win2.document.write("Question "+i+"="+correctchoices[i]+"<br>")
}
win2.document.write('</center></font>')
win2.document.close()
}
                                                                                                                                                                                   