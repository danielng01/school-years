<%@ Page Title="" Language="C#" MasterPageFile="~/SiteTemplate.Master" AutoEventWireup="true" CodeBehind="Questions.aspx.cs" Inherits="it_project.Questions" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="body" runat="server">

    <div class="grid">

        <asp:MultiView ID="MultiView1" runat="server">
            <asp:View ID="View1" runat="server">
                <asp:ListView ID="ListView1" runat="server" DataSourceID="SqlDataSource1">

                    <LayoutTemplate>
                        <span id="itemPlaceholder" runat="server" />
                    </LayoutTemplate>
                    <ItemTemplate>
                        <article class="articles">
                            <section class="article-content">
                                <asp:HyperLink ID="HyperLink1" NavigateUrl='<%# "?pid="+Eval("QuestionNumber") %>' runat="server">
                                    <h2>
                                        <asp:Label ID="SubjectLabel" runat="server"
                                            Text='<%# Eval("Subject") %>' /></h2>
                                </asp:HyperLink><asp:Label ID="BodyLabel" runat="server"
                                    Text='<%# Eval("Body").ToString().Replace(Environment.NewLine, "<br />") %>' />
                            </section>
                            <section class="article-comment">
                                Posted by
                            <asp:Label ID="UserNameLabel" runat="server"
                                Text='<%# Eval("UserName") %>' />
                                on
                            <asp:Label ID="CommentDateLabel" runat="server"
                                Text='<%# Eval("CommentDate") %>' />

                            </section>
                        </article>
                    </ItemTemplate>
                    <ItemSeparatorTemplate>
                    </ItemSeparatorTemplate>
                </asp:ListView>
            </asp:View>
            <asp:View ID="View2" runat="server">
                <asp:SqlDataSource ID="SqlDataSource2" runat="server"
                    ConnectionString="<%$ ConnectionStrings:ConnectionString %>"
                    SelectCommand="SELECT * FROM [Questions] WHERE ([QuestionNumber]=@QuestionNumber)">

                    <SelectParameters>
                        <asp:QueryStringParameter QueryStringField="pid" Name="QuestionNumber"></asp:QueryStringParameter>
                    </SelectParameters>
                </asp:SqlDataSource>
                <asp:ListView ID="ListView2" runat="server" DataSourceID="SqlDataSource2">
                    <LayoutTemplate>
                        <span id="itemPlaceholder" runat="server" />
                    </LayoutTemplate>
                    <ItemTemplate>

                        <h2>
                            <asp:Label ID="SubjectLabel" runat="server"
                                Text='<%# Eval("Subject") %>' /></h2>
                        <asp:Label ID="BodyLabel" runat="server"
                            Text='<%# Eval("Body").ToString().Replace(Environment.NewLine, "<br />") %>' />
                        <br />
                        <fb:like layout="button_count"></fb:like>
                        <div class="g-plusone" data-size="medium" href="<%="http://"+Request.Url.Host+Request.Url.PathAndQuery%>"></div>
                        <br />
                        <fb:comments href="<%="http://"+Request.Url.Host+Request.Url.PathAndQuery%>"></fb:comments>
                    </ItemTemplate>
                    <ItemSeparatorTemplate>
                    </ItemSeparatorTemplate>
                </asp:ListView>
            </asp:View>
        </asp:MultiView>

        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString='<%$ ConnectionStrings:ConnectionString %>' SelectCommand="SELECT aspnet_Users.UserName, Questions.Subject, Questions.Body, Questions.QuestionId,Questions.QuestionNumber, Questions.CommentDate FROM Questions INNER JOIN aspnet_Users ON Questions.UserId = aspnet_Users.UserId ORDER BY Questions.CommentDate DESC"></asp:SqlDataSource>

        <div id="proba" runat="server">
        </div>
    </div>
</asp:Content>
