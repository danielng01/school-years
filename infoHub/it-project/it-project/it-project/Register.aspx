<%@ Page Language="C#"
    AutoEventWireup="true"
    CodeBehind="Register.aspx.cs"
    Inherits="it_project.Register"
    MasterPageFile="~/SiteTemplate.Master" %>

<asp:Content ID="bodyContent" ContentPlaceHolderID="body" runat="server">
    <div class="Register">
        <asp:CreateUserWizard ID="CreateUserWizard1" runat="server" TabIndex="10000">
            <WizardSteps>
                <asp:CreateUserWizardStep ID="CreateUserWizardStep1" runat="server">
                </asp:CreateUserWizardStep>
                <asp:CompleteWizardStep ID="CompleteWizardStep1" runat="server">
                </asp:CompleteWizardStep>
            </WizardSteps>
        </asp:CreateUserWizard>
    </div>
    <p id="test" runat="server"></p>
</asp:Content>


