<%@ Page Language="C#"
    AutoEventWireup="true"
    CodeBehind="AddPost.aspx.cs"
    Inherits="it_project.WebForm2"
    MasterPageFile="~/SiteTemplate.Master" %>

<asp:Content ID="bodyContent" ContentPlaceHolderID="body" runat="server">
        <h3>Title:</h3>
            <input id="title" type="text" runat="server" />
            <span class="helper"></span>

        <h3>Content:</h3>
            <textarea id="content" runat="server"></textarea>
        <input id="Submit1" type="submit" value="Submit" runat="server" onserverclick="AddPost_ServerClick" />
        <input type="reset" value="Reset" />
</asp:Content>
