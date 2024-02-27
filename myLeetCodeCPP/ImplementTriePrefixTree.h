#pragma once
#include "header.h"
class ImplementTriePrefixTree
{
private:
	static const int MAX_NODES = 26;//一个节点最多有26个子节点（对应26个字母）
	struct TrieNode {
		bool is_str=false;//search函数的需要，用于表示以该节点为结尾的前缀是不是前面输入的某个完整字符串的结尾
        TrieNode* next[MAX_NODES];
    };
    TrieNode* root = new TrieNode();//初始化一个最顶层的root，由于地址已经被new了，所以root->next[i]此时都是nullptr；按理来说还要在析构函数中delete所有new的值
public:
    ImplementTriePrefixTree() {
        /*第208题：实现Trie(前缀树)
        * 用一个结构体表示前缀树的每个节点:
        *    结构体中的is_str代表是否有insert过一个str是以该节点作为结尾的（search函数的需要）
        *    结构体中的next指针数组是一个大小为26的节点数组，是否为nullptr代表着是否已经有存过该节点
        */
    }

    void insert(string word) {
        TrieNode* p = root;//用于搜索树
        for (char c : word) {//c-'a'得到字符c的下标（c在26个字母中是第c-'a'个字母）
            int index_c = c - 'a';
            //1. 没找到对应的子节点
            if (p->next[index_c]==nullptr) {//该节点下对应的子树还没建立
                //新建子树
                TrieNode* node = new TrieNode();
                p->next[index_c] = node;
            }
            //2. 已经有存过对应的子节点：不做任何操作

            p = p->next[index_c];
        }
        //该单词结束，对应的is_str更新为true
        p->is_str = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for (char c : word) {
            int index_c = c - 'a';
            //1. 没找到对应的子节点
            if (p->next[index_c] == nullptr) {
                return false;
            }
            //2. 已经有存过对应的子节点，开始搜索下一个字符对应的节点
            p = p->next[index_c];
        }
        //word能在树中被找到
        return p->is_str;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char c : prefix) {
            int index_c = c - 'a';
            //1. 没找到对应的子节点
            if (p->next[index_c] == nullptr) {
                return false;
            }
            //2. 已经有存过对应的子节点，开始搜索下一个字符对应的节点
            p = p->next[index_c];
        }
        //word能在树中被找到
        return true;
    }
};

