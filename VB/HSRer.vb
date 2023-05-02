Module HSRer
    Sub Main(args As String())

        Console.WriteLine("Press anything to rail stars...")
        Console.ReadKey(False)

        Dim Processes = Process.GetProcessesByName("StarRail")

        If Processes.Length > 0 Then
            For Each GameProcess In Processes
                GameProcess.Kill()
            Next

            Console.WriteLine("Railed all the stars.")
        Else
            Console.WriteLine("No stars to rail...")
        End If

        Console.ReadKey(False)

    End Sub
End Module
