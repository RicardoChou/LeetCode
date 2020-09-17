import csv
filename = 'data_analyze\data\sitka_weather_2018_simple.csv'
with open(filename) as f:
    reader = csv.reader(f)
    header_row = next(reader)
    stations = []
    for row in reader:
        stations.append(row[0])
    print(stations)
