
#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

#define INF	999999
#define GRAPH_SIZE	9

#define STRAIGHT 10
#define DIAGONAL 14

#define DIRECTION 8

/*
G : 출발점으로 부터 얼마나 떨어져 있는가 ? 또는 이동에 드는 비용
H : 목적지로 부터 얼마나 떨어져 있는가 ?
F : G + F
*/

struct Point
{
	int x;
	int y;

	Point()
	{
		x = -1;
		y = -1;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator==(const Point& other)
	{
		return this->x == other.x && this->y == other.y;
	}

	bool operator!=(const Point& other)
	{
		return !(*this == other);
	}
};

struct ASNode
{
	bool active;		// 활성화 여부 (탐색된 여부)
	ASNode* connect;	// 이 정점을 탐색한 정점의 주소값
	Point point;		// 현재 좌표

	int G;				// 지금까지 온 거리
	int H;				// 예상 거리(장애물 X)
	int F;				// 예상 최단거리(G + H)

	ASNode(bool active, ASNode* connect, Point point, int G, int H)
	{
		this->active = active;
		this->connect = connect;
		this->point = point;
		this->G = G;
		this->H = H;
		this->F = G + H;
	}
};

// [y][x]
bool graphMap[GRAPH_SIZE][GRAPH_SIZE] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 1, 0, 1, 0,
	0, 1, 0, 0, 0, 1, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 0, 0, 1, 0,
	0, 1, 0, 1, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0
};

int getH(Point start, Point end)
{
	// 대각선으로 최대한 이동 후 남은 직선을 가주면 가장 작은 H

	int xSize = abs(start.x - end.x);	// 가로로 가야하는 횟수
	int ySize = abs(start.y - end.y);	// 세로로 가야하는 횟수

	int straight;						// 직선으로 가야하는 횟수
	int diagonal;						// 대각선으로 가야하는 횟수

	// 가로 횟수가 더 많다면 대각선이동 + 남은 가로횟수
	/*
	ex)
	가로 10칸 차이 세로 5칸 차이

	대각선		5번 이동 후
	남은 가로	5번 이동
	*/

	if (xSize > ySize)
	{
		diagonal = ySize;
		straight = xSize - diagonal;
	}
	else
	{
		diagonal = xSize;
		straight = ySize - diagonal;
	}

	// 직선 값 * 직선으로 가야하는 횟수 + 대각선 값 * 대각선으로 가야하는 횟수
	return (STRAIGHT * straight) + (DIAGONAL * diagonal);
}

// openList (활성화 된 노드 리스트) 중 다음으로 탐색해야할 F 값이 가장 낮은 노드 찾기
list<ASNode>::iterator findMinFNode(list<ASNode>& nodeList)
{
	list<ASNode>::iterator minFIter = nodeList.end();
	int minF = INF;
	int minH = INF;

	for (list<ASNode>::iterator iter = nodeList.begin();
			iter != nodeList.end();
			iter++)
	{
		if (true == iter->active &&				// 활성화 된 리스트 이면서 (openList)
			(iter->F < minF ||					// F 값이 가장 낮은 노드
			iter->F == minF && iter->H < minH))	// F 값이 같다면, H 값이 가장 작은 노드
		{
			minFIter = iter;
			minF = iter->F;
			minH = iter->H;
		}
	}

	return minFIter;
}

// openList 중 좌표에 해당하는 노드 찾기
list<ASNode>::iterator findNode(list<ASNode>& nodeList, Point point)
{
	list<ASNode>::iterator findIter = nodeList.end();

	for (list<ASNode>::iterator iter = nodeList.begin();
		iter != nodeList.end();
		iter++)
	{
		if (iter->point == point)
			findIter = iter;
	}
	return findIter;
}

//									상  하  좌  우 우상 좌상 우하 좌하
const int directionX[DIRECTION] = {  0,  0, -1, +1,  +1,  -1,  +1,  -1 };
const int directionY[DIRECTION] = { +1, -1,  0,  0,  +1,  +1,  -1,  -1 };

