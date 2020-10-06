#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1


int FactorialByRecursion::CalculateFactorial(int num) {

	if (num <= 1)
	{
		return 1;
	}

	else 
	{
		return num * CalculateFactorial(num - 1);  
	}
}


int FactorialByStack::CalculateFactorial(int num) {

	int answer = 1;

	if (num <= 1) { return 1; }

	while (num > 1) {
		s.push(num);
		num--;
	}
	while (!s.empty()) {
		answer = answer * s.top();
		s.pop();
	}
	return answer;
}


// Palindrome
PalindromeRecursion::PalindromeRecursion(std::string str)
{
	m_str = str;
}

PalindromeRecursion::~PalindromeRecursion() {}

bool PalindromeRecursion::CheckIfPalindrome(std::string str) {
	std::string palString = getString();
	int len = str.length();

	// Check if empty and master isn't
	if (str.empty() && !palString.empty())
		return true;

	else if (palString.empty()) // check if master is empty str
		return false;

	else if (len % 2 > 0 && len == str.length()) // is first loop
		str.erase(str.begin() + (len/2));

	// Check if first and last are same
	if (str.front() != str.back())
		return false;

	// Remove first and last 
	str.erase(str.begin() + 0);
	str.pop_back();
	
	if (CheckIfPalindrome(str))
	{
		return true;
	}

	return false;
}

bool PalindromeRecursion::CheckIfPalindromeTest() {
	std::string palString = getString();
	int len = palString.length();

	if (palString.empty()) 
	{
		return false;
	}


	std::string tmp = "";
	for (int i=len-1; i>=0; i--)
	{
		tmp += palString[i];
	}

	return (tmp.compare(palString) == 0);
	

	/*
	int i, j;
	for (i=0, j=len-1; i<=(len/2)-1, j>=(len/2)-1; i++, j--)
	{
		if (palString[i] != palString[j])
		{
			return false;
		}
	}
	*/
	return true;
}


void PalindromeRecursion::setString(std::string str) { m_str = str; }
std::string PalindromeRecursion::getString() { return m_str; }

PalindromeStack::PalindromeStack(std::string str)
{
	m_len = str.length();
	for (char &c : str)
	{
		m_stack.push(c);
	}
}

PalindromeStack::~PalindromeStack() {}

bool PalindromeStack::CheckIfPalindrome()
{
	std::stack<char> stack_1 = getStack();
	std::stack<char> stack_2 = getStack();

	int len = getLen();
	
	if (len == 0)
		return false;
	
	std::stack<char> tmp_stack;
	for (int i=0; i<(len/2); i++)
	{
		stack_1.pop();	
	}
	
	for (int i=0; i<len; i++)
	{
		tmp_stack.push(stack_2.top());
		stack_2.pop();
	}

	for (int i=0; i<(len/2); i++)
	{
		tmp_stack.pop();
	}

	for (int i=0; i<(len/2); i++)
	{
		if (stack_1.top() != tmp_stack.top())
			return false;
	
		stack_1.pop();
		tmp_stack.pop();
	}

	return true;
}


std::stack <char> PalindromeStack::getStack() { return m_stack; }
int PalindromeStack::getLen() { return m_len; }


QueenPosition::QueenPosition(int r, int c){ row = r; col = c;}

int QueenPosition::getRow() { return row; }

int QueenPosition::getCol() { return col; }

std::stack<QueenPosition*> *ChessBoard::getStack() { return m_stack; }

int ChessBoard::getFilled() { return m_filled; }

