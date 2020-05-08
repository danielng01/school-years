<%@ Page Language="C#"
    AutoEventWireup="true"
    CodeBehind="Login.aspx.cs"
    Inherits="it_project.Login"
    MasterPageFile="~/SiteTemplate.Master" %>

<asp:Content ID="bodyContent" ContentPlaceHolderID="body" runat="server">
            <asp:Login ID="Login1" runat="server"
                CssClass="Login" tabindex="10000"
                CreateUserText="Register for the first time"
                CreateUserUrl="Register.aspx"
                InstructionText="Please enter your username and password for <br />logging into the system." >
            </asp:Login>
    <p id="text" runat="server"></p>
</asp:Content>
