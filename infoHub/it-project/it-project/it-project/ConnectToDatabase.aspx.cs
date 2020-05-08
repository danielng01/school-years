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
    public partial class ConnectToDatabase : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            SqlConnection myConnection = new SqlConnection();
            myConnection.ConnectionString = "Data Source=e01059ad-f795-4d30-a6b7-a10301252878.sqlserver.sequelizer.com;User ID=nptrgtzjgtneriac;Password=RjUJ2XBjEZqjTxtoGdGnxg7Uayw72LBxZQ6ofYbRgKkxETKXzrKKTVQJkaHAzDq3";
            myConnection.Open();
            SqlCommand myCommand = new SqlCommand(
                "Select * from Users", myConnection);
            SqlDataReader myReader = myCommand.ExecuteReader();
            myReader.Read();
            test.InnerText = "connected and readed succsessfull"+myReader["username"];
            myReader.Close();
            myConnection.Close();
        }
    }
}