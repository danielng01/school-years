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
    public partial class Articles : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string pid = Request.QueryString["pid"];
            if (pid == null)
            {
                MultiView1.ActiveViewIndex = 0;
            }
            else
            {
                MultiView1.ActiveViewIndex = 1;
            }
            if (!Page.IsPostBack)
            {
              /*  string selectSQL;
                selectSQL = "SELECT * FROM Posts";
                SqlConnection con = new SqlConnection();
                con.ConnectionString = "Data Source=e01059ad-f795-4d30-a6b7-a10301252878.sqlserver.sequelizer.com;User ID=nptrgtzjgtneriac;Password=RjUJ2XBjEZqjTxtoGdGnxg7Uayw72LBxZQ6ofYbRgKkxETKXzrKKTVQJkaHAzDq3";
                SqlDataAdapter myCommand = new SqlDataAdapter(selectSQL, con);
                DataSet ds = new DataSet();
                myCommand.Fill(ds);
                con.Close();
                repeater.DataSource = ds;
                repeater.DataBind();*/
                /*
                var accessToken = Session["AccessToken"].ToString();
                var client = new Facebook.FacebookClient(accessToken);
                dynamic result = client.Get("me", new { fields = "name,id" });
                string name = result.name;
                string id = result.id;
                proba.InnerText = name + " " + id;*/
            }

        }
    }
}