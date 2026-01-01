#include <gtest/gtest.h>
#include "log/log.h"


TEST(log, init)
{
    
    EXPECT_EQ(NULL, olog_init(OlogLevel::DEBUG, ""));

}

TEST(log, olog)
{
    Olog *log = olog_init(OlogLevel::DEBUG, "./a.txt");


    olog(log, OlogLevel::ERROR, "我是傻逼1111111111111111111111111111111111111111111122324343454656565sfgsafdsafdsf方法大撒范德萨范德萨范德萨范德萨飞洒分父节点拉开飞机离开而urqlfaajffjklsajflk;aiejreijeqwlj;r分离看电视剧abcds");
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}