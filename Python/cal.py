# 두 숫자와 연산자를 입력 받는 함수
def get_user_input():
    num1 = float(input("첫 번째 숫자를 입력하세요: "))
    operator = input("연산자를 입력하세요 (+, -, *, /): ")
    num2 = float(input("두 번째 숫자를 입력하세요: "))
    return num1, operator, num2


# 계산 함수
def calculate(num1, operator, num2):
    if operator == "+":
        return num1 + num2
    elif operator == "-":
        return num1 - num2
    elif operator == "*":
        return num1 * num2
    elif operator == "/":
        if num2 != 0:
            return num1 / num2
        else:
            return "오류: 0으로 나눌 수 없습니다."
    else:
        return "오류: 지원하지 않는 연산자입니다."


# 메인 함수
def main():
    num1, operator, num2 = get_user_input()
    result = calculate(num1, operator, num2)
    print(f"결과: {result}")
    if __name__ == "__main__":
        main()
