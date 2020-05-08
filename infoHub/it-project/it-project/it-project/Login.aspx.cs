using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data;
using System.Data.SqlClient;
namespace it_project
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (User.Identity.IsAuthenticated)
            {
                Response.Redirect("~/");
            }

        }


        protected void login_ServerClick(object sender, EventArgs e)
        {
            /*SqlConnection con = new SqlConnection();
            con.ConnectionString = "Data Source=e01059ad-f795-4d30-a6b7-a10301252878.sqlserver.sequelizer.com;User ID=nptrgtzjgtneriac;Password=RjUJ2XBjEZqjTxtoGdGnxg7Uayw72LBxZQ6ofYbRgKkxETKXzrKKTVQJkaHAzDq3";
            con.Open();
            SqlCommand cmd = new SqlCommand(
                "SELECT * FROM Users WHERE (password=@password) AND (username=@username)",con);
            cmd.Parameters.AddWithValue("@username", username.Value);
            cmd.Parameters.AddWithValue("@password", password.Value);
            SqlDataReader myReader = cmd.ExecuteReader();
            bool i = false;
            i = myReader.Read();
            if (i)
            {
                text.InnerText = "logged!!!";
            }
            else
            {
                text.InnerText = "no such user";
            }
            con.Close();*/
        }
    }

}