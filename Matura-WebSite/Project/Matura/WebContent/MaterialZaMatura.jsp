<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<jsp:include page="header.jsp" />
<%@ page import="java.net.URLDecoder"%>
<%@page import="java.io.FileReader"%>
<%@page import="java.io.BufferedReader"%>
<%@page import="java.io.File"%>
<%@page import="java.io.*"%>
<div style="clear:both;padding-top: 50px;"></div>
<% String[] parameters = URLDecoder.decode(request.getQueryString(), "UTF-8").split("&"); %>
<% String[] proizvedenieArray = parameters[0].split("="); 
String type = proizvedenieArray[1];
//out.println(proizvedenie);

try {
	String jspPath = session.getServletContext().getRealPath("/");
	File fileDir = new File(jspPath + "/Konspekti/" +type+".txt");
	
	BufferedReader in = new BufferedReader(
	   new InputStreamReader(
	                 new FileInputStream(fileDir), "UTF8"));
	
	String str;
	%><pre class = "tekst" style=""><%
	int i = 0;
	while ((str = in.readLine()) != null) {
		if(i==0){
			out.println("<h3><center>");
		}
		if(i<2){
			i++;
		}
	   // System.out.println(str);
		 out.println(str);
		if(i==1){
			out.println("</center></h3>");

		}
	}
%></pre><%
    in.close();
} 
catch (UnsupportedEncodingException e) 
{
	System.out.println(e.getMessage());
} 
catch (IOException e) 
{
	System.out.println(e.getMessage());
}
catch (Exception e)
{
	System.out.println(e.getMessage());
}
%>
<jsp:include page="footer.jsp" /> 