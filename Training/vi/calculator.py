print("Calculator Simulator")
class Calculator:
    def __init__(self, a, b):
        self.a, self.b = a, b
    def add(self):
        return self.a + self.b
    def sub(self):
        return self.a - self.b
    def mul(self):
        return self.a * self.b
    def div(self):
        return self.a / self.b

obj = Calculator(2, 3)
print("addition:", obj.add())
print("subtraction:", obj.sub())
print("multiplication:", obj.mul())
print("division:", obj.div()
