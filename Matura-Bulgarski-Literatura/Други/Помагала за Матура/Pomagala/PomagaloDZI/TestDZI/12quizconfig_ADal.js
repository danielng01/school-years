//Enter total number of questions:
var totalquestions=35

//Enter the solutions corresponding to each question:
var correctchoices=new Array()
correctchoices[1]='b' //question 1 solution
correctchoices[2]='a' //question 2 solution, and so on.
correctchoices[3]='d'
correctchoices[4]='c'
correctchoices[5]='c'
correctchoices[6]='d'
correctchoices[7]='b'
correctchoices[8]='d'
correctchoices[9]='d'
correctchoices[10]='b'
correctchoices[11]='a'
correctchoices[12]='d'
correctchoices[13]='b'
correctchoices[14]='d'
correctchoices[15]='a'
correctchoices[16]='b'
correctchoices[17]='a'
correctchoices[18]='d'
correctchoices[19]='b'
correctchoices[20]='d'
correctchoices[21]='a'
correctchoices[22]='d'
correctchoices[23]='d'
correctchoices[24]='c'
correctchoices[25]='c'
correctchoices[26]='c'
correctchoices[27]='d'
correctchoices[28]='d'
correctchoices[29]='b'
correctchoices[30]='b'
correctchoices[31]='c'
correctchoices[32]='d'
correctchoices[33]='a'
correctchoices[34]='c'
correctchoices[35]='a'

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
window.location="12results_ADal.html"
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
                                                                                                                                                                                   