#include <iostream>
#include <string>
#include <vector>
class log
{
public:
    enum class lvl 
    {
        INFO,
        WARN,
        ERROR
    };

    log& level(lvl lvl)
    {

        selected_level=lvl;
        return *this;
    }

    log& operator<<(const std::string &msg)
    {
        switch (selected_level) 
        {
            case lvl::INFO:
                info_msg.push_back(msg);
                break;
            case lvl::WARN:
                warn_msg.push_back(msg);
                break;
            case lvl::ERROR:
                error_msg.push_back(msg);
                break;
        }
        return *this;
    }

    void dump()
    {
        for(int iterator=0;iterator<info_msg.size();iterator++)
        {
            std::cout<<"[INFO]: "<<info_msg[iterator]<<"\n";
        }
        for(int iterator=0;iterator<warn_msg.size();iterator++)
        {
            std::cout<<"[WARN]: "<<warn_msg[iterator]<<"\n";
        }
        for(int iterator=0;iterator<error_msg.size();iterator++)
        {
            std::cout<<"[ERROR]: "<<error_msg[iterator]<<"\n";
        }
    }
    void clear()
    {
        info_msg.clear();
        warn_msg.clear();
        error_msg.clear();
    }
private:

    std::vector<std::string> info_msg;
    std::vector<std::string> warn_msg;
    std::vector<std::string> error_msg;
    lvl selected_level;


};

int main()
{
    log logger;
    logger.level(log::lvl::WARN)<<"the file is not closed"<<"the cpu is overloaded";
    logger.level(log::lvl::INFO)<<"the program is running";
    logger.level(log::lvl::ERROR)<<"the program is crashed";
    logger.dump();
    logger.clear();



    return 0;
}