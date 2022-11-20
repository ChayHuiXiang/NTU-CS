package SC2002.AY2122_Sem2_Paper.Q2;

class Course {
  private String name;
  private int unit;
  public Course(String name, int unit) {
    this.name = name;
    this.unit = unit;
  }
}

public class Student {
  private static final int MAX_COURSE_NUM = 6;
  private String name;
  private String grade;
  private Course[] course;
  public Student(String name, String grade, Course[] courses) {
    this.name = name;
    this.grade = grade;
    this.course = courses;
  }
}
