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
//	중위표기식-> 후위표기식으로 변환 (큐에 저장) -> 
//	큐에 들어있는 후위표기식을 하나씩 pull 한 후 연산자를 만날 경우에 연산 후 스택에 저장
//
//	/*
//	Q3. 스택 계산기
//	[ 후위 표기식 만들기 ]
//
//		1. 연산자 우선순위는 ( ) < + - < * /
//		2. 중위 표기법에서 한글자씩 읽어들인다.
//		3. 읽어들인 글자가 연산자이면
//			- 왼쪽 괄호 이면 스택에 추가 ( Operator Stack )
//			- 오른쪽 괄호 이면 스택에서 왼쪽 괄호를 만날때 까지 하나씩 꺼내 큐로 옮겨준다.
//				왼쪽 괄호와 만나면 둘 다 버린다.
//			- 나머지 사칙 연산은 그 연산자가 스택에서 꺼낸 연산자보다
//				우선 순위가 높거나 같은 동안에는 계속 큐로 옮겨준다.
//				그리고 자신을 스택에 추가한다.
//		4. 읽어들인 글자가 피연산자이면 큐에 넣는다. ( PostFix Queue )
//
//		2 ~ 4 의 과정을 반복해서 후위 표기식을 만든다. ( PostFix Queue )
//
//	[ 계산 과정 ]
//		5. 큐에서 데이터를 읽어 스택으로 옮긴다. ( Operand Stack )
//			- 큐에서 값을 하나씩 읽는다.
//			- 피연산자 이면 스택에 저장
//			- 연산자 이면 스택에서 값을 두 개 꺼내서 연산자에 대한 연산을 하고
//				그 결과를 다시 스택에 저장
//
//		큐에 값이 없을 때까지 5 의 과정을 반복해서 최종 계산 값을 구한다.
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