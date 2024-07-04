#include <bits/stdc++.h>
using namespace std;
#define WA(prf)                                                                                              \
    if (sure_s != unsure_s)                                                                                  \
    {                                                                                                        \
        cout << "\033[1;31mWrong Answer on test case " << i << " On Token Number: " << token_number << endl; \
        cout << "Expeceted: " << sure_s << " Found: " << unsure_s << endl;                                   \
        cout << "\033[0m" << endl;                                                                           \
        err = true;                                                                                          \
        CASE_NUM = i;                                                                                        \
        WRONG_PREFIX = prf;                                                                                  \
        goto print_test_case_sure_unsure;                                                                    \
    }
class Stressor
{
    int tc = 0;

public:
    void run(int tc)
    {
        this->tc = tc;
        generate_tests();
        run_sure_solution();
        run_unsure_solution();
        run_checker();
    }

    virtual void generate_test(ofstream &fout) = 0;

    virtual void unsure_solution(ifstream &fin, ofstream &fout) = 0;

    virtual void sure_solution(ifstream &fin, ofstream &fout) = 0;

    void cleanup()
    {
        system("rm testcases/*");
        system("rm sure_out/*");
        system("rm unsure_out/*");
    }

private:
    void generate_tests()
    {
        // clear all files in testcases folder
        system("rm testcases/*");

        for (int i = 0; i < this->tc; i++)
        {
            ofstream fout("testcases/" + to_string(i) + ".in");

            generate_test(fout);

            fout.close();
        }
    }
    void run_sure_solution()
    {
        // clear all files in sure_out folder
        system("rm sure_out/*");

        for (int i = 0; i < this->tc; i++)
        {
            ifstream fin("testcases/" + to_string(i) + ".in");
            ofstream fout("sure_out/" + to_string(i) + ".out");

            // run sure solution here
            sure_solution(fin, fout);

            fin.close();
            fout.close();
        }

        int i = 0;
        while (true)
        {
            // check if the file exists
            ifstream fin("custom/" + to_string(i) + ".in");
            if (!fin)
            {
                break;
            }

            ofstream fout("sure_out/custom" + to_string(i) + ".out");

            // run sure solution here
            sure_solution(fin, fout);

            i++;

            fin.close();
            fout.close();
        }
    }
    void run_unsure_solution()
    {
        // clear all files in unsure_out folder
        system("rm unsure_out/*");

        for (int i = 0; i < this->tc; i++)
        {
            ifstream fin("testcases/" + to_string(i) + ".in");
            ofstream fout("unsure_out/" + to_string(i) + ".out");

            // run unsure solution here
            unsure_solution(fin, fout);

            fin.close();
            fout.close();
        }

        int i = 0;
        while (true)
        {
            // check if the file exists
            ifstream fin("custom/" + to_string(i) + ".in");
            if (!fin)
            {
                break;
            }

            ofstream fout("unsure_out/custom" + to_string(i) + ".out");

            // run unsure solution here
            unsure_solution(fin, fout);

            i++;

            fin.close();
            fout.close();
        }
    }
    void run_checker()
    {

        // system("clear");

        int CASE_NUM = -1;
        string WRONG_PREFIX = "";
        for (int i = 0; i < this->tc; i++)
        {
            ifstream fin("testcases/" + to_string(i) + ".in");
            ifstream sure("sure_out/" + to_string(i) + ".out");
            ifstream unsure("unsure_out/" + to_string(i) + ".out");
            // run checker here
            string sure_s, unsure_s;
            int token_number = 0;
            bool err = false;
            while (sure >> sure_s && unsure >> unsure_s)
            {
                ++token_number;
                WA("");
            }

            cout << "\033[1;32mAccepted on test case " << i << "\033[0m" << endl;

            fin.close();
            sure.close();
            unsure.close();
        }

        for (int i = 0;; i++)
        {
            // check if the file exists
            ifstream fin("custom/" + to_string(i) + ".in");
            if (!fin)
            {
                break;
            }

            ifstream sure("sure_out/custom" + to_string(i) + ".out");
            ifstream unsure("unsure_out/custom" + to_string(i) + ".out");
            // run checker here
            string sure_s, unsure_s;
            int token_number = 0;
            bool err = false;
            while (sure >> sure_s && unsure >> unsure_s)
            {
                ++token_number;
                WA("custom");
            }

            cout << "\033[1;32mAccepted on custom test case " << i << "\033[0m" << endl;

            fin.close();
            sure.close();
            unsure.close();
            i++;
        }
        cout << "\033[1;32mAccepted all case"
             << "\033[0m" << endl;
        return;
    print_test_case_sure_unsure:
        int i = CASE_NUM;

        cout << "\033[1;33mTest Case " << i << ":\033[0m" << endl;
        cout << "\033[1;34mSure Output:\033[0m ";
        ifstream sure("sure_out/" + WRONG_PREFIX + to_string(i) + ".out");
        string sure_s;
        while (sure >> sure_s)
        {
            cout << sure_s << " ";
        }
        cout << endl;
        cout << "\033[1;34mUnsure Output:\033[0m ";
        ifstream unsure("unsure_out/" + WRONG_PREFIX + to_string(i) + ".out");
        string unsure_s;
        while (unsure >> unsure_s)
        {
            cout << unsure_s << " ";
        }
        cout << endl;
        cout << "\033[1;34mTest Case:\033[0m" << endl;

        ifstream fin;

        if (WRONG_PREFIX == "custom")
        {
            fin.open("custom/" + to_string(i) + ".in");
        }
        else
        {
            fin.open("testcases/" + to_string(i) + ".in");
        }

        // print it line by line
        while (getline(fin, sure_s))
        {
            cout << sure_s << endl;
        }

        cout << "\033[1;34mEnd Test Case\033[0m" << endl;
        cout << endl;
    }
};
