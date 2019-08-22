#include <utility.hpp>

side_type SIDE_DEFAULT = 0;
id_type ID_DEFAULT = LLONG_MAX;
price_type PRICE_DEFAULT = -1;
size_type SIZE_DEFAULT = -1;

std::string getFileName(const std::string& path) {

   char sep = '/';

#ifdef _WIN32
   sep = '\\';
#endif

   size_t i = path.rfind(sep, path.length());
   if (i != std::string::npos) {
      return(path.substr(i+1, path.length() - i));
   }

   return("");
}

uint16_t bswap_16(uint16_t value){
    return static_cast<uint16_t>(((value) & 0xff) << 8 | ((value) >> 8));
}

uint32_t bswap_32(uint32_t value){
    return ((static_cast<uint32_t>(bswap_16(static_cast<uint16_t>((value) & 0xffff))) << 16) |
    static_cast<uint32_t>(bswap_16(static_cast<uint16_t>((value) >> 16))));
}

uint64_t bswap_64(uint64_t value){
    return ((static_cast<uint64_t>(bswap_32(static_cast<uint32_t>((value) & 0xffffffff))) << 32) |
    static_cast<uint64_t>(bswap_32(static_cast<uint32_t>((value) >> 32))));
}

uint16_t parse_uint16(char * a){
    return bswap_16(*(reinterpret_cast<uint16_t *>(a)));
    // return ntohs(*(reinterpret_cast<uint16_t *>(a)));
}

uint32_t parse_uint32(char * a){
    return bswap_32(*(reinterpret_cast<uint32_t *>(a)));
    // return ntohl(*(reinterpret_cast<uint32_t *>(a)));
}

uint64_t parse_uint64(char * a){
    return bswap_64(*(reinterpret_cast<uint64_t *>(a)));
    // return ntohl(*(reinterpret_cast<uint64_t *>(a)));
}

uint64_t parse_ts(char * a){
    return (((static_cast<uint64_t>(bswap_16(*(reinterpret_cast<uint16_t *>(a))))) << 32) |
    static_cast<uint64_t>(bswap_32(*(reinterpret_cast<uint32_t *>(a+2)))));
}
