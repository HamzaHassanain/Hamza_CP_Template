import Foundation

struct Item {
    var val: Int64

    init() {
        self.val = 0
    }

    init(_ val: Int64) {
        self.val = val
    }
}

protocol Operation {
    func work(_ a: Item, _ b: Item) -> Item
}

class RangeSumQuery {
    var size: Int
    var DEFAULT: Item
    var data: [Item]
    var operation: Operation

    init(size: Int, defaultValue: Item, operation: Operation) {
        self.size = 1
        self.operation = operation
        self.DEFAULT = defaultValue

        while self.size < size {
            self.size *= 2
        }

        self.data = Array(repeating: Item(), count: 2 * self.size)
    }

    func set(_ i: Int, _ value: Item, _ Item: Int, _ beginSeg: Int, _ endSeg: Int) {
        if beginSeg == endSeg {
            data[Item] = value
            return
        }

        let mid = (beginSeg + endSeg) / 2
        if i <= mid {
            set(i, value, 2 * Item, beginSeg, mid)
        } else {
            set(i, value, 2 * Item + 1, mid + 1, endSeg)
        }

        data[Item] = operation.work(data[2 * Item], data[2 * Item + 1])
    }

    func set(_ i: Int, _ value: Item) {
        set(i, value, 1, 1, size)
    }

    func query(_ left: Int, _ right: Int, _ Item: Int, _ beginSeg: Int, _ endSeg: Int) -> Item {
        if beginSeg > right || left > endSeg {
            return DEFAULT
        }

        if beginSeg > left && endSeg < right {
            return data[Item]
        }

        let mid = (beginSeg + endSeg) / 2
        let a = query(left, right, 2 * Item, beginSeg, mid)
        let b = query(left, right, 2 * Item + 1, mid + 1, endSeg)

        return operation.work(a, b)
    }

    func query(_ left: Int, _ right: Int) -> Item {
        return query(left, right, 1, 1, size)
    }
}


class SumOperation: Operation {
    func work(_ a: Item, _ b: Item) -> Item {
        return Item(a.val + b.val)
    }
}



let n = 5

let st = RangeSumQuery(size: n, defaultValue: Item(0), operation: SumOperation()) 



let values = [1, 2, 3, 4, 5]

for i in 0..<n {
    st.set(i + 1, Item(Int64(values[i])))
}



let result = st.query(2, 4)

print(result.val) 