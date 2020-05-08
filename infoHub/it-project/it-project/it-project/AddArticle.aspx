<%@ Page Title="" Language="C#" MasterPageFile="~/SiteTemplate.Master" AutoEventWireup="true" CodeBehind="AddArticle.aspx.cs" Inherits="it_project.AddArticle" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="body" runat="server">
    <div class="addArticle">
        <h3>Add Article</h3>
        <p>
            <b>Subject:</b>
            <asp:RequiredFieldValidator ID="SubjectReqValidator" runat="server"
                ErrorMessage="You must provide a value for Subject"
                ControlToValidate="Subject" ValidationGroup="EnterComment">
            </asp:RequiredFieldValidator><br />
            <asp:TextBox ID="Subject" Columns="40" runat="server"></asp:TextBox>
        </p>
        <p>
            <b>Body:</b>
            <asp:RequiredFieldValidator ID="BodyReqValidator" runat="server"
                ControlToValidate="Body"
                ErrorMessage="You must provide a value for Body" ValidationGroup="EnterComment">
            </asp:RequiredFieldValidator><br />
            <asp:TextBox ID="Body" TextMode="MultiLine" Width="95%"
                Rows="8" runat="server"></asp:TextBox>
        </p>
        <p>
            <asp:Button ID="PostCommentButton" runat="server"
                Text="Post Your Comment"
                ValidationGroup="EnterComment" OnClick="PostCommentButton_Click" />
        </p>

        <ajaxToolkit:HtmlEditorExtender ID="HtmlEditorExtender1"
            TargetControlID="Body" DisplaySourceTab="true"
            runat="server">
        </ajaxToolkit:HtmlEditorExtender>
    </div>
</asp:Content>
