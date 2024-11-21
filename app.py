
# What happens when you run the following code?

# We first filter the numbers that are between 10 and 50 and are divisible by 3 or 5.
# Then we apply a lambda function to each number in the filtered list.

def process_numbers(numbers):
    return sum(
        map(lambda x: x**3 if x % 3 == 0 else x**2,
            filter(lambda x: 10 <= x <= 50 and (x % 3 == 0 or x % 5 == 0), numbers))
    )


nums = [5, 12, 18, 23, 30, 45, 51]


print(process_numbers(nums))
