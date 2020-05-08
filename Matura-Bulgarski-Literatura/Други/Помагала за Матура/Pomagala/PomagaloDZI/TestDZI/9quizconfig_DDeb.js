//Enter total number of questions:
var totalquestions=42

//Enter the solutions corresponding to each question:
var correctchoices=new Array()
correctchoices[1]='a' //question 1 solution
correctchoices[2]='c' //question 2 solution, and so on.
correctchoices[3]='c'
correctchoices[4]='d'
correctchoices[5]='b'
correctchoices[6]='d'
correctchoices[7]='a'
correctchoices[8]='c'
correctchoices[9]='b'
correctchoices[10]='b'
correctchoices[11]='c'
correctchoices[12]='a'
correctchoices[13]='b'
correctchoices[14]='c'
correctchoices[15]='b'
correctchoices[16]='d'
correctchoices[17]='a'
correctchoices[18]='b'
correctchoices[19]='d'
correctchoices[20]='c'
correctchoices[21]='c'
correctchoices[22]='d'
correctchoices[23]='a'
correctchoices[24]='b'
correctchoices[25]='c'
correctchoices[26]='c'
correctchoices[27]='d'
correctchoices[28]='a'
correctchoices[29]='b'
correctchoices[30]='d'
correctchoices[31]='d'
correctchoices[32]='c'
correctchoices[33]='d'
correctchoices[34]='a'
correctchoices[35]='b'
correctchoices[36]='a'
correctchoices[37]='c'
correctchoices[38]='d'
correctchoices[39]='c'
correctchoices[40]='b'
correctchoices[41]='c'
correctchoices[42]='d'

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
window.location="9results_DDeb.html"
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
                                                                                                                                                                                   