import csv
with open("data.txt", "r") as f:
  csv_f = open("data_b2.csv", "w")
  writer = csv.writer(csv_f, delimiter=",")
  writer.writerow(["V", "E", "time"])
  for line in f:
    data = line.split(" ")
    print(data)
    writer.writerow([data[7], data[11][:-1], data[-1][:-1]])
  f.close()
