// Complete the staircase function below.
func staircase(n: Int) -> Void {
    var a = Array(repeating: " ", count: n)
    for i in 0..<n {
        a[(n-1)-i] = "#"
        print(a.joined())
    }
}