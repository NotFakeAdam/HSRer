using System.Diagnostics;

internal class HSRer
{
    private static void Main(string[] args)
    {
        Console.Title = "HSRer";

        Console.WriteLine("Press anything to rail stars...");
        Console.ReadKey(true);

        var ProcessesByName = Process.GetProcessesByName("StarRail");
        if (ProcessesByName.Length != 0)
        {
            foreach (var Process in ProcessesByName)
                if (Process != null)
                    Process.Kill();

            Console.WriteLine("Railed all the stars.");
        }
        else
            Console.WriteLine("No stars to rail...");

        Console.ReadKey(true);
    }
}