#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <OrderPool.hpp>

struct OrderPool_Test : public testing::Test{
    OrderPool *pool;
    Order *order;
    void SetUp(){
        pool = new OrderPool();
    }
    void TearDown(){
        delete pool;
    }
};

TEST_F(OrderPool_Test, findOrder){
    pool->addToOrderPool(12345,0,1000,99.977);
    ASSERT_EQ(12345, pool->searchOrderPool(12345).getId());
    ASSERT_EQ(0, pool->searchOrderPool(12345).getSide());
    ASSERT_EQ(1000, pool->searchOrderPool(12345).getSize());
    ASSERT_EQ(99.977, pool->searchOrderPool(12345).getPrice());
}

TEST_F(OrderPool_Test, nonExistingOrder){
    pool->addToOrderPool(12345,0,1000,99.977);
    ASSERT_EQ(1, pool->searchOrderPool(1111).isEmpty());
}
