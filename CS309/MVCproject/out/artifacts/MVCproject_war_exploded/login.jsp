<%--
  Created by IntelliJ IDEA.
  User: wendizhou
  Date: 2019-10-17
  Time: 15:07
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Test</title>
</head>
<body>
please login the system
<br/>
<form action="LoginServlet" method="post">
    username: <input type="text" name="username"

                     value="<%=request.getAttribute("username") != null ?
request.getAttribute("username") : ""%>"/>
    <%=request.getAttribute("msg_username") != null ?
            request.getAttribute("msg_username") : ""%>
    <br/>
    password: <input type="password" name="password"

                     value="<%=request.getAttribute("password") != null ?
request.getAttribute("password") : ""%>"/>
    <%=request.getAttribute("msg_password") != null ?
            request.getAttribute("msg_password") : ""%><br/>
    <input type="submit" value="login"/>
    <br/>
    <%=request.getAttribute("msg") != null ?
            request.getAttribute("msg") : ""%>
</form>
</body>
</html>