// A* 알고리즘
list<Point> astar(bool map[GRAPH_SIZE][GRAPH_SIZE], Point start, Point end)
{
	// 탐색해야 할 노드들을 보관할 자료구조
	list<ASNode> openList;

	// 시작 노드 설정
	ASNode startNode(true, nullptr, start, 0, getH(start, end));
	openList.push_back(startNode);

	while (true)
	{
		// 1. 다음으로 탐색할 노드를 선정
		// 다음으로 탐색할 노드			: F 값이 가장 낮은 노드
		// F 값이 같은 노드끼리 비교	: H 값이 가장 낮은 노드
		list<ASNode>::iterator minFIter = findMinFNode(openList);

		// 2.  더 이상 탐색할 노드가 없는 경우
		// 경로가 없다고 판단하여 종료
		if (minFIter == openList.end())
		{
			break;
		}

		// 3. 다음으로 탐색할 노드가 도착지인 경우
		// 도착했다고 판단하여 경로 return
		if (minFIter != openList.end() && minFIter->point == end)
		{
			ASNode endNode = *minFIter;
			ASNode* pPathNode = &endNode;
			
			// 경로 복사
			list<Point> path;
			while (nullptr != pPathNode)
			{
				path.push_front(pPathNode->point);
				pPathNode = pPathNode->connect;
			}
			return path;
		}

		// 4. AStar 탐색 진행
		// 상 하 좌 우 대각선
		for (int i = 0; i < DIRECTION; i++)
		{
			int x = minFIter->point.x + directionX[i];
			int y = minFIter->point.y + directionY[i];

			list<ASNode>::iterator openIter = findNode(openList, Point(x, y));

			// 4 - 0. 탐색하면 안되는 경우
			// 맵을 벗어났을 경우
			if (x < 0 || x >= GRAPH_SIZE || y < 0 || y >= GRAPH_SIZE)
				continue;
			// 벽일 경우
			else if (false == graphMap[y][x])
				continue;
			// 이미 탐색된 노드일 경우
			else if (openIter != openList.end() && false == openIter->active)
				continue;

			// 노드의 F, G, H 값
			int G;
			if (minFIter->point.x == x || minFIter->point.y == y)
				G = minFIter->G + STRAIGHT;
			else
				G = minFIter->G + DIAGONAL;
			int H = getH(Point(x, y), end);
			int F = G + H;

			// 4 - 1. openList 에 이미 해당 노드가 있는 경우
			// F 값이 작으면 덮어씌우기, F 값이 같고 H 값이 작으면 덮어씌우기
			if (openIter != openList.end() &&	// 탐색하려고 했던 노드가 openList 에 있었을 경우
				openIter->F > F)				// 이전의 F 값이 새로운 F 보다 큰 경우
			{
				openIter->F = F;
				openIter->G = G;
				openIter->H = H;
				openIter->connect = &(*minFIter);
			}

			// 4 - 2. openList 에 해당 노드가 없는 경우
			// openList 에 해당 노드를 추가
			else if (openIter == openList.end())
			{
				openList.push_back(ASNode(true, &(*minFIter), Point(x, y), G, H));
			}
		}
		// 5. 탐색을 완료한 노드는 비 활성화
		minFIter->active = false;
	}

	// 경로가 없는 경우 비어있는 경로를 return
	return list<Point>();
}
void printMap(const bool graph[GRAPH_SIZE][GRAPH_SIZE])
{
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void printPathMap(const bool graph[GRAPH_SIZE][GRAPH_SIZE], list<Point> path)
{
	char pathMap[GRAPH_SIZE][GRAPH_SIZE];
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			if (graph[i][j] == 0)
				pathMap[i][j] = '#';
			else if (graph[i][j] == 1)
				pathMap[i][j] = ' ';
		}
	}

	for (list<Point>::iterator iter = path.begin(); iter != path.end(); iter++)
	{
		pathMap[iter->y][iter->x] = '*';
	}
	Point start = path.front();
	Point end = path.back();
	pathMap[start.y][start.x] = 'S';
	pathMap[end.y][end.x] = 'E';

	for (int i = 0; i < GRAPH_SIZE + 2; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		cout << "#";
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			cout << pathMap[i][j];
		}
		cout << "#" << endl;
	}
	for (int i = 0; i < GRAPH_SIZE + 2; i++)
		cout << "#";
	cout << endl;
}

int main()
{

	/*
	1. 시작 노드 설정
	2. 오픈 리스트(탐색 대상 노드)와 클로즈 리스트(탐색이 종료된 노드)를 초기화합니다.
	3. 시작 노드를 오픈 리스트에 추가합니다.
	4. 오픈 리스트에서 휴리스틱 함수 값이 가장 작은 노드를 선택합니다.
	5. 선택된 노드가 목표 노드와 일치하면, 탐색을 종료하고 경로를 반환합니다.
	6. 선택된 노드가 목표 노드와 일치하지 않으면, 해당 노드를 오픈 리스트에서 제거하고 클로즈 리스트에 추가합니다.
	7. 선택된 노드와 연결된 인접 노드들을 검색하고, 각 노드에 대한 휴리스틱 함수 값을 계산합니다.
	8. 각 인접 노드를 오픈 리스트에 추가합니다 (이미 오픈 리스트에 있는 경우, 더 나은 경로를 찾으면 경로를 갱신합니다).
	9. 오픈 리스트에 노드가 없을 때 까지 4-8단계를 반복합니다.
	*/

	list<Point> path = astar(graphMap, Point(1, 1), Point(7,7));

	if (path.size() == 0)
		cout << "경로를 찾지 못했습니다." << endl;
	else
		printPathMap(graphMap, path);

	return 0;
}