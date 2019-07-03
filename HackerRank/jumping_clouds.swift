// Complete the jumpingOnClouds function below.
func jumpingOnClouds(c: [Int]) -> Int {
    var it = 1
    var jumps = 0
    while it < (c.count-1) {
        it = c[it+1] == 0 ? it + 2 : it + 1
        jumps += 1
    }
    return (it < c.count) ? jumps+1 : jumps
}