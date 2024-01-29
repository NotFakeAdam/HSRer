printfn "Press anything to derail stars..."
let Key = System.Console.ReadKey(false)

let ProcessesByName = System.Diagnostics.Process.GetProcessesByName("StarRail");

if (ProcessesByName.Length > 0) then
    for gameprocess in ProcessesByName do
        gameprocess.Kill()

    printfn "Derailed all the stars."

else
    printfn "No stars to derail..."

System.Console.ReadKey(false)
