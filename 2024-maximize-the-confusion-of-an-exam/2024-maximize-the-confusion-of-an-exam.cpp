class Solution
{
    public:
        int Max_steps(string answers, int k, char val)
        {
            int n = answers.size() ;
            int i = 0;
            int j = 0;
            int no_of_val = 0;
            int finalVal = 0;
            while (j < n)
            {
                if (answers[j] == val)
                {
                    no_of_val++;
                }
                while (no_of_val > k && i < n)
                {
                    if (answers[i] == val)
                    {
                        no_of_val--;
                    }
                    i++;
                }

                finalVal = max(finalVal, j - i + 1);
                j++;
            }
           	// finalVal=max(finalVal,finalVal+(no_of_val-k));
           	// finalVal+=(no_of_val-k);
           	// cout<<val<<" "<<finalVal<<endl;
           	// cout<<no_of_val;
            return finalVal;
        }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(Max_steps(answerKey, k, 'T'), Max_steps(answerKey, k, 'F'));
    }
};