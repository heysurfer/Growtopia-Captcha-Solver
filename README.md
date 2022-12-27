# Growtopia-Captcha-Solver

## Parse Captcha UID


Varlist

```txt
param 0: onShowCaptcha
param 1: add_puzzle_captcha|0098/captcha/generated/576f9518-615c-4308-8d04-e6fc0c8fb905-PuzzleWithMissingPiece.rttex|0098/captcha/generated/576f9518-615c-4308-8d04-e6fc0c8fb905-TrimmedPuzzlePiece.rttex|ubistatic-a.akamaihd.net|200118|
end_dialog|puzzle_captcha_submit||Submit|
576f9518-615c-4308-8d04-e6fc0c8fb905-PuzzleWithMissingPiece.rttex -> Puzzle UID = 576f9518-615c-4308-8d04-e6fc0c8fb905
Puzzle UID = 576f9518-615c-4308-8d04-e6fc0c8fb905
```

Example Solver For Enet Proxy
<a href="https://github.com/heysurfer/EnetProxy/blob/main/proxy/events.cpp#L14">Events.cpp</a>

if Answer Success Its Will Return Answer|Number<br>
If Answer Fail Its Will Return Answer|Failed<br>

### Api
api.surferwallet.net

### Information
Solve Time 0-1.3 Seconds.<br>

00 - 27 December 

![JGFFzxPRV4oApPquitNo](https://user-images.githubusercontent.com/58826689/209679271-71afb7ae-67aa-4b63-97f4-5681cdb6fe0f.png)



### Price Information

<strong>150 World Lock for Per 500 captchas </strong>

<a href="http://surferwallet.net/SurferShop">Buy</a>


### Example Request
Request Method : GET

Query Params
| Key | Value | Value |
|:-----|:-----------:|:-----------|
| Action | `Solve` | Action Type |
| Format | `txt` | Response Format, default json |
| Secret | `xxxxxxxxx` | Your secret code |
| Puzzle | `07ed133c-ee0e-4fcb-8e76-81dda6aa5333` | Puzzle UID |

```curl "http://api.surferwallet.net/Captcha?Action=Solve&Puzzle=07ed133c-ee0e-4fcb-8e76-81dda6aa5333&Secret=xxxxxxxxx" ```
### Response
```json
{
    "Answer": "Failed",
    "Success": false
}
------------------------
{
    "Answer": "0.59375",
    "Success": true
}
```
Response txt format
```txt
Answer|Failed
------------------------
Answer|0.59375
```

```curl "http://api.surferwallet.net/Captcha?Action=Info&Secret=xxxxxxxxx" ```
### Response
```json
{
    "Remains": 0
}
```

discord heysurfer#0101

![ezgif-4-5977a6b3ba](https://user-images.githubusercontent.com/58826689/190183715-9171acf1-5ced-4df1-aeeb-b6c9d0f7139e.gif)
