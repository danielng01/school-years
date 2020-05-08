//Enter total number of questions:
var totalquestions=42

//Enter the solutions corresponding to each question:
var correctchoices=new Array()
correctchoices[1]='c' //question 1 solution
correctchoices[2]='a' //question 2 solution, and so on.
correctchoices[3]='d'
correctchoices[4]='b'
correctchoices[5]='c'
correctchoices[6]='a'
correctchoices[7]='b'
correctchoices[8]='d'
correctchoices[9]='d'
correctchoices[10]='b'
correctchoices[11]='a'
correctchoices[12]='c'
correctchoices[13]='d'
correctchoices[14]='b'
correctchoices[15]='a'
correctchoices[16]='c'
correctchoices[17]='a'
correctchoices[18]='d'
correctchoices[19]='b'
correctchoices[20]='d'
correctchoices[21]='a'
correctchoices[22]='c'
correctchoices[23]='c'
correctchoices[24]='d'
correctchoices[25]='c'
correctchoices[26]='a'
correctchoices[27]='d'
correctchoices[28]='b'
correctchoices[29]='c'
correctchoices[30]='c'
correctchoices[31]='d'
correctchoices[32]='c'
correctchoices[33]='b'
correctchoices[34]='a'
correctchoices[35]='b'
correctchoices[36]='a'
correctchoices[37]='a'
correctchoices[38]='c'
correctchoices[39]='a'
correctchoices[40]='c'
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
window.location="15results_NVap.html"
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
                                                                                                                                                                                   