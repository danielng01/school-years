//Enter total number of questions:
var totalquestions=42

//Enter the solutions corresponding to each question:
var correctchoices=new Array()
correctchoices[1]='d' //question 1 solution
correctchoices[2]='a' //question 2 solution, and so on.
correctchoices[3]='b'
correctchoices[4]='c'
correctchoices[5]='c'
correctchoices[6]='d'
correctchoices[7]='b'
correctchoices[8]='d'
correctchoices[9]='a'
correctchoices[10]='d'
correctchoices[11]='b'
correctchoices[12]='c'
correctchoices[13]='d'
correctchoices[14]='a'
correctchoices[15]='d'
correctchoices[16]='b'
correctchoices[17]='c'
correctchoices[18]='a'
correctchoices[19]='c'
correctchoices[20]='c'
correctchoices[21]='b'
correctchoices[22]='b'
correctchoices[23]='d'
correctchoices[24]='b'
correctchoices[25]='c'
correctchoices[26]='c'
correctchoices[27]='d'
correctchoices[28]='c'
correctchoices[29]='a'
correctchoices[30]='b'
correctchoices[31]='b'
correctchoices[32]='b'
correctchoices[33]='d'
correctchoices[34]='a'
correctchoices[35]='c'
correctchoices[36]='b'
correctchoices[37]='a'
correctchoices[38]='b'
correctchoices[39]='a'
correctchoices[40]='a'
correctchoices[41]='d'
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
window.location="10results_HSm1.html"
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
                                                                                                                                                                                   