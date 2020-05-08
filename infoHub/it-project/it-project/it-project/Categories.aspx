<%@ Page Title="" Language="C#" MasterPageFile="~/SiteTemplate.Master" AutoEventWireup="true" CodeBehind="Categories.aspx.cs" Inherits="it_project.Categories" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="body" runat="server">
        <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString='<%$ ConnectionStrings:ConnectionString %>' SelectCommand="SELECT Categories.CategoryName, Articles.Subject FROM Articles INNER JOIN Categories ON Articles.CategoryId = Categories.CategoryId"></asp:SqlDataSource>
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString='<%$ ConnectionStrings:ConnectionString %>' SelectCommand="SELECT * FROM [Categories]"></asp:SqlDataSource>
    <div>
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="CategoryName" HeaderText="CategoryName" SortExpression="CategoryName"></asp:BoundField>
                <asp:BoundField DataField="Subject" HeaderText="Subject" SortExpression="Subject"></asp:BoundField>
            </Columns>
        </asp:GridView>
        
    </div>
    <asp:CheckBoxList ID="chk1" runat="server" DataSourceID="SqlDataSource2" DataTextField="CategoryName" DataValueField="CategoryName" AutoPostBack="True" OnSelectedIndexChanged="chk1_SelectedIndexChanged"></asp:CheckBoxList>
    <asp:Label ID="Label2" runat="server" Text="Label"></asp:Label>
</asp:Content>
