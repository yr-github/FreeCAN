#ifndef LOGMODULE_H
#define LOGMODULE_H
#include<vector>
#include<string>
typedef struct LogModule
{
public:
    LogModule();
    bool operator==(const LogModule& rLog);
    bool operator!=(const LogModule& rLog);
    bool operator<=(const LogModule& rLog);
    bool operator>=(const LogModule& rLog);
    bool operator<(const LogModule& rLog);
    bool operator>(const LogModule& rLog);

    long long Ltime() const;
    void setLtime(long long newLtime);

    const std::vector<std::string> &VSlogs() const;
    void setVSlogs(const std::vector<std::string> &newVSlogs);

private:
    long long m_Ltime;
    std::vector<std::string> m_VSlogs;
}LogModule;

#endif // LOHMODULE_H
