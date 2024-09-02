template <typename T, typename X>
struct Binary_Exponentiation
{

    Binary_Exponentiation() = default;
    Binary_Exponentiation(T MOD) : MOD(MOD) {}
    T MOD;

    vector<T> applyPermutation(vector<T> &sequence, vector<T> &permutation)
    {

        vector<T> newSequence(sequence.size());

        for (int i = 0; i < sequence.size(); i++)
        {
            newSequence[i] = sequence[permutation[i]];
        }
        return newSequence;
    }
    vector<T> permute(vector<T> &sequence, vector<T> &permutation, T b)
    {

        while (b > 0)
        {
            if (b & 1)
            {
                sequence = applyPermutation(sequence, permutation);
            }
            permutation = applyPermutation(permutation, permutation);
            b >>= 1;
        }
        return sequence;
    }
};
