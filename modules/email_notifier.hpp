#ifndef EMAIL_NOTIFIER_HPP
#define EMAIL_NOTIFIER_HPP

#include <string>
bool send_email_alert(const std::string& subject, const std::string& body);

#endif
