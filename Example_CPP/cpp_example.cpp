#include "HTTPRequest.hpp"

std::string GetCaptcha(std::string captchaid)
{
  http::Request request{"http://api.surferstealer.com/captcha/index?CaptchaID"+captchaid};
  const auto response = request.send("GET");
  std::string captchaAnswer = std::string{response.body.begin(), response.body.end()};
  if (captchaAnswer.find("Failed") != std::string::npos) 
      std::cout << "Captcha Failed.!" << '\n';
  else if (captchaAnswer.find("Answer|") != std::string::npos) 
  {
        std::cout << "Captcha Success.!" << '\n';
        std::cout << captchaAnswer<< '\n';
        return captchaAnswer;
  }
    return "Fail";
}
