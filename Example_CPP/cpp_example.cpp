#include "HTTPRequest.hpp"
#include <string>

class PuzzleSolver {
public:
    bool Solved = false;
    std::string LatestAnswer = "";
    PuzzleSolver(std::string g) : SecretKey(g) {}
    void AddParams(std::string Key, std::string Value)
    {
        Params.append(Key + "=" + Value + "&");
    }

    std::string GetAnswer(std::string CaptchaUID)
    {
        AddParams("Action", "Solve");
        AddParams("Puzzle", CaptchaUID);
        AddParams("Secret", SecretKey);
        AddParams("Format", "txt");
        std::string FullUrl = API + Path + Params;
        http::Request request{ std::string{FullUrl}.c_str()};
        const auto response = request.send("GET");
        std::string captchaAnswer = std::string{ response.body.begin(), response.body.end() };
        Solved = captchaAnswer.find("Failed") == std::string::npos && captchaAnswer.length() > 6 && response.status.code==202;

        return LatestAnswer = (captchaAnswer.length() > 6) ? captchaAnswer.erase(0, 7) : "Failed";

    }
private:
    std::string SecretKey;
    std::string API = "http://api.surferwallet.net/";
    std::string Path = "Captcha?";
    std::string Params = "";
};

int main(void)
{
  std::string SecretCode="";
  auto x = PuzzleSolver(SecretCode);
  x.GetAnswer("Puzzle UID");
  if (x.Solved)
      std::cout << "Answer : " << x.LatestAnswer + "\n";
  else
      std::cout << "Failed\n";
  
  
}
