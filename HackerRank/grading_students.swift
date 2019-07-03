/*
 * Complete the gradingStudents function below.
 */
func gradingStudents(grades: [Int]) -> [Int] {
    var grades_cpy = grades
    for ig in 0..<grades_cpy.count {
        if grades_cpy[ig] >= 38 {
            var multBy5 = 0
            var grade_it = grades_cpy[ig]
            while multBy5 == 0 && (grade_it - grades_cpy[ig]) < 3 {
                if grade_it % 5 == 0 {
                    multBy5 = grade_it
                    break
                }
                grade_it += 1
            }
            grades_cpy[ig] = multBy5 != 0 ? multBy5 : grades_cpy[ig]
        }
    }
    return grades_cpy
}