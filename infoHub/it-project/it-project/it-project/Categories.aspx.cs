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
using System.Web.Profile;

namespace it_project
{
    public partial class Categories : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void chk1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string subscriptions="";
            foreach (ListItem item in chk1.Items)
            {
                if (item.Selected == true)
                {
                    subscriptions += item.Value + ",";
                }
            }
            subscriptions=subscriptions.Remove(subscriptions.Length-1,1);

            AccountProfile.CurrentUser.Subscriptions = subscriptions;
            Label2.Text = AccountProfile.CurrentUser.Subscriptions;

        }
    }
}