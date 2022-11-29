#include <iostream>
#include <string>
#include <map>
#include <regex> //regular expressions

using namespace std;

map<string, string> questions_answers = {
    //{phrase, answer}
    {"Hello", "Hello, human!\n"},
    {"How (do you do|are you)?", "I'm functioning within normal parameters\n"},
    {"Exit", "Never wanted to talk with you in the first place\n"},
    {"What are you doing?", "Answeing stupid questions"},
    {"No pain","No gain"},
    {"(What is|Whats|What's) (your )?name", "My name is whyDoYouCare"}
};

//у функции должны быть входные(текст вопроса(string user_text)) и выходные параметры(текст ответа)
//данная наша функция cout ответ на данный текст
//void функция не возвращает никакого результата, просто выводит инфу в консоль

void bot_reply(string user_text) 
{
    //cout << "Can't understand :( \n";

    //найти ответ перебором
    //цикл фор используем когда хотим выполнить действие для всех элементов массива,мапа м тд
    //auto - не указываем тип переменнойб определяется автоматически
    //element - название переменной

    for (auto element : questions_answers) {
        //"." => "a", "$", ",", "." то есть один любимой символ
        // ".*" => сколько угодно символов
        //icase = ignore case (capital letter or small letter)
        regex phrase_search(".*" + element.first + ".*", regex_constants::icase);
        //.*hello.* = "любые символы за которыми следует хелло за которым следует следует любые символы

        //{phrase, answer} = {first, second}
        
        if (regex_match(user_text, phrase_search)) {
            cout << "[bot: ]" << element.second << "\n";
        }
    }
}

int main()
{
    cout << "Wassup\n";

    //Переменная question имеет тип string
    string question;

    while (question != "exit") {
        cout << "[user]: ";
        getline(cin, question); //читает введенные данные в син и помещает в стринг квешн
        bot_reply(question);
    }
    //if (question == "hello") {
      //  cout << "Hello, human!\n";
    //}
    //if (question == "bye") {
      //  cout << "Bye, human!\n";
    //}
}
