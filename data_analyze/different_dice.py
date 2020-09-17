from die import Die
import pygal
# 创建一个D6和一个D10
die_1 = Die()
die_2 = Die(10)
# 掷骰子多次，并将结果保存在一个列表中
results = []
for roll_num in range(50000):
    reslut = die_1.roll()+die_2.roll()
    results.append(reslut)
# 分析结果
frequencies = []
max_result = die_1.num_sides+die_2.num_sides
for value in range(2, max_result+1):
    frequency = results.count(value)
    frequencies.append(frequency)

# 可视化结果
hist = pygal.Bar()
hist.title = "同时投D6和D10两个骰子得到的结果分布图"
hist.x_labels = ['2', '3', '4', '5', '6', '7', '8',
                 '9', '10', '11', '12', '13', '14', '15', '16']
hist.x_title = "Result"
hist.y_title = "Frequency of Result"
hist.add("D6 + D10", frequencies)
hist.render_to_file("different dice_visual.svg")
