//#include <fstream>
//#include <iostream>
//#include <string>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//int priority(char ch)
//{
//	if (ch == '+' || ch == '-') return 1;
//	if (ch == '*' || ch == '/') return 2;
//	return 0;
//}
//
//void print_Debug(stack<char> stack, queue<char> queue)
//{
//	cout << "Stack : ";
//	while (!stack.empty())
//	{
//		cout << stack.top();
//		stack.pop();
//	}
//	cout << endl;
//	cout << "Queue : ";
//	while (!queue.empty())
//	{
//		cout << queue.front(); 
//		queue.pop();
//	}
//	cout << endl << endl;
//}
//
//double calculate(double a, double b, char ch)
//{
//	switch (ch)
//	{
//	case '+':
//		return a + b;
//		break;
//	case '-':
//		return a - b;
//		break;
//	case '*':
//		return a * b;
//		break;
//	case '/':
//		return a / b;
//		break;
//	default:
//		break;
//	}
//}
//
//void convertToPostfix(string& input, queue<char>& postfixQueue)
//{
//	stack<char> operatorStack;
//	char iter;
//	int i, length = input.length();
//	bool a = true;
//	for (i = 0; i < length; i++)
//	{
//		iter = input[i];
//		if (isdigit(iter) || iter == '-')
//		{
//			a = true;
//
//			if (input[i] == '-' && i == 0)
//			{
//				postfixQueue.push('n');
//				postfixQueue.push(input[i]);
//				i++;
//				a = false;
//			}
//			else if (input[i] == '-' && !isdigit(input[i - 1]) && input[i - 1] != ')')
//			{
//				postfixQueue.push('n');
//				postfixQueue.push(input[i]);
//				i++;
//				a = false;
//			}
//
//			if (isdigit(input[i]) || input[i] =='.')
//			{
//				if (a)
//				{
//					postfixQueue.push('n');
//					a = false;
//				}
//				while (i < input.length() && (isdigit(input[i]) || input[i] == '.'))
//				{
//					postfixQueue.push(input[i]);
//					i++;
//				}
//				i--;
//			}
//			else if (!operatorStack.empty() && priority(operatorStack.top()) >= priority(iter))
//			{
//				while (!operatorStack.empty() && priority(operatorStack.top()) >= priority(iter))
//				{
//					postfixQueue.push(operatorStack.top());
//					operatorStack.pop();
//				}
//				operatorStack.push(iter);
//			}
//			else
//			{
//				operatorStack.push(iter);
//			}
//		}
//		else if (operatorStack.empty() || iter == '(')
//		{
//			operatorStack.push(iter);
//		}
//		else if (iter == ')')
//		{
//			while (operatorStack.top() != '(')
//			{
//				postfixQueue.push(operatorStack.top());
//				operatorStack.pop();
//			}
//			operatorStack.pop();
//		}
//		else if (!operatorStack.empty() && priority(operatorStack.top()) >= priority(iter))
//		{
//			while (!operatorStack.empty() && priority(operatorStack.top()) >= priority(iter))
//			{
//				postfixQueue.push(operatorStack.top());
//				operatorStack.pop();
//			}
//			operatorStack.push(iter);
//		}
//		else
//		{
//			operatorStack.push(iter);
//		}
//
//		print_Debug(operatorStack, postfixQueue);
//	}
//
//	while (!operatorStack.empty())
//	{
//		postfixQueue.push(operatorStack.top());
//		operatorStack.pop();
//		print_Debug(operatorStack, postfixQueue);
//	}
//}
//
//double evaluatePostfix(queue<char>& postfixQueue)
//{
//	stack<double> operandStack;
//	string number = "";
//	char ch;
//	double operand, a, b, result;
//	while (!postfixQueue.empty())
//	{
//		ch = postfixQueue.front();
//		postfixQueue.pop();
//
//		if (ch == 'n')
//		{
//			if (postfixQueue.front() == '-')
//			{
//				number += postfixQueue.front();
//				postfixQueue.pop();
//			}
//			while (!postfixQueue.empty() && (isdigit(postfixQueue.front()) || postfixQueue.front() == '.'))
//			{
//				number += postfixQueue.front();
//				postfixQueue.pop();
//			}
//			operand = stod(number);
//			number = "";
//			operandStack.push(operand);
//		}
//		else
//		{
//			b = operandStack.top();
//			operandStack.pop();
//			a = operandStack.top();
//			operandStack.pop();
//
//			result = calculate(a, b, ch);
//			operandStack.push(result);
//		}
//	}
//	return operandStack.top();
//}
//
//int main()
//{
//	/*
//	����ǥ���-> ����ǥ������� ��ȯ (ť�� ����) -> 
//	ť�� ����ִ� ����ǥ����� �ϳ��� pull �� �� �����ڸ� ���� ��쿡 ���� �� ���ÿ� ����
//
//	/*
//	Q3. ���� ����
//	[ ���� ǥ��� ����� ]
//
//		1. ������ �켱������ ( ) < + - < * /
//		2. ���� ǥ������� �ѱ��ھ� �о���δ�.
//		3. �о���� ���ڰ� �������̸�
//			- ���� ��ȣ �̸� ���ÿ� �߰� ( Operator Stack )
//			- ������ ��ȣ �̸� ���ÿ��� ���� ��ȣ�� ������ ���� �ϳ��� ���� ť�� �Ű��ش�.
//				���� ��ȣ�� ������ �� �� ������.
//			- ������ ��Ģ ������ �� �����ڰ� ���ÿ��� ���� �����ں���
//				�켱 ������ ���ų� ���� ���ȿ��� ��� ť�� �Ű��ش�.
//				�׸��� �ڽ��� ���ÿ� �߰��Ѵ�.
//		4. �о���� ���ڰ� �ǿ������̸� ť�� �ִ´�. ( PostFix Queue )
//
//		2 ~ 4 �� ������ �ݺ��ؼ� ���� ǥ����� �����. ( PostFix Queue )
//
//	[ ��� ���� ]
//		5. ť���� �����͸� �о� �������� �ű��. ( Operand Stack )
//			- ť���� ���� �ϳ��� �д´�.
//			- �ǿ����� �̸� ���ÿ� ����
//			- ������ �̸� ���ÿ��� ���� �� �� ������ �����ڿ� ���� ������ �ϰ�
//				�� ����� �ٽ� ���ÿ� ����
//
//		ť�� ���� ���� ������ 5 �� ������ �ݺ��ؼ� ���� ��� ���� ���Ѵ�.
//	*/
//	queue<char> postfixQueue;
//
//	string filePath = "Calc2.txt";
//	string input;
//
//	ifstream openFile(filePath.data());
//	if (openFile.is_open())
//	{
//		getline(openFile, input);
//		openFile.close();
//	}
//	cout << input << endl;
//
//	convertToPostfix(input, postfixQueue);
//
//	double result = evaluatePostfix(postfixQueue);
//
//	cout << result;
//
//	return 0;
//}