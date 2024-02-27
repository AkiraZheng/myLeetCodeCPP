#pragma once
#include "header.h"
class ImplementTriePrefixTree
{
private:
	static const int MAX_NODES = 26;//һ���ڵ������26���ӽڵ㣨��Ӧ26����ĸ��
	struct TrieNode {
		bool is_str=false;//search��������Ҫ�����ڱ�ʾ�Ըýڵ�Ϊ��β��ǰ׺�ǲ���ǰ�������ĳ�������ַ����Ľ�β
        TrieNode* next[MAX_NODES];
    };
    TrieNode* root = new TrieNode();//��ʼ��һ������root�����ڵ�ַ�Ѿ���new�ˣ�����root->next[i]��ʱ����nullptr��������˵��Ҫ������������delete����new��ֵ
public:
    ImplementTriePrefixTree() {
        /*��208�⣺ʵ��Trie(ǰ׺��)
        * ��һ���ṹ���ʾǰ׺����ÿ���ڵ�:
        *    �ṹ���е�is_str�����Ƿ���insert��һ��str���Ըýڵ���Ϊ��β�ģ�search��������Ҫ��
        *    �ṹ���е�nextָ��������һ����СΪ26�Ľڵ����飬�Ƿ�Ϊnullptr�������Ƿ��Ѿ��д���ýڵ�
        */
    }

    void insert(string word) {
        TrieNode* p = root;//����������
        for (char c : word) {//c-'a'�õ��ַ�c���±꣨c��26����ĸ���ǵ�c-'a'����ĸ��
            int index_c = c - 'a';
            //1. û�ҵ���Ӧ���ӽڵ�
            if (p->next[index_c]==nullptr) {//�ýڵ��¶�Ӧ��������û����
                //�½�����
                TrieNode* node = new TrieNode();
                p->next[index_c] = node;
            }
            //2. �Ѿ��д����Ӧ���ӽڵ㣺�����κβ���

            p = p->next[index_c];
        }
        //�õ��ʽ�������Ӧ��is_str����Ϊtrue
        p->is_str = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for (char c : word) {
            int index_c = c - 'a';
            //1. û�ҵ���Ӧ���ӽڵ�
            if (p->next[index_c] == nullptr) {
                return false;
            }
            //2. �Ѿ��д����Ӧ���ӽڵ㣬��ʼ������һ���ַ���Ӧ�Ľڵ�
            p = p->next[index_c];
        }
        //word�������б��ҵ�
        return p->is_str;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char c : prefix) {
            int index_c = c - 'a';
            //1. û�ҵ���Ӧ���ӽڵ�
            if (p->next[index_c] == nullptr) {
                return false;
            }
            //2. �Ѿ��д����Ӧ���ӽڵ㣬��ʼ������һ���ַ���Ӧ�Ľڵ�
            p = p->next[index_c];
        }
        //word�������б��ҵ�
        return true;
    }
};

