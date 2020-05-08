using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;


namespace it_project
{
    public partial class Register : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (User.Identity.IsAuthenticated)
            {
                Response.Redirect("~/");
            }
            if (!Roles.RoleExists("User"))
            {
                Roles.CreateRole("User");
            }

        }
        protected void CreateUserWizard1_FinishButtonClick(object sender, WizardNavigationEventArgs e)
        {
            Response.Redirect("~/");
        }

        protected void CreateUserWizard1_CreatedUser(object sender, EventArgs e)
        {
            Roles.AddUserToRole(CreateUserWizard1.UserName, "User");
        }
        protected void Register_ServerClick(object sender, EventArgs e)
        {   /*
            test.InnerText = "registraciq uspeshna";
            SqlConnection myConnection = new SqlConnection();
            myConnection.ConnectionString = "Data Source=e01059ad-f795-4d30-a6b7-a10301252878.sqlserver.sequelizer.com;User ID=nptrgtzjgtneriac;Password=RjUJ2XBjEZqjTxtoGdGnxg7Uayw72LBxZQ6ofYbRgKkxETKXzrKKTVQJkaHAzDq3";
            myConnection.Open();
            SqlCommand myCommand = new SqlCommand(
                "INSERT INTO USERS (name,email,username,password) VALUES (@name,@email,@username,@password)",myConnection);
            myCommand.Parameters.AddWithValue("@name", name.Value);
            myCommand.Parameters.AddWithValue("@email", email.Value);
            myCommand.Parameters.AddWithValue("@username", username.Value);
            myCommand.Parameters.AddWithValue("@password", password.Value);
            myCommand.ExecuteNonQuery();
            myConnection.Close();*/
        }
    }
}