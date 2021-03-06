#pragma once

#include "iXblue_stdbin_decoder/data_models/external_data/usbl.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class Usbl2 : public MemoryBlockParser
{
public:
    Usbl2() : MemoryBlockParser(7, 49) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::Usbl res;
        buffer >> res.validityTime_100us >> res.usbl_id >> res.beacon_id >>
            res.latitude_deg >> res.longitude_deg >> res.altitude_m >>
            res.north_stddev_m >> res.east_stddev_m >> res.lat_lon_cov_m2 >>
            res.altitude_stddev_m;
        outBinaryNav.usbl2 = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder