#pragma once

#include "iXblue_stdbin_decoder/data_models/extended_navigation_data/raw_rotation_rate_vessel_frame.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class RawRotationRateVesselFrame : public MemoryBlockParser
{
public:
    RawRotationRateVesselFrame() : MemoryBlockParser(2, 12) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::RawRotationRateVesselFrame res;
        buffer >> res.xv1_degsec >> res.xv2_degsec >> res.xv3_degsec;
        outBinaryNav.rawRotationRateVesselFrame = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder