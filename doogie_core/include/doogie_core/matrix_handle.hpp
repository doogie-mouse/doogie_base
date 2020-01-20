#ifndef DOOGIE_CORE_MATRIX_HANDLE_HPP_
#define DOOGIE_CORE_MATRIX_HANDLE_HPP_

#include <ros/ros.h>
#include "doogie_msgs/MazeCell.h"
#include "doogie_msgs/MazeCellMultiArray.h"
#include "doogie_msgs/DoogiePosition.h"

#include <string>

namespace doogie_core{
typedef struct LocalCell{
  bool front_wall;
  bool back_wall;
  bool right_wall;
  bool left_wall;
}LocalCell;

class MatrixHandle {
 public:
  MatrixHandle();
  void initMatrix(int i_size, int j_size, std::string i_label, std::string j_label, int fill = 0, int offset = 0);
  doogie_msgs::MazeCell getMatrixElement(doogie_msgs::MazeCellMultiArray matrix, int i, int j);
  void setMatrixElement(doogie_msgs::MazeCellMultiArray matrix, int i, int j, bool north_element,
                        bool south_element, bool east_element, bool west_element, bool visited);
  LocalCell GlobalToLocal(doogie_msgs::DoogiePosition);

 private:
  doogie_msgs::MazeCellMultiArray mat;
};

}

#endif  // DOOGIE_CORE_MATRIX_HANDLE_HPP_