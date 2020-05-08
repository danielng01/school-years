//Enter total number of questions:
var totalquestions=42

//Enter the solutions corresponding to each question:
var correctchoices=new Array()
correctchoices[1]='c' //question 1 solution
correctchoices[2]='b' //question 2 solution, and so on.
correctchoices[3]='b'
correctchoices[4]='d'
correctchoices[5]='d'
correctchoices[6]='d'
correctchoices[7]='b'
correctchoices[8]='c'
correctchoices[9]='c'
correctchoices[10]='c'
correctchoices[11]='d'
correctchoices[12]='c'
correctchoices[13]='c'
correctchoices[14]='c'
correctchoices[15]='c'
correctchoices[16]='b'
correctchoices[17]='c'
correctchoices[18]='d'
correctchoices[19]='c'
correctchoices[20]='d'
correctchoices[21]='a'
correctchoices[22]='c'
correctchoices[23]='b'
correctchoices[24]='b'
correctchoices[25]='b'
correctchoices[26]='b'
correctchoices[27]='c'
correctchoices[28]='b'
correctchoices[29]='d'
correctchoices[30]='d'
correctchoices[31]='c'
correctchoices[32]='b'
correctchoices[33]='d'
correctchoices[34]='b'
correctchoices[35]='a'
correctchoices[36]='c'
correctchoices[37]='b'
correctchoices[38]='c'
correctchoices[39]='c'
correctchoices[40]='b'
correctchoices[41]='c'
correctchoices[42]='b'

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
window.location="1results.html"
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
                                                                                                                                                                                   