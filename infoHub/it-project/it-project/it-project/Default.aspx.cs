using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data;
using System.Data.SqlClient;
using System.Web.Security;
namespace it_project
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected string notes;
        protected void Page_Load(object sender, EventArgs e)
        {

            /*  string selectSQL;
              selectSQL = "SELECT * FROM Posts";
              SqlConnection con = new SqlConnection();
              con.ConnectionString = "Data Source=e01059ad-f795-4d30-a6b7-a10301252878.sqlserver.sequelizer.com;User ID=nptrgtzjgtneriac;Password=RjUJ2XBjEZqjTxtoGdGnxg7Uayw72LBxZQ6ofYbRgKkxETKXzrKKTVQJkaHAzDq3";
              SqlCommand cmd = new SqlCommand(selectSQL, con);
              SqlDataAdapter adapter = new SqlDataAdapter(cmd);
              DataSet dsPubs = new DataSet();

                  con.Open();
                  // All the information in transferred with one command.
                  // This command creates a new DataTable (named Authors)
                  // inside the DataSet.
                  adapter.Fill(dsPubs, "Posts");
                  con.Close();

              foreach (DataRow row in dsPubs.Tables["Posts"].Rows)
              {
                  proba.InnerHtml="<div class=\"arrows\"><img src=\"~/Images/arrow-up.png\" runat=\"server\" class=\"kartinka\" /><br /><span class=\"score\"></span><br /><img src=\"~/Images/arrow-down.png\" runat=\"server\" class=\"kartinka\" /></div>";
                  proba.InnerHtml+="<div class=\"tile double\">";
                  proba.InnerHtml += "<div class='tile-content'>";
                  proba.InnerHtml += "<h4>" + row["title"].ToString() + "</h4>";
                  proba.InnerHtml += "<p>" + row["content"].ToString() + "</p>";
                  proba.InnerHtml += "</div></div>";
              }
             WebConfigurationManager.ConnectionStrings["Pubs"].ConnectionString;*/
            //proba.InnerText = Session["AccessToken"].ToString();
        }

    }

}