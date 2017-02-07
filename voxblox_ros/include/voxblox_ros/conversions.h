#ifndef VOXBLOX_ROS_CONVERSIONS_H_
#define VOXBLOX_ROS_CONVERSIONS_H_

#include <algorithm>
#include <std_msgs/ColorRGBA.h>
#include <vector>

#include <voxblox_msgs/Layer.h>
#include <voxblox/core/common.h>
#include <voxblox/mesh/mesh.h>
#include <voxblox/core/layer.h>

namespace voxblox {

inline void colorVoxbloxToMsg(const Color& color,
                              std_msgs::ColorRGBA* color_msg) {
  CHECK_NOTNULL(color_msg);
  color_msg->r = color.r / 255.0;
  color_msg->g = color.g / 255.0;
  color_msg->b = color.b / 255.0;
  color_msg->a = color.a / 255.0;
}

inline void colorMsgToVoxblox(const std_msgs::ColorRGBA& color_msg,
                              Color* color) {
  CHECK_NOTNULL(color);
  color->r = static_cast<uint8_t>(color_msg.r * 255.0);
  color->g = static_cast<uint8_t>(color_msg.g * 255.0);
  color->b = static_cast<uint8_t>(color_msg.b * 255.0);
  color->a = static_cast<uint8_t>(color_msg.a * 255.0);
}

// Declarations
template <typename VoxelType>
void serializeLayerAsMsg(const Layer<VoxelType>& layer,
                         voxblox_msgs::Layer* msg);

// Returns true if could parse the data into the existing layer (all parameters
// are compatible), false otherwise.
template <typename VoxelType>
bool deserializeMsgToLayer(const voxblox_msgs::Layer& msg,
                           Layer<VoxelType>* layer);


}  // namespace voxblox

#endif  // VOXBLOX_ROS_CONVERSIONS_H_

#include "voxblox_ros/conversions_inl.h"