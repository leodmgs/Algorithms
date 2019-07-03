// Complete the plusMinus function below.
func plusMinus(arr: [Int]) -> Void {
    var ps = 0
    var ns = 0
    var zs = 0
    for i in 0..<arr.count {
        if arr[i] > 0 { ps += 1 }
        if arr[i] < 0 { ns += 1 }
        if arr[i] == 0 { zs += 1 }
    }
    print(String(format: "%.6f", Double(ps) / Double(arr.count) ))
    print(String(format: "%.6f", Double(ns) / Double(arr.count) ))
    print(String(format: "%.6f", Double(zs) / Double(arr.count) ))
}