#pragma once

#include "iXblue_stdbin_decoder/data_models/navigation_data/ins_user_status.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class INSUserStatus : public MemoryBlockParser
{
public:
    INSUserStatus() : MemoryBlockParser(17, 4) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::INSUserStatus res;
        buffer >> res.status;
        outBinaryNav.insUserStatus = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder