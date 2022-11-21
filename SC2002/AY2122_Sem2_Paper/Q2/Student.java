package SC2002.AY2122_Sem2_Paper.Q2;

class Course {
  @SuppressWarnings("unused")
  private String name;

  @SuppressWarnings("unused")
  private int unit;
  public Course(String name, int unit) {
    this.name = name;
    this.unit = unit;
  }
}

public class Student {
  @SuppressWarnings("unused")
  private static final int MAX_COURSE_NUM = 6;

  @SuppressWarnings("unused")
  private String name;

  @SuppressWarnings("unused")
  private String grade;

  @SuppressWarnings("unused")
  private Course[] course;
  public Student(String name, String grade, Course[] courses) {
    this.name = name;
    this.grade = grade;
    this.course = courses;
  }
}
