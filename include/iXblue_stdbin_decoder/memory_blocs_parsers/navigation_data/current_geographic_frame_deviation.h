#pragma once

#include "iXblue_stdbin_decoder/data_models/navigation_data/current_geographic_frame_deviation.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class CurrentGeographicFrameDeviation : public MemoryBlockParser
{
public:
    CurrentGeographicFrameDeviation() : MemoryBlockParser(12, 8) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::CurrentGeographicFrameDeviation res;
        buffer >> res.north_stddev_msec >> res.east_stddev_msec;
        outBinaryNav.currentGeographicFrameDeviation = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder