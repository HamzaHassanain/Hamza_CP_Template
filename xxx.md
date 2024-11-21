I am an aspiring competitive programmer, I have just started learning what segment trees are, and I have just written my first segment tree, however, it keeps giving me a runtime error.

This is the code I wrote:

```swift

import Foundation

struct Node {
    var val: Int64

    init() {
        self.val = 0
    }

    init(_ val: Int64) {
        self.val = val
    }
}

protocol Operation {
    func work(_ a: Node, _ b: Node) -> Node
}

class SegmentTree {
    var size: Int
    var DEFAULT: Node
    var data: [Node]
    var operation: Operation

    init(size: Int, defaultValue: Node, operation: Operation) {
        self.size = 1
        self.operation = operation
        self.DEFAULT = defaultValue

        while self.size < size {
            self.size *= 2
        }

        self.data = Array(repeating: Node(), count: 2 * self.size)
    }

    // Function to set a value at index i
    func set(_ i: Int, _ value: Node, _ node: Int, _ beginSeg: Int, _ endSeg: Int) {
        if beginSeg == endSeg {
            data[node] = value
            return
        }

        let mid = (beginSeg + endSeg) / 2
        if i <= mid {
            set(i, value, 2 * node, beginSeg, mid)
        } else {
            set(i, value, 2 * node + 1, mid + 1, endSeg)
        }

        data[node] = operation.work(data[2 * node], data[2 * node + 1])
    }

    // Overloaded set function
    func set(_ i: Int, _ value: Node) {
        set(i, value, 1, 1, size)
    }

    // Function to query the range
    func query(_ left: Int, _ right: Int, _ node: Int, _ beginSeg: Int, _ endSeg: Int) -> Node {
        if beginSeg > right || left > endSeg {
            return DEFAULT
        }

        if beginSeg > left && endSeg < right {
            return data[node]
        }

        let mid = (beginSeg + endSeg) / 2
        let a = query(left, right, 2 * node, beginSeg, mid)
        let b = query(left, right, 2 * node + 1, mid + 1, endSeg)

        return operation.work(a, b)
    }

    // Overloaded query function
    func query(_ left: Int, _ right: Int) -> Node {
        return query(left, right, 1, 1, size)
    }
}


class SumOperation: Operation {
    func work(_ a: Node, _ b: Node) -> Node {
        return Node(a.val + b.val)
    }
}




let n = 5

let st = SegmentTree(size: n, defaultValue: Node(0), operation: SumOperation()) 



let values = [1, 2, 3, 4, 5]

for i in 0..<n {
    st.set(i + 1, Node(Int64(values[i])))
}



let result = st.query(2, 4)

print(result.val) 

```

The error is:

```code
Stack dump:
0.      Program arguments: /usr/share/swift/usr/bin/swift-frontend -frontend -interpret /home/hamza/Documents/Github/Hamza_CP_Template/shit.swift -disable-objc-interop -color-diagnostics -new-driver-path /usr/share/swift/usr/bin/swift-driver -empty-abi-descriptor -resource-dir /usr/share/swift/usr/lib/swift -module-name shit -plugin-path /usr/share/swift/usr/lib/swift/host/plugins -plugin-path /usr/share/swift/usr/local/lib/swift/host/plugins
1.      Swift version 5.10.1 (swift-5.10.1-RELEASE)
2.      Compiling with the current language version
3.      While running user code "/home/hamza/Documents/Github/Hamza_CP_Template/shit.swift"
Stack dump without symbol names (ensure you have llvm-symbolizer in your PATH or set the environment var `LLVM_SYMBOLIZER_PATH` to point to it):
/usr/share/swift/usr/bin/swift-frontend(+0x61b7463)[0x5a11083a4463]
/usr/share/swift/usr/bin/swift-frontend(+0x61b541e)[0x5a11083a241e]
/usr/share/swift/usr/bin/swift-frontend(+0x61b77da)[0x5a11083a47da]
/lib/x86_64-linux-gnu/libc.so.6(+0x45320)[0x7a0da4e45320]

```

Please help me find the error in my segment tree template.