// Complete the countingValleys function below.
func countingValleys(n: Int, s: String) -> Int {
    var isDown = false
    var countValleys = 0
    var seeLevel = 0
    for v in s {
        seeLevel = v == "U" ? (seeLevel + 1) : (seeLevel - 1)
        if seeLevel < 0 && !isDown {
            countValleys += 1
            isDown = true
        } else if seeLevel >= 0 && isDown {
            isDown = false
        }
    }
    return countValleys
}