#pragma once

#include "iXblue_stdbin_decoder/data_models/extended_navigation_data/rotation_acceleration_vessel_frame_deviation.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class RotationAccelerationVesselFrameDeviation : public MemoryBlockParser
{
public:
    RotationAccelerationVesselFrameDeviation() : MemoryBlockParser(1, 12) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::RotationAccelerationVesselFrameDeviation res;
        buffer >> res.xv1_stddev_degsec2 >> res.xv2_stddev_degsec2 >>
            res.xv3_stddev_degsec2;
        outBinaryNav.rotationAccelerationVesselFrameDeviation = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder