def main():
    try:
        while True:
            n = int(input())

            input_lst = list(map(float, input().split(" ")))
            temp_lst = [0 for _ in range(n)]
            predecessores = [0 for _ in range(n)]

            for index, item in enumerate(input_lst):
                temp_lst[index] = 1
                predecessores[index] = 0

                for j in range(index):
                    if input_lst[j] < input_lst[index] and ((1 + temp_lst[j]) > temp_lst[index]):
                        temp_lst[index] = 1 + temp_lst[j]
                        predecessores[index] = j

            big = max(temp_lst)
            
            print(big)
    except EOFError:
        return 0

    return 0

if __name__ == "__main__":
    main()

