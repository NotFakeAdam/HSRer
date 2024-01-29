Module HSRer
    Sub Main(args As String())

        Console.WriteLine("Press anything to derail stars...")
        Console.ReadKey(False)

        Dim Processes = Process.GetProcessesByName("StarRail")

        If Processes.Length > 0 Then
            For Each GameProcess In Processes
                GameProcess.Kill()
            Next

            Console.WriteLine("Derailed all the stars.")
        Else
            Console.WriteLine("No stars to derail...")
        End If

        Console.ReadKey(False)

    End Sub
End Module
