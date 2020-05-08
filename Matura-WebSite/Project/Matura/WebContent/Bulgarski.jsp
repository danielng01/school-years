<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<jsp:include page="header.jsp" />
<div style="clear:both;padding-top: 50px;margin-left:20px;">
<%@ page import="java.net.URLDecoder"%>
<%@page import="java.io.FileReader"%>
<%@page import="java.io.BufferedReader"%>
<%@page import="java.io.File"%>
<%@page import="java.io.*"%>
<%
try {
	String jspPath = session.getServletContext().getRealPath("/");
	File fileDir = new File(jspPath + "/Bulgarski/bulgarski.txt");
	
	BufferedReader in = new BufferedReader(
	   new InputStreamReader(
	                 new FileInputStream(fileDir), "UTF8"));
	
	String str;
	while ((str = in.readLine()) != null) {
	   // System.out.println(str);
		 out.println(str);
	}
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
</div>
<jsp:include page="footer.jsp" /> 