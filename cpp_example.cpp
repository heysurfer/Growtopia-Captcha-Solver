std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string GetCaptcha(std::string captchlink)
{
  std::string cmd="CaptchaBypasser.exe -captcha "+captchlink;//0098/captcha/generated/a6392818-530d-4d9c-a50a-908b4d6eedff-PuzzleWithMissingPiece.rttex
  std::string captchaAnswer = exec(cmd.c_str());
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

