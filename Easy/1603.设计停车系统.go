/*
 * @lc app=leetcode.cn id=1603 lang=golang
 *
 * [1603] 设计停车系统
 */

// @lc code=start
type ParkingSystem struct {
	// 表明剩余车位的数组
	Num [3]int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	// 初始化剩余车位的数组
	return ParkingSystem{[3]int{big, medium, small}}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	// 如果当前所属类型的车位为0，返回false
	if this.Num[carType-1] == 0 {
		return false
	} else {
		// 当前所属类型的车位减一，并返回true
		this.Num[carType-1]--
		return true
	}
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */
// @lc code=end

