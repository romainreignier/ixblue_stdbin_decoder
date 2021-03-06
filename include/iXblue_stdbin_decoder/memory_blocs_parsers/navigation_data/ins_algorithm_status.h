#pragma once

#include "iXblue_stdbin_decoder/data_models/navigation_data/ins_algorithm_status.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class INSAlgorithmStatus : public MemoryBlockParser
{
public:
    INSAlgorithmStatus() : MemoryBlockParser(15, 16) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::INSAlgorithmStatus res;
        buffer >> res.status1 >> res.status2 >> res.status3 >> res.status4;
        outBinaryNav.insAlgorithmStatus = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder