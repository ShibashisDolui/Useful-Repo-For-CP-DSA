#include <bits/stdc++.h>
using namespace std;

class SearchSuggestionSystem
{
private:
    struct TrieNode
    {
        bool isEnd;
        struct TrieNode *child[26];

        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode *trieRoot;

    void insert(string &word)
    {
        TrieNode *temp = trieRoot;

        for (int i = 0; i < (int)word.length(); i++)
        {
            int x = word[i] - 'a';
            if (temp->child[x] == nullptr)
            {
                TrieNode *newNode = new TrieNode;
                temp->child[x] = newNode;
            }
            temp = temp->child[x];
        }

        temp->isEnd = true;
    }

    void dfs(TrieNode *curNode, string &curString, vector<string> &ans)
    {
        if (curNode == nullptr)
            return;

        if (curNode->isEnd)
            ans.push_back(curString);

        if ((int)ans.size() == 3)
            return;

        for (int i = 0; i < 26; i++)
        {
            if (curNode->child[i])
            {
                curString.push_back('a' + i);
                dfs(curNode->child[i], curString, ans);
                curString.pop_back();

                if ((int)ans.size() == 3)
                    break;
            }
        }
    }

    bool find(string &searchWord)
    {
        TrieNode *curNode = trieRoot;
        for (int i = 0; i < (int)searchWord.length(); i++)
        {
            int x = searchWord[i] - 'a';

            if (curNode->child[x] == nullptr)
                return false;

            curNode = curNode->child[x];
        }
        return true; // or curNode->isEnd
    }

public:
    SearchSuggestionSystem(vector<string> products)
    {
        trieRoot = new TrieNode;

        for (string productName : products)
            insert(productName);
    }

    vector<string> suggestProducts(string searchWord)
    {
        TrieNode *curNode = trieRoot;
        vector<string> ans;

        for (int i = 0; i < (int)searchWord.length(); i++)
        {
            int x = searchWord[i] - 'a';

            if (curNode->child[x] == nullptr)
                return ans;

            curNode = curNode->child[x];
        }

        dfs(curNode, searchWord, ans);

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> products;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        products.push_back(s);
    }

    SearchSuggestionSystem searchSuggestionSystem(products);

    int q;
    cin >> q;

    while (q--)
    {
        string searchWord;
        cin >> searchWord;

        vector<string> ans = searchSuggestionSystem.suggestProducts(searchWord);

        for (string s : ans)
            cout << s << " ";
        cout << "\n";
    }

    return 0;
}