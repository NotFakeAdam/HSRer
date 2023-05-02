printfn "Press anything to rail stars..."
let Key = System.Console.ReadKey(false)

let ProcessesByName = System.Diagnostics.Process.GetProcessesByName("StarRail");

if (ProcessesByName.Length > 0) then
    for gameprocess in ProcessesByName do
        gameprocess.Kill()

    printfn "Railed all the stars."

else
    printfn "No stars to rail..."

System.Console.ReadKey(false)