#pragma once

#include "iXblue_stdbin_decoder/data_models/external_data/vtg.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class Vtg1 : public MemoryBlockParser
{
public:
    Vtg1() : MemoryBlockParser(25, 17) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::Vtg res;
        buffer >> res.validityTime_100us >> res.vtg_id >> res.true_course_deg >>
            res.magnetic_course_deg >> res.speed_over_ground_ms;
        outBinaryNav.vtg1 = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder