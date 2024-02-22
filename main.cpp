#include<iostream>
#include<glog/logging.h> // Needs define GLOG_USE_GLOG_EXPORT to include correctly
#include<gtest/gtest.h>

#include"main.h"

void InitGoogleLog(char* program_name)
{
    fLB::FLAGS_timestamp_in_logfile_name = false;
    google::SetLogDestination(google::GLOG_INFO, "log");
    google::SetLogFilenameExtension(".txt");
    using namespace std::chrono_literals;
    google::EnableLogCleaner(24h);
    google::InitGoogleLogging(program_name);
}

int main(int argc, char* argv[])
{
    InitGoogleLog(argv[0]);
    LOG(INFO) << "Application started";
    testing::InitGoogleTest(&argc, argv);
    google::ShutdownGoogleLogging();
    return RUN_ALL_TESTS();
}