void ChessBoard::setFilled(int filled) { m_filled = filled; }

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	bool done = false;
	std::stack<QueenPosition*> *stack = chessBoard.getStack();
	int b_row = 0;
	int failed = false;

	while(!done)
	{
		// for loop rows
		failed = true;
		for (int row=b_row; row<8; row++)
		{
			// if safe 
			if (CheckSafeQueens(chessBoard, row, col))
			{
				QueenPosition *qp = new QueenPosition(row, col);
				stack->push(qp);
				// update cols
				col++;
				failed = false;
				break;
			}
		}

		// couldn't place queen
		if (stack->size() == 8)
		{
			// won
			done = true;
		}
		else if (failed)
		{
			b_row = stack->top()->getRow() + 1;
			stack->pop();
			col--;
		}
		else
		{
			// could place queen
			b_row = 0;
			continue;
		}

	}
	return true;

	/*
	// Row
	for (int row = 0; row < 8; row++) {

		// Check if safe to place queen
		if (CheckSafeQueens(chessBoard, row, col)) {
			//m_board[row][col] = 1; // Place a queen
			QueenPosition *qp = new QueenPosition(row, col);
			stack->push(qp);

			// Recurssion, with next col
			if (Solve(chessBoard, col+1))
				return true; // Goes until game won

			// Queen is removed 
			// m_board[row][col] = 0;
			stack->pop(); // Back Track

		}
	}

	// Not possible to win
	return false;	
*/
}




bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) 
{
	int i, j; 
	int count = 0;
	std::stack<QueenPosition*> *stack = getStack();
	std::stack<QueenPosition*> cpy = *stack;
	int size = stack->size(); 
 
    /* Check this row on left side */
	cpy = *stack;
	count = 0;
	while (count < size)
	{
		for (i = 0; i <= col; i++) 
		{
			if (cpy.empty())
				continue;

			else if ( (cpy.top()->getCol() == i) &&
				(cpy.top()->getRow() == row) )
			{
				return false;
			}

			/*
			if (chessBoard->m_board[row][i])
				return false; 
			*/
		}
		if (cpy.empty())
			break;
		count++;
		cpy.pop();
	}

    /* Check upper diagonal on left side */
	cpy = *stack;
	count = 0;
	while (count < size)
	{
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		{
			if (cpy.empty())
				continue;
			
			if ( (cpy.top()->getCol() == j) &&
				(cpy.top()->getRow() == i) )
			{
				return false;
			}

			/*if (chessBoard->m_board[i][j]) 
			{
				return false; 
			}
			*/
		}
		if (cpy.empty())
			break;
		count++;
		cpy.pop();
	}	

    /* Check lower diagonal on left side */
	cpy = *stack;
	count = 0;
	while (count < size)
	{
		for (i = row, j = col; j >= 0 && i < 8; i++, j--)
		{
			if (cpy.empty())
				continue;

			if ( (cpy.top()->getCol() == j) &&
				(cpy.top()->getRow() == i) )
			{
				return false;
			}

			/*if (chessBoard->m_board[i][j]) 
			{
				return false; 
			}
			*/
		}
		if (cpy.empty())
			break;
		count++;
		cpy.pop();
	}
	
	return true; 

    // TODO
	
}


string ChessBoard::ToString() {

	string answer = "";
	std::stack<QueenPosition*> *stack = getStack();
	int temp = 0;
	for (int i = 7; i >= 0; i--) {
		for (int j = 7; j >= 0; j--) {
			temp = ( (stack->top()->getCol() == i) &&
					(stack->top()->getRow() == j) ) ? 1 : 0;
			
			if (temp)
				stack->pop();
			
			//int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer += str;
		}
		answer += "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.


	std::string retVal = "";
	MyFakeClass* resourceThatNeedsToBeCleanedup = nullptr;

	resourceThatNeedsToBeCleanedup = new MyFakeClass();

	try{
		SimpleExceptionMethod(i);
	} catch (MyException1 &e) {
		retVal = "I got Exception 1";
	} catch (MyException2 &e) {
		retVal = "I got Exception 2";
	} catch (MyException3 &e) {
		retVal = "I got Exception 3";
	}

	if (retVal.empty())
		retVal = "I did not get an Exception";

	delete resourceThatNeedsToBeCleanedup;

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();

	}
	else if (i == 3)
	{
        // TODO uncomment line below, as you need to have all three exceptions working here
		throw MyException3();
	}
	else
	{
		retVal = 20;
	}

	return;

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "MyException1";
}
char const* MyException2::what() const throw() {
	return "MyException2";
}
char const* MyException3::what() const throw() {
	return "MyException3";
}


// TODO make a MyException3::what
