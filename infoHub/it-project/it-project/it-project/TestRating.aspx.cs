﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace it_project
{
    public partial class TestRating : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
           /* string pid = Request.QueryString["pid"];
            if (pid == null)
            {
                MultiView1.ActiveViewIndex = 0;
            }
            else
            {
                MultiView1.ActiveViewIndex = 1;
            }
            if (!Page.IsPostBack)
            { }*/
        }

        protected void ThaiRating_Changed(object sender, AjaxControlToolkit.RatingEventArgs e)
        {

        }
    }
}