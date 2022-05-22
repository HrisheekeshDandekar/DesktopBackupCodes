using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SQL_try
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            CREATE TABLE client_master
            (
            client_no varchar(6),
            name varchar(20), 
            address1 varchar(30), 
            address2 varchar(30), 
            city varchar(15),
            state varchar(15), 
            pincode number(6), 
            bal_due number(10)
            );

            DESCRIBE client_master;
        }
    }
}