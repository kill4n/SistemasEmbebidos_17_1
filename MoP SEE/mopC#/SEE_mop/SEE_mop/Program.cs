using System;
using System.Diagnostics;

namespace SEE_mop
{
    class MainClass
    {
        public static bool running = true;
        public static void Main(string[] args)
        {
            Console.WriteLine("Starting master of Pupets!");
            try
            {
                var p = Process.Start("/home/pi/Desktop/camSeg/camSeg");
                p.Exited += P_Exited;
                while (running) ;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: ", ex.Message);
            }
        }

        private static void P_Exited(object sender, EventArgs e)
        {
            running = false;
        }
    }
}
