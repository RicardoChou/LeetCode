/*
 * @lc app=leetcode.cn id=1418 lang=golang
 *
 * [1418] 点菜展示表
 */

// @lc code=start
func displayTable(orders [][]string) [][]string {
	// 保存所有的食物的名称
	nameMap := map[string]struct{}{}
	// 保存桌号和该桌的对应的食物的点餐数量
	foodCountMap := map[int]map[string]int{}
	// 遍历给定的订单并提取各种信息
	for _, order := range orders {
		tableId, _ := strconv.Atoi(order[1])
		foodName := order[2]
		nameMap[foodName] = struct{}{}
		if foodCountMap[tableId] == nil {
			foodCountMap[tableId] = map[string]int{}
		}
		foodCountMap[tableId][foodName]++
	}

	// 提取食物名称并且按照字符序排序
	n := len(nameMap)
	names := make([]string, 0, n)
	for name := range nameMap {
		names = append(names, name)
	}
	sort.Strings(names)

	// 提取桌号并按桌号升序排序
	m := len(foodCountMap)
	tableIds := make([]int, 0, m)
	for id := range foodCountMap {
		tableIds = append(tableIds, id)
	}
	sort.Ints(tableIds)

	res := make([][]string, m+1)
	res[0] = make([]string, 1, n+1)
	res[0][0] = "Table"
	res[0] = append(res[0], names...)
	for i, id := range tableIds {
		count := foodCountMap[id]
		res[i+1] = make([]string, n+1)
		res[i+1][0] = strconv.Itoa(id)
		for j, name := range names {
			res[i+1][j+1] = strconv.Itoa(count[name])
		}
	}
	return res
}

// @lc code=end

