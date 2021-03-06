#pragma once

#include "iXblue_stdbin_decoder/data_models/navigation_data/rotation_rate_vessel_frame.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class RotationRateVesselFrame : public MemoryBlockParser
{
public:
    RotationRateVesselFrame() : MemoryBlockParser(5, 12) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::RotationRateVesselFrame res;
        buffer >> res.xv1_degsec >> res.xv2_degsec >> res.xv3_degsec;
        outBinaryNav.rotationRateVesselFrame = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder