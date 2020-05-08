using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Web.Profile;
using System.Web.Security;

namespace it_project
{
    public class AccountProfile : ProfileBase
    {
        static public AccountProfile CurrentUser
        {
            get
            {
                return (AccountProfile)
                       (ProfileBase.Create(Membership.GetUser().UserName));
            }
        }

        public string FullName
        {
            get { return ((string)(base["FullName"])); }
            set { base["FullName"] = value; Save(); }
        }
        public string Subscriptions
        {
            get { return ((string)(base["Subscriptions"])); }
            set { base["Subscriptions"] = value; Save(); }
        }
        // add additional properties here
    }
}