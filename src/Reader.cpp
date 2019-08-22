#include <Reader.hpp>

Reader::Reader(const std::string &_fileName, const std::string &_stock):
    fileName(_fileName), stock(_stock){
        file.open(fileName);
        if(!file.is_open()){
            std::cerr << "The input file: " << fileName << " cannot be open! " << std::endl;
            }
        else{
            std::cout << "Opened " << fileName << " to read ITCH 5.0. messages." << std::endl;
            validFile = 1;
        }
        start = time(0);
    }

Reader::Reader(const std::string &_stock): stock(_stock){}

void Reader::printProgress(void){
    count ++;
    if(count % 10000000 == 0){
        std::cout << "Processed " << count/1000000 << "Mio messages. " << int(count/difftime(time(0), start)/10000)/100. << " Mio messages per sec." << std::endl;
    }
}

void Reader::readBytesIntoMessage(const long &size){
    file.read(message, size);
}

void Reader::skipBytes(const long &size){
    file.ignore(size);
}

char Reader::getKey(void){
    char key;
    file.get(key);
    return key;
}

Message Reader::createMessage(void){
    printProgress();
    Message msg;
    skipBytes(2);
    char key = getKey();
    // char str[100] = {0};
    char ticker[9];
    strncpy(ticker, stock.c_str(), 8); ticker[8] = 0;
    switch(key){
        uint64_t timeStamp, orderId, oldOrderId, newOrderId;
        uint32_t size, price, execSize, cancSize, newSize, newPrice;
        // uint16_t locateCode, trackingNumb;
        // uint32_t upperAuctionCollarPrice, lowerAuctionCollarPrice, fairPrice, nearPrice, referencePrice, numberOfSharesInALot, ETPLevarage, timeIPO, priceIPO, auctionCollarPrice;
        // uint64_t level1, level2, level3, matchNumber, size64, pairedShares, imbalanceShares, matchId;
        char direction;
        // char auctionCollarExtension, eventCode, marketCategory, financialStatus, roundLotsOnly, issueClassification, subType[3], autenticity, shortIndicator, ipoFlag, indicatorLULD, flagETP, inverseETPFlag, tradingState, reserved, reason[5], regSHO, mpidIdentifier[5], primaryMarketMaker, marketMakerMode, makerParticipantState, breachedLevel, qualifierIPO, marketCode, haltAction, mpid[5], printable, crossType, imbalanceDirection, priceVariationIndicator;

        case 'S':
            readBytesIntoMessage(11);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     eventCode = message[10];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%c\n", key, locateCode,trackingNumb,timeStamp,eventCode);
            // }
            break;
        case 'R':
            readBytesIntoMessage(38);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     strncpy(ticker, message+10, 8); ticker[8] = 0;
            //     marketCategory = message[18];
            //     financialStatus = message[19];
            //     numberOfSharesInALot = parse_uint32(message+20);
            //     roundLotsOnly = message[24];
            //     issueClassification = message[25];
            //     strncpy(subType, message+26, 2); subType[2] = 0;
            //     autenticity = message[28];
            //     shortIndicator = message[29];
            //     ipoFlag = message[30];
            //     indicatorLULD = message[31];
            //     flagETP = message[32];
            //     ETPLevarage = parse_uint32(message+33);
            //     inverseETPFlag = message[37];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%s,%c,%c,%" PRIu32 ",%c,%c,%s,%c,%c,%c,%c,%c,%" PRIu32 ",%c\n", key,locateCode,trackingNumb,timeStamp,ticker,marketCategory,financialStatus,numberOfSharesInALot,roundLotsOnly,issueClassification,subType,autenticity,shortIndicator,ipoFlag,indicatorLULD,flagETP,ETPLevarage,inverseETPFlag);
            // }
            break;
        case 'H':
            readBytesIntoMessage(24);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     strncpy(ticker, message+10, 8); ticker[8] = 0;
            //     tradingState = message[18];
            //     reserved = message[19];
            //     strncpy(reason, message+20, 4); reason[4] = 0;
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%s,%c,%c,%s\n",key,locateCode,trackingNumb,timeStamp,ticker,tradingState,reserved,reason);
            // }
            break;
        case 'Y':
            readBytesIntoMessage(19);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     strncpy(ticker, message+10, 8); ticker[8] = 0;
            //     regSHO = message[18];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%s,%c\n",key,locateCode,trackingNumb,timeStamp,ticker,regSHO);
            // }
            break;
        case 'L':
            readBytesIntoMessage(25);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     strncpy(mpidIdentifier, message+10, 4); mpidIdentifier[4] = 0;
            //     strncpy(ticker, message+14, 8); ticker[8] = 0;
            //     primaryMarketMaker = message[22];
            //     marketMakerMode = message[23];
            //     makerParticipantState = message[24];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%s,%s,%c,%c,%c\n",key,locateCode,trackingNumb,timeStamp,mpidIdentifier,ticker,primaryMarketMaker,marketMakerMode,makerParticipantState);
            // }
            break;
        case 'V':
            readBytesIntoMessage(34);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     level1 = parse_uint64(message+10);
            //     level2 = parse_uint64(message+18);
            //     level3 = parse_uint64(message+26);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ".%08" PRIu64 ",%" PRIu64 ".%08" PRIu64 ",%" PRIu64 ".%08" PRIu64 "\n",key,locateCode,trackingNumb,timeStamp,level1/100000000,level1%100000000,level2/100000000,level2%100000000,level3/100000000,level3%100000000);
            // }
            break;
        case 'W':
            readBytesIntoMessage(11);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     breachedLevel = message[10];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%c\n",
            //         key,locateCode,trackingNumb,timeStamp,breachedLevel);
            // }
            break;
        case 'K':
            readBytesIntoMessage(27);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     strncpy(ticker, message+10, 8); ticker[8] = 0;
            //     timeIPO = parse_uint32(message+18);
            //     qualifierIPO = message[22];
            //     priceIPO = parse_uint32(message+23);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%s,%" PRIu32 ",%c,%" PRIu32 ".%04" PRIu32 "\n",
            //         key,locateCode,trackingNumb,timeStamp,ticker,timeIPO,qualifierIPO,
            //         priceIPO/10000,priceIPO%10000);
            // }
            break;
        case 'J':
            readBytesIntoMessage(34);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     strncpy(ticker, message+10, 8); ticker[8] = 0;
            //     auctionCollarPrice = parse_uint32(message+18);
            //     upperAuctionCollarPrice = parse_uint32(message+22);
            //     lowerAuctionCollarPrice = parse_uint32(message+26);
            //     auctionCollarExtension = message[30];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%s,%" PRIu32 ".%04" PRIu32 ",%" PRIu32 ".%04" PRIu32 ",%" PRIu32 ".%04" PRIu32 ",%c\n",
            //         key,locateCode,trackingNumb,timeStamp,ticker,
            //         auctionCollarPrice/10000,auctionCollarPrice%10000,
            //         upperAuctionCollarPrice/10000,upperAuctionCollarPrice%10000,
            //         lowerAuctionCollarPrice/10000,lowerAuctionCollarPrice%10000,
            //         auctionCollarExtension);
            // }
            break;
        case 'h':
            readBytesIntoMessage(20);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     strncpy(ticker, message+10, 8); ticker[8] = 0;
            //     marketCode = message[18];
            //     haltAction = message[19];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%s,%c,%c\n",
            //         key,locateCode,trackingNumb,timeStamp,ticker,marketCode,haltAction);
            // }
            break;
        case 'A':
            readBytesIntoMessage(35);
            timeStamp = parse_ts(message+4);
            orderId = parse_uint64(message+10);
            direction = message[18];
            size = parse_uint32(message+19);
            strncpy(ticker, message+23, 8); ticker[8] = 0;
            price = parse_uint32(message+31);
            // if(debug){
            //    locateCode = parse_uint16(message);
            //    trackingNumb = parse_uint16(message+2);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%c,%" PRIu32 ",%s,%" PRIu32 ".%04" PRIu32 "\n",
            //         key,locateCode,trackingNumb,timeStamp,orderId,
            //         direction,size,ticker,
            //         price/10000,price%10000);
            // }
            msg.setType(key);
            msg.setTimeStamp(static_cast<time_type>(timeStamp));
            msg.setId(static_cast<id_type>(orderId));
            msg.setSide(static_cast<side_type>(direction == 'S'));
            msg.setRemSize(static_cast<size_type>(size));
            msg.setPrice(static_cast<price_type>(price)/10000);
            break;
        case 'F':
            readBytesIntoMessage(39);
            timeStamp = parse_ts(message+4);
            orderId = parse_uint64(message+10);
            direction = message[18];
            size = parse_uint32(message+19);
            strncpy(ticker, message+23, 8); ticker[8] = 0;
            price = parse_uint32(message+31);
            // if(debug){
            //    locateCode = parse_uint16(message);
            //    trackingNumb = parse_uint16(message+2);
            //     strncpy(mpid, message+35, 4); mpid[4] = 0;
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%c,%" PRIu32 ",%s,%" PRIu32 ".%04" PRIu32 ",%s\n",
            //     key,locateCode,trackingNumb,timeStamp,orderId,
            //     direction,size,ticker,
            //     price/10000,price%10000,mpid);
            // }
            msg.setType(key);
            msg.setTimeStamp(static_cast<time_type>(timeStamp));
            msg.setId(static_cast<id_type>(orderId));
            msg.setSide(static_cast<side_type>(direction == 'S'));
            msg.setRemSize(static_cast<size_type>(size));
            msg.setPrice(static_cast<price_type>(price)/10000);
            break;
        case 'E':
            readBytesIntoMessage(30);
            timeStamp = parse_ts(message+4);
            orderId = parse_uint64(message+10);
            execSize = parse_uint32(message+18);
            // if(debug){
            //    locateCode = parse_uint16(message);
            //    trackingNumb = parse_uint16(message+2);
            //     matchNumber = parse_uint64(message+22);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%" PRIu32 ",%" PRIu64 "\n",
            //     key,locateCode,trackingNumb,timeStamp,orderId,
            //     execSize,matchNumber);
            // }
            msg.setType(key);
            msg.setTimeStamp(static_cast<time_type>(timeStamp));
            msg.setId(static_cast<id_type>(orderId));
            msg.setExecSize(static_cast<size_type>(execSize));
            break;
        case 'C':
            readBytesIntoMessage(35);
            timeStamp = parse_ts(message+4);
            orderId = parse_uint64(message+10);
            execSize = parse_uint32(message+18);
            price = parse_uint32(message+31);
            // if(debug){
            //    locateCode = parse_uint16(message);
            //    trackingNumb = parse_uint16(message+2);
            //     matchNumber = parse_uint64(message+22);
            //     printable = message[30];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%" PRIu32 ",%" PRIu64 ",%c,%" PRIu32 ".%04" PRIu32 "\n",
            //     key,locateCode,trackingNumb,timeStamp,orderId,
            //     execSize,matchNumber,printable,
            //     price/10000,price%10000);
            // }
            msg.setType(key);
            msg.setTimeStamp(static_cast<time_type>(timeStamp));
            msg.setId(static_cast<id_type>(orderId));
            msg.setExecSize(static_cast<size_type>(execSize));
            msg.setPrice(static_cast<price_type>(price)/10000);
            break;
        case 'X':
            readBytesIntoMessage(22);
            timeStamp = parse_ts(message+4);
            orderId = parse_uint64(message+10);
            cancSize = parse_uint32(message+18);
            // if(debug){
            //    locateCode = parse_uint16(message);
            //    trackingNumb = parse_uint16(message+2);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%" PRIu32 "\n",
            //     key,locateCode,trackingNumb,timeStamp,orderId,cancSize);
            // }
            msg.setType(key);
            msg.setTimeStamp(static_cast<time_type>(timeStamp));
            msg.setId(static_cast<id_type>(orderId));
            msg.setCancSize(static_cast<size_type>(cancSize));
            break;
        case 'D':
            readBytesIntoMessage(18);
            timeStamp = parse_ts(message+4);
            orderId = parse_uint64(message+10);
            // if(debug){
            //    locateCode = parse_uint16(message);
            //    trackingNumb = parse_uint16(message+2);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 "\n",
            //     key,locateCode,trackingNumb,timeStamp,orderId);
            // }
            msg.setType(key);
            msg.setTimeStamp(static_cast<time_type>(timeStamp));
            msg.setId(static_cast<id_type>(orderId));
            break;
        case 'U':
            readBytesIntoMessage(34);
            timeStamp = parse_ts(message+4);
            oldOrderId = parse_uint64(message+10);
            newOrderId = parse_uint64(message+18);
            newSize = parse_uint32(message+26);
            newPrice = parse_uint32(message+30);
            // if(debug){
            //    locateCode = parse_uint16(message);
            //    trackingNumb = parse_uint16(message+2);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%" PRIu64 ",%" PRIu32 ",%" PRIu32 ".%04" PRIu32 "\n",
            //     key,locateCode,trackingNumb,timeStamp,oldOrderId,
            //     newOrderId,newSize,newPrice/10000,newPrice%10000);
            // }
            msg.setType(key);
            msg.setTimeStamp(static_cast<time_type>(timeStamp));
            msg.setId(static_cast<id_type>(newOrderId));
            msg.setOldId(static_cast<id_type>(oldOrderId));
            msg.setRemSize(static_cast<size_type>(newSize));
            msg.setPrice(static_cast<price_type>(newPrice)/10000);
            break;
        case 'P':
            readBytesIntoMessage(43);
            timeStamp = parse_ts(message+4);
            orderId = parse_uint64(message+10);
            direction = message[18];
            size = parse_uint32(message+19);
            strncpy(ticker, message+23, 8); ticker[8] = 0;
            price = parse_uint32(message+31);
            // if(debug){
            //    locateCode = parse_uint16(message);
            //    trackingNumb = parse_uint16(message+2);
            //    matchId = parse_uint64(message+35);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%c,%" PRIu32 ",%s,%" PRIu32 ".%04" PRIu32 ",%" PRIu64 "\n",
            //     key,locateCode,trackingNumb,timeStamp,orderId,
            //     direction,size,ticker,price/10000,price%10000,matchId);
            // }
            msg.setType(key);
            msg.setTimeStamp(static_cast<time_type>(timeStamp));
            msg.setId(static_cast<id_type>(orderId));
            msg.setSide(static_cast<side_type>(direction == 'S'));
            msg.setExecSize(static_cast<size_type>(size));
            msg.setPrice(static_cast<price_type>(price)/10000);
            break;
        case 'Q':
            readBytesIntoMessage(39);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     size64 = parse_uint64(message+10);
            //     strncpy(ticker, message+18, 8); ticker[8] = 0;
            //     price = parse_uint32(message+26);
            //     matchId = parse_uint64(message+30);
            //     crossType = message[38];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%s,%" PRIu32 ".%04" PRIu32 ",%" PRIu64 ",%c\n",
            //     key,locateCode,trackingNumb,timeStamp,size64,
            //     ticker,price/10000,price%10000,matchId,crossType);
            // }

            // Check how to use Q.
            break;
        case 'B':
            readBytesIntoMessage(18);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     matchId = parse_uint64(message+10);
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 "\n",
            //     key,locateCode,trackingNumb,timeStamp,matchId);
            // }
            break;
        case 'I':
            readBytesIntoMessage(49);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     pairedShares = parse_uint64(message+10);
            //     imbalanceShares = parse_uint64(message+18);
            //     imbalanceDirection = message[26];
            //     strncpy(ticker, message+27, 8); ticker[8] = 0;
            //     fairPrice = parse_uint32(message+35);
            //     nearPrice = parse_uint32(message+39);
            //     referencePrice = parse_uint32(message+43);
            //     crossType = message[47];
            //     priceVariationIndicator = message[48];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%" PRIu64 ",%" PRIu64 ",%c,%s,%" PRIu32 ".%04" PRIu32 ",%" PRIu32 ".%04" PRIu32 ",%" PRIu32 ".%04" PRIu32 ",%c,%c\n",
            //         key,locateCode,trackingNumb,timeStamp,pairedShares,
            //         imbalanceShares,imbalanceDirection,ticker,
            //         fairPrice/10000,fairPrice%10000,
            //         nearPrice/10000,nearPrice%10000,
            //         referencePrice/10000,referencePrice%10000,
            //         crossType,priceVariationIndicator);
            // }
            break;
        case 'N':
            readBytesIntoMessage(19);
            // if(debug){
            //     locateCode = parse_uint16(message);
            //     trackingNumb = parse_uint16(message+2);
            //     timeStamp = parse_ts(message+4);
            //     strncpy(ticker, message+10, 8); ticker[8] = 0;
            //     interest = message[18];
            //     sprintf(str,"%c,%" PRIu16 ",%" PRIu16 ",%" PRIu64 ",%s,%c\n", key, locateCode,trackingNumb,timeStamp,ticker,interest);
            // }
            break;
        default:
            if(!eof()){
                std::cerr << "Type " << key <<" not found: abort" << std::endl;
                validFile = 0;
            }
            break;
    }
    // if(debug){
    //     parserWriter.writeLine(std::string(str));
    // }
    if(strcmp(ticker,stock.c_str())){
        return Message();
    }
    return msg;
}

bool Reader::eof(void){
    return file.eof();
}

bool Reader::isValid(void) const{
    return validFile;
}

std::string Reader::getFileName(void) const{
    return fileName;
}

std::string Reader::getStock(void) const{
    return stock;
}

void Reader::setMessage(const char* str){
    memcpy(message, str, 64);
}

Reader::~Reader(){
    if (file.is_open()){
        file.close();
        std::cout << "File " << fileName << " has been closed" << std::endl;
        std::cout << "Finished, processed " << count << " messages in " << difftime(time(0),start) << "seconds."  << std::endl;
    }
}
