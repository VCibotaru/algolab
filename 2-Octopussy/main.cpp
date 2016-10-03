#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Ball {
  int time;
  int index;
  bool dependent;
  int first_parent;
  int second_parent;
  Ball(){};
  Ball(int t, int i, int n): time(t), index(i) {
    dependent = (i <= ((n - 3) / 2));
    if (dependent) {
      first_parent = 2*i + 1;
      second_parent = 2*i + 2;
    } else {
      first_parent = second_parent = -1;
    }
  }
};

bool ballComparator(const Ball &a, const Ball &b) {
  if (a.time != b.time) {
    return a.time < b.time;
  }
  // first disarm the independent balls
  return b.dependent;
}

bool disarmBall(Ball &ball, int &time, std::vector<bool> &ball_disarmed) {
  /* std::cout << "trying ball: " << ball.index << "\n"; */
  if (ball_disarmed[ball.index]) {
    return true;
  }
  if (time >= ball.time) {
    return false;
  }
  ball_disarmed[ball.index] = true;
  ++time;
  return true;
}

std::string doTest() {
  int n, i, t;
  std::cin >> n;
  std::vector<Ball> balls(n);
  for (i = 0 ; i < n ; ++i) {
    std::cin >> t;
    balls[i] = Ball(t, i, n);
  }
  std::sort(balls.begin(), balls.end(), ballComparator);
  std::vector<bool> ball_disarmed(n, false);

  // ball_index[old_ball_index] = new_ball_index
  std::vector<int> ball_index(n);
  for (i = 0 ; i < n ; ++i) {
    ball_index[balls[i].index] = i;
  }

  int time = 0;
  for (i = 0 ; i < n ; ++i) {
    Ball &cur_ball = balls[i];
    /* std::cout << "ball number " << i << " is: " << cur_ball.index << "\n"; */ 
    if (cur_ball.dependent) {
      Ball &first_parent = balls[ball_index[cur_ball.first_parent]];
      Ball &second_parent = balls[ball_index[cur_ball.second_parent]];
      bool flag = true;
      if (first_parent.time < second_parent.time) {
        flag = disarmBall(first_parent, time, ball_disarmed);
        flag = flag && disarmBall(second_parent, time, ball_disarmed);
      }
      else {
        flag = disarmBall(second_parent, time, ball_disarmed);
        flag = flag && disarmBall(first_parent, time, ball_disarmed);
      }
      flag = flag && disarmBall(cur_ball, time, ball_disarmed);
      if (!flag) {
        return "no";
      }
    }
    else {
      if (!disarmBall(cur_ball, time, ball_disarmed)) {
        return "no";
      }
    }
  }
  return "yes";
}

int main() {
  /* std::ios_base::sync_with_stdio(false); */
  unsigned test_count;
  std::cin >> test_count;
  for (unsigned i = 0 ; i < test_count ; ++i) {
    std::cout << doTest() << "\n";
  }
  return 0;
}
