fn insertion_sort<T: PartialOrd>(arr: &mut [T]) {
    for i in 1..arr.len() {
        let mut j = i;
        while j > 0 && arr[j] < arr[j - 1] {
            arr.swap(j- 1, j);
            j -= 1
        }
    }
}

fn swap<T>(a: &mut T, b: &mut T) {
    std::mem::swap(a, b);
}

fn main() {
    let mut v1 = vec![5, 1, 99, 0, -32];
    insertion_sort(v1.as_mut());
    assert_eq!(vec![-32, 0, 1, 5, 99], v1);
    let mut x = 23i32;
    let mut y = 55i32;
    swap(&mut x, &mut y);
    assert_eq!(55, x);
    assert_eq!(23, y);
}
