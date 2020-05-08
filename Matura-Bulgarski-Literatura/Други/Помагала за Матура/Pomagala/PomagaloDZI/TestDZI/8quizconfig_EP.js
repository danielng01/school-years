//Enter total number of questions:
var totalquestions=42

//Enter the solutions corresponding to each question:
var correctchoices=new Array()
correctchoices[1]='c' //question 1 solution
correctchoices[2]='b' //question 2 solution, and so on.
correctchoices[3]='d'
correctchoices[4]='a'
correctchoices[5]='a'
correctchoices[6]='b'
correctchoices[7]='d'
correctchoices[8]='b'
correctchoices[9]='a'
correctchoices[10]='c'
correctchoices[11]='d'
correctchoices[12]='c'
correctchoices[13]='a'
correctchoices[14]='b'
correctchoices[15]='b'
correctchoices[16]='d'
correctchoices[17]='b'
correctchoices[18]='a'
correctchoices[19]='b'
correctchoices[20]='d'
correctchoices[21]='a'
correctchoices[22]='c'
correctchoices[23]='d'
correctchoices[24]='d'
correctchoices[25]='b'
correctchoices[26]='d'
correctchoices[27]='a'
correctchoices[28]='c'
correctchoices[29]='d'
correctchoices[30]='a'
correctchoices[31]='b'
correctchoices[32]='c'
correctchoices[33]='c'
correctchoices[34]='b'
correctchoices[35]='d'
correctchoices[36]='a'
correctchoices[37]='b'
correctchoices[38]='d'
correctchoices[39]='c'
correctchoices[40]='b'
correctchoices[41]='a'
correctchoices[42]='c'

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
window.location="8results_EP.html"
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
                                                                                                                                                                                   